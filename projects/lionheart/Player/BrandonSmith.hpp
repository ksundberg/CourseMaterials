#ifndef LIONHEART_BRANDON_SMITH
#define LIONHEART_BRANDON_SMITH
#include "Player.hpp"

// Summer 2015 CS 1400 Champion - Brandon Smith

namespace lionheart
{
  class BrandonSmith : public Player
  {
  public:
    Placement placeUnit(UnitType, StartBox const& box, SituationReport report);
    Action recommendAction(Unit const&, SituationReport, Plan);
    Blazon getBlazon();
  };
}

#endif
