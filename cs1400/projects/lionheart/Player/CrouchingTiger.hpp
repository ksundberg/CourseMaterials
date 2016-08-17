#ifndef LIONHEART_CROUCHING_TIGER
#define LIONHEART_CROUCHING_TIGER
#include "Player.hpp"

namespace lionheart
{
  class CrouchingTiger : public Player
  {
  public:
    Placement placeUnit(UnitType, StartBox const& box, SituationReport report)
    {
      static std::random_device rd;
      static std::mt19937 engine(rd());

      std::uniform_int_distribution<> row(box.minRow, box.maxRow);
      std::uniform_int_distribution<> col(box.minCol, box.maxCol);
      auto r = row(engine);
      auto c = col(engine);

      while (report.things[r][c].type != SituationReport::SPACE)
      {
        r = row(engine);
        c = col(engine);
      }
      return {r, c};
    }
    Action recommendAction(Unit const& u, SituationReport, Plan p)
    {
      if (p.hasAttack()) return p.attackEnemy();
      if (u.getType() == CROWN) {
        if (p.movesToEnemy() > 6) return p.moveToLocation(15, 15);
      }
      if (u.getType() == ARCHER) {
        if (p.movesToEnemy() < 4) return p.attackEnemy();
        return p.moveToAllyCrown();
      }

      if (p.movesToAllyCrown() > 10) {
        return p.moveToAllyCrown();
      }
      return p.moveToEnemyCrown();
    }
    Blazon getBlazon() { return {Color::OR, Color::SABLE, Style::INVERTED_CHEVERON, "Crouching Tiger"}; }
  };
}
#endif
