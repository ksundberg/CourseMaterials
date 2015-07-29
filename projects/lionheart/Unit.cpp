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
bool lionheart::Unit::move(Map::Location target)
{
  if(!target) return false;
  auto rowDist = target.row - location->row;
  auto colDist = target.col - location->col;
  //check for valid movements
  if((rowDist != 0)&&(colDist != 0)){return false;}
  if (abs(rowDist) > getMoveSpeed()){ return false;}
  if (abs(colDist) > getMoveSpeed()){ return false;}
  //check if facing is correct
  switch (facing)
  {
    case Direction::NORTH:
      if(rowDist >= 0) return false;
      break;
    case Direction::SOUTH:
      if(rowDist <= 0) return false;
      break;
    case Direction::WEST:
      if(colDist >= 0) return false;
      break;
    case Direction::EAST:
      if(colDist <= 0) return false;
      break;
  }
  location.reset(new Map::Location(target));
  return true;
}
void lionheart::Unit::attack(Unit &other)
{
  if(inRange(*(other.location)))
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
  auto targetRow = location->row;
  auto targetCol = location->col;
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

