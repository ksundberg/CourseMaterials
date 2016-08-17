#ifndef LIONHEART_ARCHER_HPP
#define LIONHEART_ARCHER_HPP

#include "Unit.hpp"

namespace lionheart
{
  class Archer:public Unit
  {
    public:
      static const int STARTING_HP = 4;
      Archer(int id, Map::Location l, Direction d) : Unit(id, l, d, STARTING_HP) {}
      bool hasArmor() const override{return false;}
      AttackType attackType() const override{return AttackType::ARROW;}
      int getMoveSpeed() const override{return 1;}
      virtual bool inRange(Map::Location const &) const override;
      UnitType getType() const override {return type;}
      const static UnitType type = ARCHER;
  };
}

#endif

