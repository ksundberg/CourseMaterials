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
  };
}

#endif
