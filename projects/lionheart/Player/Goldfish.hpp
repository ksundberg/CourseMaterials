#ifndef LIONHEART_GOLDFISH
#define LIONHEART_GOLDFISH
#include "Player.hpp"
#include <random>

namespace lionheart
{
  class Goldfish : public Player
  {
  public:
    Placement placeUnit(UnitType, StartBox const& box, SituationReport report)
    {
      thread_local std::random_device rd;
      thread_local std::mt19937 engine(rd());

    std::uniform_int_distribution<> row(box.minRow, box.maxRow);
    std::uniform_int_distribution<> col(box.minCol, box.maxCol);
    auto r = row(engine);
    auto c = col(engine);

    while (report.things[r][c].type != SituationReport::SPACE)
    {
      r = row(engine);
      c = col(engine);
    }
    return { r, c };
    }
    Action recommendAction(Unit const&, SituationReport) { return Action(); }
    Blazon getBlazon() { return {Color::OR, Color::GULES, Style::BEND, "Goldfish"}; }
  };
}
#endif
