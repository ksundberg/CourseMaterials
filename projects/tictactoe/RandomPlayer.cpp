#include "RandomPlayer.h"
#include <cstdlib>

RandomPlayer::RandomPlayer(Board::Player player):
Player(player)
{
}

Board RandomPlayer::move(Board board)
{
  Board boards[9];
  int possible = 0;
  
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
    {
      if(board(i,j)==Board::EMPTY)
      { 
        boards[possible] = board.move(i,j,mPlayer);
        if(boards[possible].winner()==mPlayer) //if a move wins, make it
        {
          return boards[possible];
        }
        possible++;
      }
    }
  int choice = rand()%possible;
  return boards[choice]; //choose a random move
}

