#include "Unit.hpp"
#include <random>
namespace
{
bool roll(lionheart::AttackType attackType)
{
  thread_local std::random_device rd;
  thread_local std::mt19937 engine(rd());
  std::uniform_int_distribution<> die(1, 6);
  auto result = die(engine);
  switch(attackType)
  {
    case lionheart::AttackType::ARROW:
      return result <= 2;
    case lionheart::AttackType::AXE:
      return result <= 3;
  }
  return false;
}
}

void lionheart::Unit::turn(Direction d)
{
  facing = d;
}
void lionheart::Unit::move(int dist)
{
  if(dist <= getMoveSpeed())
  {
    //TODO apply movement (check for intervening units and rocks)
  }
}
void lionheart::Unit::attack(Unit &other)
{
  if(inRange(other.location))
  {
    auto hits = getHits(other.hasArmor());
    other.hp -= hits;
  }
}

int lionheart::Unit::getHits(bool armoredTarget) const
{
  auto hits = 0;
  auto rolls = hp;
  // Units with armor get two attacks per hp
  if (hasArmor())
  {
    rolls *= 2;
  }
  // Roll die for each attack
  for(int i=0;i<rolls;++i)
  {
    if(roll(attackType()))
    {
      ++hits;
    }
  }
  // Unarmored targets with one hp against armored targets can
  // never succeed, so they get a bonus attack if the first hit
  if (armoredTarget && !hasArmor() && (hits == 1) && rolls == 1)
  {
    if(roll(attackType()))
    {
      ++hits;
    }
  }
  // Armored targets need two hits, the integer division is correct
  if(armoredTarget) hits /= 2;
  return hits;
}

bool lionheart::Unit::inRange(Map::Location const &target) const
{
  // Default inRange implementation for melee units
  auto targetRow = location.row;
  auto targetCol = location.col;
  switch (facing)
  {
    case Direction::NORTH:
    --targetRow;
    break;
    case Direction::SOUTH:
    ++targetRow;
    break;
    case Direction::WEST:
    --targetCol;
    break;
    case Direction::EAST:
    ++targetCol;
    break;
  }
  if (target.row != targetRow)
    return false;
  if (target.col != targetCol)
    return false;
  return true;
}

