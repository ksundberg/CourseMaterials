#ifndef _DEFENSIVE_RANDOM_PLAYER_
#define _DEFENSIVE_RANDOM_PLAYER_

#include "RandomPlayer.h"

class DefensiveRandomPlayer:public RandomPlayer
{
public:
  DefensiveRandomPlayer(Board::Player);
  virtual Board move(Board board);

};

#endif
