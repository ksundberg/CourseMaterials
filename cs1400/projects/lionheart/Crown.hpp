#ifndef LIONHEART_CROWN_HPP
#define LIONHEART_CROWN_HPP

#include "Unit.hpp"

namespace lionheart
{
  class Crown:public Unit
  {
    public:
      static const int STARTING_HP = 1;
      Crown(int id, Map::Location l, Direction d) : Unit(id, l, d, STARTING_HP) {}
      bool hasArmor() const override{return true;}
      AttackType attackType() const override{return AttackType::AXE;}
      int getMoveSpeed() const override{return 5;}
      UnitType getType() const override{return type;}
      const static UnitType type = CROWN;

  };
}

#endif

