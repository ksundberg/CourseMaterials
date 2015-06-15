#include "Action.hpp"
#include <algorithm>


namespace lionheart
{

  class MoveImpl:public ActionImpl
  {
    public:
      MoveImpl(int d):ActionImpl(),dist(d){}
      void apply(std::shared_ptr<const Map> const& map,
                 Unit& actor,
                 std::vector<std::shared_ptr<Unit>>& allies,
                 std::vector<std::shared_ptr<Unit>>& enemies) override
      {
        if(dist > actor.getMoveSpeed())
        {
          dist = actor.getMoveSpeed();
        }
        auto actLocation = actor.getLocation();
        Placement curLoc{actLocation.row,actLocation.col};
        //verify move is legal (no intervening rocks or units)
        for(auto i=0;i<dist;++i)
        {
          auto nextLoc = getNext(curLoc,actor);
          //check for rocks
          if ((*map)[map->at(nextLoc.row, nextLoc.col)] == lionheart::Tile::ROCK) {
            break;
          }
          auto sameLocation = [&](std::shared_ptr<Unit> const& u)
          {
            return u->getLocation() == map->at(nextLoc.row,nextLoc.col);
          };
          //check for allies
          auto aiter = std::find_if(allies.begin(),allies.end(),sameLocation);
          if (aiter != allies.end()) {
            break;
          }
          //check for enemies
          auto eiter = std::find_if(enemies.begin(),enemies.end(),sameLocation);
          if (eiter != enemies.end()) {
            break;
          }
          //current location okay, iterate to check next location
          curLoc = nextLoc;
        }
        actor.move(map->at(curLoc.row,curLoc.col));
      }
    private:
      Placement getNext(Placement const & old, Unit const & actor)
      {
        auto result = old;
        switch (actor.getFacing())
        {
          case Direction::NORTH:--result.row; break;
          case Direction::SOUTH:++result.row; break;
          case Direction::EAST:++result.col; break;
          case Direction::WEST:--result.col; break;
        }
        return result;
      }
      int dist;
  };
  class TurnImpl:public ActionImpl
  {
    public:
      TurnImpl(Direction d):ActionImpl(),dir(d){}
      void apply(std::shared_ptr<const Map> const& map,
                 Unit& actor,
                 std::vector<std::shared_ptr<Unit>>& allies,
                 std::vector<std::shared_ptr<Unit>>& enemies) override
      {
        actor.turn(dir);
      }

    private:
      Direction dir;
  };
  class AttackImpl:public ActionImpl
  {
    public:
      void apply(std::shared_ptr<const Map> const& map,
                 Unit& actor,
                 std::vector<std::shared_ptr<Unit>>& allies,
                 std::vector<std::shared_ptr<Unit>>& enemies) override
      {}
  };
}

lionheart::Action lionheart::turn(Direction d)
{
  return Action(std::unique_ptr<TurnImpl>(new TurnImpl(d)));
}

lionheart::Action lionheart::move(int distance)
{
  return Action(std::unique_ptr<MoveImpl>(new MoveImpl(distance)));
}

lionheart::Action lionheart::wait()
{
  //Return default constructed action (do nothing)
  return Action();
}

lionheart::Action lionheart::attack()
{
  return Action();
}

