#ifndef LIONHEART_BRANDON_SMITH
#define LIONHEART_BRANDON_SMITH
#include "Player.hpp"

namespace lionheart
{
  class BrandonSmith : public Player
  {
  public:
	Placement placeUnit(UnitType, StartBox const& box, SituationReport report);
    Action recommendAction(Unit const &, SituationReport, Plan);
    Blazon getBlazon();
  };
  class Enemy
  {
  public:
	  Enemy(int r, int c, lionheart::UnitType t)
		  : row(r)
		  , col(c)
		  , type(t){};
  private:
	  int row;
	  int col;
	  lionheart::UnitType type;
  };
}

#endif
