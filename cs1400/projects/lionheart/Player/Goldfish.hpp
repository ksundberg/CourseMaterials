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
    return { r, c };
    }
    Action recommendAction(Unit const&, SituationReport,Plan) {
       static std::random_device rd;
      static std::mt19937 engine(rd());
      std::uniform_int_distribution<> act(0,4);
      switch(act(engine))
      {
        case 0:return turn(Direction::NORTH);
        case 1:return turn(Direction::EAST);
        case 2:return turn(Direction::SOUTH);
        case 3:return turn(Direction::WEST);
        case 4:return move(5);
      }
	  return wait();
    }
    Blazon getBlazon() { return {Color::OR, Color::GULES, Style::BEND, "Goldfish"}; }
  };
}
#endif
