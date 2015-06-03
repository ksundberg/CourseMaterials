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
enum class AttackType
{
  ARROW,AXE
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
  void move(int dist);
  void attack(Unit &other);

protected:
  Unit(Map::Location l, Direction d, int hp)
      : location(l)
      , facing(d)
      , hp(hp){}
  int getHp() const
  {
    return hp;
  }

private:
  Map::Location location;
  Direction facing;
  int hp;
  virtual bool hasArmor() const=0;
  int getHits(bool armoredTarget) const;
  virtual AttackType attackType() const=0;
  virtual int getMoveSpeed() const=0;
  virtual bool inRange(Map::Location const &) const;
};
}

#endif
