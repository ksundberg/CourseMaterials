#ifndef LIONHEART_SITTING_DUCK
#define LIONHEART_SITTING_DUCK
#include "Player.hpp"

namespace lionheart
{
  class SittingDuck : public Player
  {
  public:
    Placement placeUnit(UnitType, StartBox const& box, SituationReport report)
    {
      for (int r = box.minRow; r < box.maxRow; ++r)
        for (int c = box.minCol; c < box.maxCol; ++c)
          if (report.things[r][c].type == SituationReport::SPACE) return {r, c};
	  return{ 0, 0 };
    }
    Action recommendAction(Unit const&, SituationReport,Plan) { return Action(); }
    Blazon getBlazon() { return {Color::AZURE, Color::OR, Style::BEND, "Sitting Duck"}; }
  };
}
#endif
