#include "DefensiveRandomPlayer.h"
#include <cstdlib>

DefensiveRandomPlayer::DefensiveRandomPlayer(Board::Player player):
RandomPlayer(player)
{
}

Board DefensiveRandomPlayer::move(Board board)
{
  Board boardToConsider;
  Board::Player opponent;
  if (mPlayer == Board::PLAYER_X)
  {
    opponent = Board::PLAYER_O;
  }
  else 
  {
    opponent = Board::PLAYER_X;
  }

    
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
    {
      if(board(i,j)==Board::EMPTY)
      { 
        boardToConsider = board.move(i,j,opponent);
        if(boardToConsider.winner()==opponent) //if a move wins for opponent, block it
        {
          return board.move(i,j,mPlayer);;
        }
      }
    }
  return RandomPlayer::move(board); //choose like RandomPlayer
}

