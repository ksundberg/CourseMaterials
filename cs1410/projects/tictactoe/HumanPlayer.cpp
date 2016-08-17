#include "HumanPlayer.h"
#include <iostream>

using namespace std;

HumanPlayer::HumanPlayer(Board::Player player):
Player(player)
{
}

Board HumanPlayer::move(Board board)
{
  int row, col;
  bool notValid = true;
  board.display();
  while(notValid)
  {
    cout << "Enter your move - row column:";
    cin >> row >> col;
    if(board(row,col)==Board::EMPTY)
      notValid = false;
  }
  return board.move(row,col,mPlayer);
}

