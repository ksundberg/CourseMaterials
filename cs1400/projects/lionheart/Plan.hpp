#ifndef LIONHEART_PLAN_HPP
#define LIONHEART_PLAN_HPP

#include "Map.hpp"
#include "Action.hpp"
namespace lionheart
{
  struct PathVertex
      {
        PathVertex():location(),facing(){}
        PathVertex(Placement p,Direction d):location(p),facing(d){}
        Placement location;
        Direction facing;
      };
  std::ostream& serialize(std::ostream& os, const PathVertex& pathVertex);
  std::istream& deserialize(std::istream& is, PathVertex& pathVertex);

  inline bool operator==(PathVertex const & a,PathVertex const & b)
  {
    return (a.location.row == b.location.row) && (a.location.col == b.location.col) && (a.facing == b.facing);
  }

  inline bool operator!=(PathVertex const & a,PathVertex const & b)
  {
    return !(a==b);
  }
  inline bool operator<(PathVertex const & a,PathVertex const & b)
  {
    if(a.location.row < b.location.row) return true;
    if(a.location.row > b.location.row) return false;
    if(a.location.col < b.location.col) return true;
    if(a.location.col > b.location.col) return false;
    return a.facing < b.facing;
  }

  class Paths
  {
    public:
      Paths(std::shared_ptr<const Map> const& map,int maxSpeed);
      Action next(PathVertex start, PathVertex stop) const { return access(nextAction, start, stop, Action()); }
      int distance(PathVertex start, PathVertex stop) const { return access(pathLength, start, stop, static_cast<int>(vertex.size())); }

    private:
      template <typename T,typename U>
      U access(std::vector<std::vector<T>> const& v, PathVertex start, PathVertex stop,U defaultValue) const
      {
        auto startIter = vertex.find(start);
        if (startIter == vertex.end()) return defaultValue;
        auto stopIter = vertex.find(stop);
        if (stopIter == vertex.end()) return defaultValue;
        auto startVIter = v.begin() + startIter->second;
        if (startVIter == v.end()) return defaultValue;
        auto valueIter = startVIter->begin() + stopIter->second;
        if (valueIter == startVIter->end()) return defaultValue;
        return *valueIter;
      }

      std::map<PathVertex,int> vertex;
      std::vector<std::vector<Action>> nextAction;
      std::vector<std::vector<int>> pathLength;

    void calculate(const std::shared_ptr<const Map> &map, int maxSpeed);
  };
  class Plan
  {
  public:
    Plan(Unit const& self,
         std::vector<std::shared_ptr<lionheart::Unit>> const& allies,
         std::vector<std::shared_ptr<lionheart::Unit>> const& enemies,
         std::shared_ptr<const Paths> paths);
    Action attackEnemy() const;
    Action moveToEnemy() const;
    Action moveToEnemyCrown() const;
    Action moveToAllyCrown() const;
    Action moveToLocation(int row,int col) const;
    int movesTo(int row,int col) const;
    int movesToEnemy() const;
    int movesToEnemyCrown() const;
    int movesToAllyCrown() const;
    bool hasAttack() const {return inRange;}
  private:
    std::shared_ptr<const Paths> paths;
    PathVertex self;
    PathVertex enemy;
    PathVertex enemyCrown;
    PathVertex allyCrown;
    bool inRange;
  };
}
#endif
