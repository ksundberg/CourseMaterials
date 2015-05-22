#ifndef BOARD_HPP
#define BOARD_HPP

#include <array>

const int ROWS=30;  // board vertical dimension
const int COLS=30;// board horizontal dimension


enum Dir{up,dn,lt,rt,none}; // all directions are specified using these

enum Rank{infantry, archer, knight, crown}; // each unit has its own rank

enum ThingType{unit,space,rock}; // All things on the board are units, rocks, or empty space

struct Thing{ // this struct is used to completely define any one space on the board
	ThingType what;  // a unit, a rock, or an empty space
	Rank rank;       // if it is a unit, this gives its rank
  std::string tla;      // if it is a unit, this gives its TLA
	Dir dir;         // it it is a unit, this gives its current direction
	int hp;          // if it is a unit, this gives its current strength
};

struct Box
{
  int minr;
  int maxr;
  int minc;
  int maxc;
};

struct Board
{
  std::array<std::array<Thing,COLS>,ROWS> things;
  std::array<std::array<char, COLS>, ROWS> c;
  std::string tla[4];
  std::string color[4];
  Box startBox[4];
};

#endif

