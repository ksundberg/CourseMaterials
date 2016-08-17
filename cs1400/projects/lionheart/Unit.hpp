#ifndef LIONHEART_UNIT_HPP
#define LIONHEART_UNIT_HPP

#include "Map.hpp"

namespace lionheart
{
enum class Direction
{
  NORTH,
  EAST,
  SOUTH,
  WEST
};
std::ostream & serialize(std::ostream& os, const Direction& placement);
std::istream & deserialize(std::istream& is, Direction& placement);

enum class AttackType
{
  ARROW,AXE
};
enum UnitType
{
  CROWN,
  KNIGHT,
  ARCHER,
  INFANTRY,
  NONE
};
class Unit
{
public:
  virtual ~Unit(){}
  bool isAlive() const
  {
    return hp > 0;
  }
  void turn(Direction);
  bool move(Map::Location);
  void attack(Unit &other);
  int getHp() const
  {
    return hp;
  }
  Map::Location getLocation() const
  {
    return *location;
  }
  Direction getFacing() const
  {
    return facing;
  }
virtual UnitType getType() const=0;
virtual int getId() const{return id;}

virtual bool inRange(Map::Location const &) const;
virtual int getMoveSpeed() const = 0;


protected:
  Unit(int id, Map::Location l, Direction d, int hp)
      : location(new Map::Location(l))
      , facing(d)
      , hp(hp)
      , id(id){}

private:
  std::unique_ptr<Map::Location> location;
  Direction facing;
  int hp;
  const int id;
  virtual bool hasArmor() const=0;
  int getHits(bool armoredTarget) const;
  virtual AttackType attackType() const=0;
};
}

#endif
