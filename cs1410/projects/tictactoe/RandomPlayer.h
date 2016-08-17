#ifndef _RANDOM_PLAYER_
#define _RANDOM_PLAYER_

#include "Player.h"

class RandomPlayer:public Player
{
public:
  RandomPlayer(Board::Player);
  virtual Board move(Board board);
};

#endif
