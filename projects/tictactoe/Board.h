#ifndef _BOARD_H_
#define _BOARD_H_

class Board
{
public:
  enum Player
  {
    PLAYER_X ='X',
    PLAYER_O = 'O',
    EMPTY = ' '
  };
  Board();
  void display();
  Board move(int row,int column,Player player);
  Player winner();
  bool movesRemain();
  Player operator()(int row,int column);
  bool operator==(const Board&);
  int getId();
  static int maxId();
private:
  Player board[3][3];
};

#endif
