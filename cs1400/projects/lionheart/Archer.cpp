#include "Archer.hpp"

//check if target is on this row up to three columns away
bool checkRow(int r,int c,int tr,int tc)
{
  if(r!=tr) return false;
  if(tc<c) return false;
  if (tc - c < 3) return true;
  return false;
}

//check current row as well as row above and below
bool checkCols(int r,int c,int tr,int tc)
{
  auto result = checkRow(r-1,c,tr,tc);
  result = result || checkRow(r,c,tr,tc);
  result = result || checkRow(r+1,c,tr,tc);
  return result;
}

bool lionheart::Archer::inRange(Map::Location const & l) const
{
  auto location = getLocation();
  auto targetRow = l.row;
  auto targetCol = l.col;
  auto row = location.row;
  auto col = location.col;
  //use symmetry to transform each direction to east check
  switch(getFacing())
  {
    case Direction::NORTH:
      return checkCols(targetCol,targetRow,col,row-1);
    case Direction::EAST:
      return checkCols(row,col+1,targetRow,targetCol);
    case Direction::WEST:
      return checkCols(targetRow,targetCol,row,col-1);
    case Direction::SOUTH:
      return checkCols(col,row+1,targetCol,targetRow);
  }
  return false;
}
