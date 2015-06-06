#ifndef LIONHEART_KNIGHT_HPP
#define LIONHEART_KNIGHT_HPP

#include "Unit.hpp"

namespace lionheart
{
  class Knight:public Unit
  {
    public:
      const int STARTING_HP = 2;
      Knight(Map::Location l,Direction d):Unit(l,d,STARTING_HP){}
      bool hasArmor() const override{return true;}
      AttackType attackType() const override{return AttackType::AXE;}
      int getMoveSpeed() const override{return 5;}
      UnitType getType() const{return type;}
      const static UnitType type = KNIGHT;
  };
}

#endif

