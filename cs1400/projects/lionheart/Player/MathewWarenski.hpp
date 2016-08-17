#ifndef LIONHEART_MATHEW_WARENSKI
#define LIONHEART_MATHEW_WARENSKI
#include "Player.hpp"
#include <vector>

// Spring 2016 CS 3100 Champion - Mathew Warenski

namespace lionheart
{

class MathewWarenski : public Player
{
public:
  MathewWarenski()
      : enemyWaiting(true)
      , id(0)
  {
  }
  Placement placeUnit(UnitType, StartBox const &box, SituationReport report);
  Action recommendAction(Unit const &, SituationReport, Plan);
  Blazon getBlazon();

private:
  bool enemyWaiting;
  int id;
  int kingX;
  int kingY;
  const int ENEMY_EAST_WALL = 28;
  const int ENEMY_WEST_WALL = 21;
  const int NORTH_WALL = 10;
  const int SOUTH_WALL = 19;
  const int ALLY_EAST_WALL = 1;
  const int ALLY_WEST_WALL = 8;

  lionheart::Direction setdefdir(lionheart::Unit const &u,
                                 lionheart::SituationReport);
  // flip to east facing if west, will also reverse if already flipped.
  int flipIfWest(int x, int w);
  const int MAX_CHICKEN = 1; // maximum turns to wait before switching strategy

  // true if placed on left side of board.
  bool facingEast;

  // SituationReport currentReport;
  // Unit* currentUnit;
  // Plan currentPlan;
  struct Location
  {
    Location(int x, int y)
        : x(x)
        , y(y)
    {
    }
    int x;
    int y;
  };

  bool enemyInInbetween(SituationReport report);

  // direct units to appropriate locations
  Location getDefensivePosition(Unit const &u, SituationReport report, Plan p);
  Location
  getSmartChargePosition(Unit const &u, SituationReport report, Plan p);

  // hide king in center behind wall with infantry sheilds. hide kights, only
  // attack if from behind
  Location hideAndStrike(Unit const &u, SituationReport report, Plan p);

  // assign movements or attacks accordingly
  lionheart::Action
  playSmartCharge(Unit const &u, SituationReport report, Plan p);
  lionheart::Action
  playInFortDefend(Unit const &u, SituationReport report, Plan p);

  //  lionheart::Unit* findEnemyKing(SituationReport report);

  // basic actions
  // wait - stay put and attack if possible
  lionheart::Action wait(Plan p);
  // wait - avoid enemy range

  lionheart::Action attack();

  bool isDefender(int id);
};
}

#endif
