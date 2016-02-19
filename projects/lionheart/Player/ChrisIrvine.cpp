#include "ChrisIrvine.hpp"
#include <random>

lionheart::Placement lionheart::ChrisIrvine::placeUnit(UnitType,
                                                       StartBox const& box,
                                                       SituationReport report)
{
  for (int r = box.minRow; r < box.maxRow; ++r)
    for (int c = box.minCol; c < box.maxCol; ++c)
      if (report.things[r][c].type == SituationReport::SPACE) return {r, c};
  return {0, 0};
}

lionheart::Action lionheart::ChrisIrvine::recommendAction(Unit const& u,
                                                          SituationReport,
                                                          Plan p)
{
  if (u.getType() == CROWN)
  {
    if (p.movesToEnemy() < 2)
    {
      static std::random_device rd;
      static std::mt19937 engine(rd());
      return move(5);
    }
    return wait();
  }
  if (u.getType() == KNIGHT)
  {
    if (p.hasAttack())
    {
      return p.attackEnemy();
    }
    return p.moveToEnemyCrown();
  }
  return p.attackEnemy();

  if (u.getType() == ARCHER)
  {
    {
      if (p.hasAttack())
      {
        return p.attackEnemy();
      }
      return p.moveToAllyCrown();
    }
    return p.attackEnemy();
  }
  if (u.getType() == INFANTRY)
  {
    if (p.hasAttack())
    {
      return p.attackEnemy();
    }
    return p.moveToEnemyCrown();
  }
  return p.attackEnemy();
}
lionheart::Blazon lionheart::ChrisIrvine::getBlazon()
{
  return {Color::SABLE, Color::AZURE, Style::CROSS, "Chris Irvine"};
}
