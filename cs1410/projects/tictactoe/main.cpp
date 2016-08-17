#include <iostream>

#include "Board.h"
#include "HumanPlayer.h"
#include "RandomPlayer.h"
#include "DefensiveRandomPlayer.h"
#include "PerfectPlayer.h"

using namespace std;

Player* getPlayer(Board::Player player)
{
  char choice;
  cout << "Will player ";
  
  if(player == Board::PLAYER_X)
  {
    cout << "X";
  }
  else 
  {
    cout << "O";
  }

  cout << " be:" << endl;
  cout << "\t(H)uman" << endl;
  cout << "\t(R)andom" << endl;
  cout << "\t(D)efensive" << endl;
  cout << "\t(P)erfect" << endl;
  
  cin >> choice;
  
  switch (choice) {
    case 'H':
    case 'h':
      return new HumanPlayer(player);
    case 'R':
    case 'r':
      return new RandomPlayer(player);
    case 'D':
    case 'd':
      return new DefensiveRandomPlayer(player);
    default:
      return new PerfectPlayer(player);
  }
}

int main()
{
  Board board;
  Player* players[2];
  
  players[0] = getPlayer(Board::PLAYER_X);
  players[1] = getPlayer(Board::PLAYER_O);
  
  int current_player = 0;
  
  while(board.movesRemain())
  {
    board = players[current_player]->move(board);
    
    current_player++;
    current_player%=2;
  }

  board.display();
  switch(board.winner())
  {
    case Board::PLAYER_X:
      cout << "X's Win!" << endl;
      break;
      
    case Board::PLAYER_O:
      cout << "O's Win!" << endl;
      break;
      
    case Board::EMPTY:
      cout << "Cat's Game" << endl;
      break;
  }
  
  delete players[0];
  delete players[1];
}
