#include "Maze.hpp"
#include <iostream>
#include <fstream>

Maze::Maze() : cells()
{
}

void Maze::read(std::string filename)
{
  std::ifstream fin(filename);
  auto r=0;
  auto c=0;
  fin >> r >> c;
  cells.resize(r);
  for(auto&& row:cells)
    row.resize(c);
  for(auto curRow = 0;curRow<r;++curRow)
  {
    for(auto curCol = 0;curCol<c;++curCol)
    {
      char fromFile;
      
    }
  }
}

void Maze::solve()
{
}

void Maze::display()
{
  for(auto&& row:cells)
  {
    for(auto&& cell:row)
    {
      display(cell);
    }
    std::cout << std::endl;
  }
}

void Maze::display(Maze::MazeCell c)
{
  switch (c)
  {
  case WALL:
    std::cout << 'X';
    break;
  case VISITED:
    std::cout << ' ';
    break;
  case EMPTY:
    std::cout << ' ';
    break;
  case ON_PATH:
    std::cout << '.';
    break;
  case START:
    std::cout << 's';
    break;
  case END:
    std::cout << 'e';
    break;
  }
}

