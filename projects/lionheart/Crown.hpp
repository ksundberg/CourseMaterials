#ifndef LIONHEART_CROWN_HPP
#define LIONHEART_CROWN_HPP

#include "Unit.hpp"

namespace lionheart
{
  class Crown:public Unit
  {
    public:
      static const int STARTING_HP = 1;
      Crown(Map::Location l,Direction d):Unit(l,d,STARTING_HP){}
      bool hasArmor() const override{return true;}
      AttackType attackType() const override{return AttackType::AXE;}
      int getMoveSpeed() const override{return 5;}
      UnitType getType() const{return type;}
      const static UnitType type = CROWN;

  };
}

#endif

