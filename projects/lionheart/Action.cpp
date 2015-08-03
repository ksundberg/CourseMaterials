#include "Action.hpp"
#include <algorithm>

namespace lionheart
{

  class MoveImpl:public ActionImpl
  {
    public:
      MoveImpl(int d):ActionImpl(),dist(d){}
      std::unique_ptr<ActionImpl> clone() const
      {
        return std::unique_ptr<ActionImpl>(new MoveImpl(dist));
      }
      bool apply(std::shared_ptr<const Map> const& map,
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
        return actor.move(map->at(curLoc.row,curLoc.col));
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
      std::unique_ptr<ActionImpl> clone() const
      {
        return std::unique_ptr<ActionImpl>(new TurnImpl(dir));
      }
      bool apply(std::shared_ptr<const Map> const&,
                 Unit& actor,
                 std::vector<std::shared_ptr<Unit>>&,
                 std::vector<std::shared_ptr<Unit>>&) override
      {
        actor.turn(dir);
        return true;
      }

    private:
      Direction dir;
  };
  class AttackImpl:public ActionImpl
  {
    public:
      AttackImpl(Placement p):ActionImpl(),target(p){}
      std::unique_ptr<ActionImpl> clone() const
      {
        return std::unique_ptr<ActionImpl>(new AttackImpl(target));
      }
      bool apply(std::shared_ptr<const Map> const&,
                 Unit& actor,
                 std::vector<std::shared_ptr<Unit>>&,
                 std::vector<std::shared_ptr<Unit>>& enemies) override
      {
        // find legal target
        auto eIter = std::find_if(enemies.begin(),
                               enemies.end(),
                               [&](std::shared_ptr<Unit> const& u)
                                 ->bool
                               {
          auto loc = u->getLocation();
          if ((loc.row == target.row) && (loc.col == target.col)) return true;
          return false;
        });
        if(eIter != enemies.end())
        {
          auto& enemy = *eIter;
          if(actor.inRange(enemy->getLocation()))
          {
            actor.attack(*enemy);
            return true;
          }
        }
        return false;
      }

    private:
      Placement target;
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

lionheart::Action lionheart::attack(Placement p)
{
  return Action(std::unique_ptr<AttackImpl>(new AttackImpl(p)));
}

