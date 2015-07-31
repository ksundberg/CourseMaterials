#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Board.h"

class Player
{
public:
  Player(Board::Player);
  virtual Board move(Board board)=0;
protected:
  Board::Player mPlayer;
};

#endif
