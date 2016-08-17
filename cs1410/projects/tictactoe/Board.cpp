#include "Board.h"
#include <cstdio>

Board::Board()
{
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      board[i][j] = EMPTY;
}

void Board::display()
{
  printf("\n    0   1   2  \n");
  printf("   ___________\n");
  printf("  |   |   |   |\n");
  printf("0 | %c | %c | %c |\n",board[0][0],board[0][1],board[0][2]);
  printf("  |   |   |   |\n");
  printf("  |---|---|---|\n");
  printf("  |   |   |   |\n");
  printf("1 | %c | %c | %c |\n",board[1][0],board[1][1],board[1][2]);
  printf("  |   |   |   |\n");
  printf("  |---|---|---|\n");
  printf("  |   |   |   |\n");
  printf("2 | %c | %c | %c |\n",board[2][0],board[2][1],board[2][2]);
  printf("  |___|___|___|\n\n");
             
}

Board Board::move(int row,int column,Player player)
{
  Board next_move(*this);
  
  if(row < 0) return next_move;
  if(row > 2) return next_move;
  
  
  if(column < 0) return next_move;
  if(column > 2) return next_move;
  
  if(board[row][column] != EMPTY) return next_move;
  
  next_move.board[row][column] = player;
  return next_move;
}

Board::Player Board::operator()(int row,int column)
{
  return board[row][column];
}

Board::Player Board::winner()
{
  //check rows
  for(int i=0;i<3;i++)
      if(board[i][0]!=EMPTY)
        if((board[i][0] == board[i][1])&&(board[i][1]==board[i][2]))
          return board[i][0];
  
  //check columns
  for(int i=0;i<3;i++)
    if(board[0][i]!=EMPTY)
      if((board[0][i] == board[1][i])&&(board[1][i]==board[2][i]))
        return board[0][i];
  //check diagonals
  if(board[0][0]!= EMPTY)
    if((board[0][0] == board[1][1])&&(board[1][1]==board[2][2]))
      return board[0][0];
  
  if(board[0][2]!= EMPTY)
    if((board[0][2] == board[1][1])&&(board[1][1]==board[2][0]))
      return board[0][2];
  //otherwise no winner
  
  return EMPTY;
}

bool Board::operator==(const Board& other)
{
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      if(board[i][j] != other.board[i][j])
        return false;
  return true;
}

int Board::getId()
{
  int id = 0;
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
    {
      int positionValue = 0;
      switch (board[i][j]) 
      {
        case PLAYER_X:
          positionValue = 0x01;
          break;
        case PLAYER_O:
          positionValue = 0x02;
          break;
        case EMPTY:
        default:
          positionValue = 0x00;
          break;
      }
      id += positionValue << (i*3+j);
    }
    return id;
}

int Board::maxId()
{
  Board Oboard;
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      Oboard.board[i][j] = PLAYER_O;
  return Oboard.getId();
}

bool Board::movesRemain()
{
  if(winner()!=EMPTY) return false;
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      if(board[i][j] == EMPTY)
        return true;
  return false;
}