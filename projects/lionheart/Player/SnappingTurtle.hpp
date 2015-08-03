#ifndef LIONHEART_SNAPPING_TURTLE
#define LIONHEART_SNAPPING_TURTLE
#include "Player.hpp"

namespace lionheart
{
  class SnappingTurtle : public Player
  {
  public:
    SnappingTurtle()
    {
    }
    Placement placeUnit(UnitType type, StartBox const& box, SituationReport report)
    {
      auto useMin = (box.minCol < static_cast<int>((report.things[0].size() / 2)));
      if(type == CROWN)
      {
        if(useMin)
          crown = {(box.minRow + box.maxRow)/2,box.minCol};
        else
          crown = {(box.minRow + box.maxRow)/2,box.maxCol};
        return crown;
      }
      auto minR = box.minRow;
      auto maxR = box.maxRow;
      auto minC = box.minCol;
      auto maxC = box.maxCol;

      if(type == KNIGHT)
      {
        minR = crown.row - 3;
        maxR = crown.row + 3;
        if (useMin) {
          maxC = crown.col + 4;
          minC = crown.col + 4;
        }
        else
        {
          maxC = crown.col - 4;
          minC = crown.col - 4;
        }
      }
      if(type == INFANTRY)
      {
        minR = crown.row - 3;
        maxR = crown.row + 3;
        if (useMin) {
          maxC = crown.col + 3;
          minC = crown.col;
        }
        else
        {
          maxC = crown.col;
          minC = crown.col - 3;
        }
      }
      if(type == ARCHER)
      {
        minR = crown.row - 1;
        maxR = crown.row + 1;
        if(useMin)
        {
          maxC = crown.col + 2;
          minC = crown.col;
        }
        else
        {
          maxC = crown.col;
          minC = crown.col-2;
        }

      }

      for (int r = minR; r <= maxR; ++r)
        for (int c = minC; c <= maxC; ++c)
          if (report.things[r][c].type == SituationReport::SPACE) return {r, c};
      return {maxR,maxC};
    }
    Action recommendAction(Unit const& u, SituationReport,Plan p) {
     if(u.getType() == KNIGHT)
     {
       return p.attackEnemy();
     }
     if(p.hasAttack())
     {
       return p.attackEnemy();
     }
     return wait();
    }
    Blazon getBlazon() { return {Color::VERT, Color::ARGENT, Style::BEND, "Snapping Turtle"}; }
  private:
    Placement crown;
  };
}
#endif
