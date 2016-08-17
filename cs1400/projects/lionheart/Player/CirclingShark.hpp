#ifndef LIONHEART_CIRCLING_SHARK
#define LIONHEART_CIRCLING_SHARK
#include "Player.hpp"
#include <map>

namespace lionheart
{
  class CirclingShark : public Player
  {
  public:
    Placement placeUnit(UnitType, StartBox const& box, SituationReport report)
    {
      westFirst = (box.minCol < static_cast<int>(report.things[0].size() / 2));
      if(!westFirst)
      {
      for (int r = box.minRow; r <= box.maxRow; ++r)
        for (int c = box.minCol; c <= box.maxCol; ++c)
          if (report.things[r][c].type == SituationReport::SPACE) return {r, c};
      }
      else
      {
        for (int r = box.maxRow; r >= box.minRow; --r)
          for (int c = box.maxCol; c >= box.minCol; --c)
            if (report.things[r][c].type == SituationReport::SPACE) return {r, c};
      }
	  return{ 0, 0 };
    }
    Action recommendAction(Unit const& u, SituationReport, Plan p)
    {
      if (p.movesToEnemy() < 3) return p.attackEnemy();
      auto waypoint = getPoint(dest[u.getId()]);
      if (p.movesTo(waypoint.row, waypoint.col) < 2) {
        dest[u.getId()] = (dest[u.getId()] + 1)%4;
      }
      return p.moveToLocation(waypoint.row, waypoint.col);
    }
    Blazon getBlazon() { return {Color::ARGENT, Color::AZURE, Style::CHIEF, "Circling Shark"}; }
  private:
    Placement getPoint(int point)
    {
      if(!westFirst)
      {
        point +=2;
        point %=4;
      }
      switch(point)
      {
        case 0: return {3,3};
        case 1: return {3,26};
        case 2: return {26,26};
        case 3: return {26,3};
      }
      return {15,15};
    }
    std::map<int,int> dest;
    bool westFirst;
  };
}
#endif
