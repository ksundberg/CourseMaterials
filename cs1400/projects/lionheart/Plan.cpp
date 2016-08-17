#include "Plan.hpp"
#include <limits>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <string>

namespace
{
  lionheart::PathVertex getClosest(lionheart::PathVertex start,std::shared_ptr<lionheart::Unit> u,
    std::shared_ptr<const lionheart::Paths> paths)
  {
    lionheart::PathVertex result;
    auto dist = std::numeric_limits<int>::max();
    auto l1Dist = std::numeric_limits<int>::max();
    std::vector<lionheart::Direction> const dirs{lionheart::Direction::NORTH, lionheart::Direction::EAST, lionheart::Direction::SOUTH, lionheart::Direction::WEST};
    for(auto&& dir:dirs)
    {
      lionheart::PathVertex loc({u->getLocation().row,u->getLocation().col},dir);
      auto toLoc = paths->distance(start,loc);
      auto toLocL1 = abs(start.location.row - loc.location.row) + abs(start.location.col - loc.location.col);
      if(toLoc == dist)
      {
        //break ties with L1-norm
        if(toLocL1 < l1Dist)
        {
          dist = toLoc;
          l1Dist = toLocL1;
          result = loc;
        }
      }
      if(toLoc < dist)
      {
        dist = toLoc;
        l1Dist = toLocL1;
        result = loc;
      }
    }
    return result;
  }
}

std::ostream& lionheart::serialize(std::ostream& os, const PathVertex& pathVertex){
  serialize(os, pathVertex.location);
  os << " ";
  serialize(os, pathVertex.facing);
  return os;
}
std::istream& lionheart::deserialize(std::istream& is, PathVertex& pathVertex){
  deserialize(is, pathVertex.location);
  deserialize(is, pathVertex.facing);
  return is;
}

lionheart::Paths::Paths(std::shared_ptr<const Map> const& map, int maxSpeed) : vertex(), nextAction(), pathLength()
{
  auto pathDataFilename = map->getName() + "." + std::to_string(maxSpeed) + ".path";

  //Check for cached data and load
  std::ifstream pathDataFile(pathDataFilename);
  if (pathDataFile.is_open()) {
    //load the data
    std::cout << "Reading path data from " << pathDataFilename << std::endl;

    //vertex
    int numVertexes;
    pathDataFile >> numVertexes;
    for(int i = 0; i < numVertexes; i++){
      PathVertex pathVertex;
      deserialize(pathDataFile, pathVertex);
      int num;
      pathDataFile >> num;
      vertex[pathVertex] = num;
    }

    //nextAction
    int numActionLists;
    pathDataFile >> numActionLists;
    for(int i = 0; i < numActionLists; i++){
      nextAction.emplace_back();
      int length;
      pathDataFile >> length;
      for(int j = 0; j < length; j++){
        Action action;
        deserialize(pathDataFile, action);
        nextAction[i].push_back(action);
      }
    }

    //pathLength
    int numPathLengthLists;
    pathDataFile >> numPathLengthLists;
    for(int i = 0; i < numPathLengthLists; i++){
      pathLength.emplace_back();
      int length;
      pathDataFile >> length;
      for(int j = 0; j < length; j++){
        int dist;
        pathDataFile >> dist;
        pathLength[i].push_back(dist);
      }
    }

    pathDataFile.close();
  } else {
    calculate(map, maxSpeed);

    //Save cached data

    std::cout << "Writing path data to " << pathDataFilename << std::endl;
    std::ofstream outFile(pathDataFilename);

    //vertex
    outFile << vertex.size() << std::endl;
    for(auto entry : vertex){
      serialize(outFile, entry.first);
      outFile << " " << entry.second << std::endl;
    }

    //nextAction
    outFile << nextAction.size() << std::endl;
    for(auto list : nextAction){
      outFile << list.size() << " ";
      for(auto action : list){
        serialize(outFile, action) << " ";
      }
      outFile << std::endl;
    }

    //pathLength
    outFile << pathLength.size() << std::endl;
    for(auto list : pathLength){
      outFile << list.size() << " ";
      for(auto length : list){
        outFile << length << " ";
      }
      outFile << std::endl;
    }

    outFile.close();
  }
}


void lionheart::Paths::calculate(std::shared_ptr<const Map> const &map, int maxSpeed){
  //calculate the data
  std::vector<lionheart::Direction> const dirs{
      lionheart::Direction::NORTH, lionheart::Direction::EAST, lionheart::Direction::SOUTH, lionheart::Direction::WEST};
  //Create all vertexes
  auto vNum = 0;
  for (int r = 0; r < static_cast<int>(map->rows()); ++r)
    for (int c = 0; c < static_cast<int>(map->cols()); ++c)
    {
      if((*map)[map->at(r,c)] == Tile::SPACE)
      {
        for(auto&& d:dirs)
        {
          vertex[{{r, c}, d}] = vNum;
          ++vNum;
        }
      }
    }
  //create adjacency maps
  for(int i=0;i<vNum;++i)
  {
    nextAction.emplace_back();
    pathLength.emplace_back();
    for(int j=0;j<vNum;++j)
    {
      nextAction[i].emplace_back();
      if (j == i)
      {
        pathLength[i].emplace_back(0);
      }
      else
      {
        pathLength[i].emplace_back(vNum*2);
      }
    }
  }

  for(auto&& v:vertex)
  {
    //Add turn based adjacencies
    for(auto&& d:dirs)
    {
      auto vIdx = vertex[PathVertex(v.first.location,d)];
      if(vIdx != v.second)
      {
        nextAction[v.second][vIdx] = turn(d);
        pathLength[v.second][vIdx] = 1;
      }
    }
    //Add move based adjacencies
    for(auto moveDist = 1;moveDist<=maxSpeed;++moveDist)
    {
      //verify move is valid
      PathVertex dest = v.first;
      switch(dest.facing)
      {
        case Direction::NORTH: dest.location.row-=moveDist;break;
        case Direction::SOUTH: dest.location.row+=moveDist;break;
        case Direction::WEST: dest.location.col-=moveDist;break;
        case Direction::EAST: dest.location.col+=moveDist;break;
      }
      auto destIter = vertex.find(dest);
      if(destIter == vertex.end())
      {
        //there are no more legal moves in this direction
        break;
      }
      else
      {
        nextAction[v.second][destIter->second] = move(moveDist);
        pathLength[v.second][destIter->second] = 1;
      }
    }
  }
  //Apply Floyd-Warshall algorithm with paths
  for (int mid = 0; mid < vNum; ++mid)
  {
    for (int start = 0; start < vNum; ++start)
      for (int stop = 0; stop < vNum; ++stop)
      {
        auto direct = pathLength[start][stop];
        auto throughMid = pathLength[start][mid] + pathLength[mid][stop];
        if(throughMid < direct)
        {
          nextAction[start][stop] = nextAction[start][mid];
          pathLength[start][stop] = throughMid;
        }
      }
  }
}

lionheart::Plan::Plan(Unit const& s,
                      std::vector<std::shared_ptr<lionheart::Unit>> const& allies,
                      std::vector<std::shared_ptr<lionheart::Unit>> const& enemies,
                      std::shared_ptr<const Paths> p)
  : paths(p)
  , self({s.getLocation().row, s.getLocation().col}, s.getFacing())
  , enemy()
  , enemyCrown()
  , allyCrown()
  , inRange(false)
{
  //find closest enemy and if that enemy is in range
  auto dist = std::numeric_limits<int>::max();
  for (auto&& e : enemies)
  {
    auto loc = getClosest(self, e, paths);
    auto toLoc = paths->distance(self, loc);
    if (toLoc < dist) {
      dist = toLoc;
      enemy = loc;
      inRange = s.inRange(e->getLocation());
    }
  }
  auto findCrown = [](std::shared_ptr<lionheart::Unit> u)
  {
    return u->getType() == CROWN;
  };
  //find enemy crown
  auto eCrownIter = std::find_if(enemies.begin(),enemies.end(),findCrown);
  if(eCrownIter!=enemies.end())
  {
    enemyCrown = getClosest(self,*eCrownIter,paths);
  }
  //find ally crown
  auto aCrownIter = std::find_if(allies.begin(), allies.end(), findCrown);
  if(aCrownIter!=allies.end())
  {
    allyCrown = getClosest(self,*aCrownIter,paths);
  }
}

lionheart::Action lionheart::Plan::attackEnemy() const
{
  //return an attack if legal
  if(inRange)
  {
    return attack(enemy.location);
  }

  //otherwise approach enemy
  return moveToEnemy();
}

lionheart::Action lionheart::Plan::moveToEnemy() const
{
  if(paths)
  {
    return paths->next(self,enemy);
  }
  return Action();
}

lionheart::Action lionheart::Plan::moveToEnemyCrown() const
{
  if(paths)
  {
    return paths->next(self,enemyCrown);
  }
  return Action();
}

lionheart::Action lionheart::Plan::moveToAllyCrown() const
{
  if (paths) 
  {
    return paths->next(self, allyCrown);
  }
  return Action();
}

lionheart::Action lionheart::Plan::moveToLocation(int row,int col) const
{
  PathVertex dest({row,col},self.facing);
  if(paths)
  {
    return paths->next(self,dest);
  }
  return Action();
}

int lionheart::Plan::movesTo(int row,int col) const
{
  PathVertex dest({row,col},self.facing);
  if(paths)
  {
    return paths->distance(self,dest);
  }
  return std::numeric_limits<int>::max();
}

int lionheart::Plan::movesToEnemy() const
{
  if(paths)
  {
    return paths->distance(self,enemy);
  }
  return std::numeric_limits<int>::max();
}

int lionheart::Plan::movesToEnemyCrown() const
{
  if(paths)
  {
    return paths->distance(self,enemyCrown);
  }
  return std::numeric_limits<int>::max();
}

int lionheart::Plan::movesToAllyCrown() const
{
  if(paths)
  {
    return paths->distance(self,allyCrown);
  }
  return std::numeric_limits<int>::max();
}
