#include "Plan.hpp"
#include <limits>
#include <algorithm>

namespace
{
  lionheart::PathVertex getClosest(lionheart::PathVertex start,std::shared_ptr<lionheart::Unit> u,
    std::shared_ptr<const lionheart::Paths> paths)
  {
    lionheart::PathVertex result;
    auto dist = std::numeric_limits<int>::max();
    std::vector<lionheart::Direction> const dirs{lionheart::Direction::NORTH, lionheart::Direction::EAST, lionheart::Direction::SOUTH, lionheart::Direction::WEST};
    for(auto&& dir:dirs)
    {
      lionheart::PathVertex loc({u->getLocation().row,u->getLocation().col},dir);
      auto toLoc = paths->distance(start,loc);
      if(toLoc < dist)
      {
        dist = toLoc;
        result = loc;
      }
    }
    return result;
  }
}

lionheart::Paths::Paths(std::shared_ptr<const Map> const& map, int maxSpeed) : vertex(), nextAction(), pathLength()
{
  std::vector<lionheart::Direction> const dirs{
    lionheart::Direction::NORTH, lionheart::Direction::EAST, lionheart::Direction::SOUTH, lionheart::Direction::WEST};
  //Create all vertexes
  auto vNum = 0;
  for(size_t r=0;r<map->rows();++r)
    for(size_t c=0;c<map->cols();++c)
    {
      if((*map)[map->at(r,c)] == Tile::SPACE)
      {
        for(auto&& d:dirs)
          vertex[{{static_cast<int>(r),static_cast<int>(c)},d}] = vNum++;
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
      pathLength[i].emplace_back(std::numeric_limits<int>::max());
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
  //Apply Floyed-Warshall's algorithm with paths
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
          pathLength[start][stop] = pathLength[start][mid];
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

lionheart::Action lionheart::Plan::attackEnemy()
{
  //return an attack if legal

  //otherwise approach enemy
  return moveToEnemy();
}

lionheart::Action lionheart::Plan::moveToEnemy()
{
  if(paths)
  {
    return paths->next(self,enemy);
  }
  return Action();
}

lionheart::Action lionheart::Plan::moveToEnemyCrown()
{
  if(paths)
  {
    return paths->next(self,enemyCrown);
  }
  return Action();
}

lionheart::Action lionheart::Plan::moveToAllyCrown()
{
  if (paths) 
  {
    return paths->next(self, allyCrown);
  }
  return Action();
}

lionheart::Action lionheart::Plan::moveToLocation(int row,int col)
{
  PathVertex dest({row,col},self.facing);
  if(paths)
  {
    return paths->next(self,dest);
  }
  return Action();
}
