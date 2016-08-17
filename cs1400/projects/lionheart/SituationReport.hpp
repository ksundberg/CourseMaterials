#ifndef LIONHEART_SITUATION_REPORT_HPP
#define LIONHEART_SITUATION_REPORT_HPP
#include "Unit.hpp"
#include "Action.hpp"
#include <vector>

namespace lionheart
{

  struct SituationReport
  {
    enum ThingType
    {
      SPACE,
      ROCK,
      ALLY,
      ENEMY
    };
    struct Thing
    {
      Thing()
          : type(ROCK)
          , unit(NONE)
          , direction(Direction::NORTH)
          , hp(0)
      {
      }
      Thing(std::shared_ptr<Unit> u, ThingType isAlly)
          : type(isAlly)
          , unit(u->getType())
          , direction(u->getFacing())
          , hp(u->getHp())
      {
      }
      ThingType type;
      UnitType unit;
      Direction direction;
      int hp;
    };
    std::vector<std::vector<Thing>> things;
    int turns;
    int getHp(ThingType type) const
    {
      int result = 0;
      for (auto &&row : things)
        for (auto &&t : row)
        {
          if (t.type == type)
          {
            result += t.hp;
          }
        }
      return result;
    }
  };
}

#endif
