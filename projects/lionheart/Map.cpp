#include "Map.hpp"
#include <numeric>
#include <fstream>
#include <iostream>

namespace
{
  std::pair<int,int> readSize(std::istream& fin)
  {
    int row,col;
    fin>>row;
    fin>>col;
    return std::make_pair(row,col);
  }

  std::vector<lionheart::StartBox> readBoxes(std::istream& fin)
  {
    std::vector<lionheart::StartBox> boxes;
    int players;
    fin>>players;
    boxes.reserve(players);

    //read start box extents
    for(int i=0;i<players;++i)
    {
      int minr,maxr,minc,maxc;
      fin>>minr; //min row
      fin>>maxr; //max row
      fin>>minc; //min col
      fin>>maxc; //max col
      boxes.push_back(lionheart::StartBox{minr,maxr,minc,maxc});
    }
    return boxes;
  }

  std::vector<std::vector<lionheart::Tile>> readTiles(std::istream& fin,int rows,int cols)
  {
    std::vector<std::vector<lionheart::Tile>> tiles(rows);
    for (int i = 0; i < rows; ++i)
    {
      auto& row = tiles[i];
      row.reserve(cols);
      for(int j=0;j<cols;++j)
      {
        char space;
        fin >> space;
        if(space =='X')
        {
          row.push_back(lionheart::Tile::ROCK);
        }
        else
        {
          row.push_back(lionheart::Tile::SPACE);
        }
      }
    }
    return tiles;
  }
}

std::shared_ptr<lionheart::Map const> lionheart::makeMap(std::string filename)
{
  std::ifstream fin;
  fin.open(filename);
  if (fin.fail())
    throw std::runtime_error(filename + " could not be opened");
  auto extent = readSize(fin);
  auto boxes = readBoxes(fin);
  auto tiles = readTiles(fin,extent.first,extent.second);
  fin.close();
  auto m = std::make_shared<lionheart::Map>(filename,tiles,boxes);
    return m;
}

lionheart::Map::Map(std::string name, std::vector<std::vector<lionheart::Tile>> tiles,
                           std::vector<lionheart::StartBox> boxes)
    : tiles(tiles)
    , boxes(boxes)
    , name(name)
{
}

lionheart::Tile lionheart::Map::operator[](Location const& l) const
{
  if(!l) return Tile::ROCK;
  return tiles[l.row][l.col];
}

lionheart::Map::Location lionheart::Map::at(int row,int col) const
{
  if(row < 0) return Location();
  if(col < 0) return Location();
  if(static_cast<size_t>(row) >= tiles.size()) return Location();
  if(static_cast<size_t>(col) >= tiles[row].size()) return Location();
  return Location(row,col);
}

bool lionheart::Map::Location::operator<(Location const & other) const
{
  if(row < other.row) return true;
  if(row > other.row) return false;

  if (col < other.col) return true;
  if (col > other.col) return false;

  if(isValid && !other.isValid) return true;
  return false;
}

bool lionheart::Map::Location::operator==(Location const & other) const
{
  if(row != other.row) return false;
  if (col != other.col) return false;
  return true;
}

