#ifndef LIONHEART_CHRIS_IRVINE
#define LIONHEART_CHRIS_IRVINE
#include "Player.hpp"

// Summer 2015 CS 1400 Champion - Chris Irvine

namespace lionheart
{
  class ChrisIrvine : public Player
  {
  public:
    Placement placeUnit(UnitType, StartBox const& box, SituationReport report);
    Action recommendAction(Unit const&, SituationReport, Plan);
    Blazon getBlazon();
  };
}
#endif
