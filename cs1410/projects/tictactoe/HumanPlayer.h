#ifndef _HUMAN_PLAYER_
#define _HUMAN_PLAYER_

#include "Player.h"

class HumanPlayer:public Player
{
public:
  HumanPlayer(Board::Player);
  virtual Board move(Board board);
};

#endif
