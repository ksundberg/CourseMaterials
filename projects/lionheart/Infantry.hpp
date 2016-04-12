#ifndef LIONHEART_INFANTRY_HPP
#define LIONHEART_INFANTRY_HPP

#include "Unit.hpp"

namespace lionheart
{
  class Infantry:public Unit
  {
    public:
      static const int STARTING_HP = 4;
      Infantry(int id, Map::Location l, Direction d) : Unit(id, l, d, STARTING_HP) {}
      bool hasArmor() const override{return false;}
      AttackType attackType() const override{return AttackType::AXE;}
      int getMoveSpeed() const override{return 1;}
      UnitType getType() const override{return type;}
      const static UnitType type = INFANTRY;
  };
}

#endif

