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

  std::vector<StartBox> readBoxes(std::istream& fin)
  {
    std::vector<StartBox> boxes;
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
      boxes.push_back(StartBox{minr,maxr,minc,maxc});
    }
    return boxes;
  }

  std::vector<std::vector<Tile>> readTiles(std::istream& fin,int rows,int cols)
  {
    std::vector<std::vector<Tile>> tiles(rows);
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
          row[j] = Tile::ROCK;
        }
        else
        {
          row[j] = Tile::SPACE;
        }
      }
    }
    return tiles;
  }
}

std::shared_ptr<LionheartMap const> makeMap(std::string filename)
{
  std::ifstream fin;
  fin.open(filename);
  if (fin.fail())
    throw std::runtime_error(filename + " could not be opened");
  auto extent = readSize(fin);
  auto boxes = readBoxes(fin);
  auto tiles = readTiles(fin,extent.first,extent.second);
  fin.close();
  auto m = std::make_shared<LionheartMap>(fin);
    return m;
}

LionheartMap::LionheartMap(std::istream& fin)
  :tiles()
   ,boxes()
   ,paths()
{
  //Load map from file
        //read map data
    //Build all-pairs shortest paths
}

Tile LionheartMap::operator[](Location const& l) const
{
  if(!l) return Tile::ROCK;
  return tiles[l.row][l.col];
}

LionheartMap::Location LionheartMap::at(int row,int col) const
{
  if(row < 0) return Location();
  if(col < 0) return Location();
  if(row >= tiles.size()) return Location();
  if(col >= tiles[row].size()) return Location();
  if(tiles[row][col] == Tile::ROCK) return Location();
  return Location(row,col);
}

int LionheartMap::distance(Location const & a, Location const & b) const
{
  auto pathBetween = path(a,b);
  return std::accumulate(std::begin(pathBetween),
                         std::end(pathBetween),
                         0,
                         [](int d, PathLeg const &l)
  { return d + l.length; });
}


  std::vector<PathLeg> LionheartMap::path(Location const &from, Location const &to) const
{
  if(!from) return std::vector<PathLeg>();
  if(!to) return std::vector<PathLeg>();
  auto fromIter = paths.find(from);
  if(fromIter == paths.end()) return std::vector<PathLeg>();
  auto toIter = fromIter->second.find(to);
  if(toIter == fromIter->second.end()) return std::vector<PathLeg>();
  return toIter->second;
}

bool LionheartMap::Location::operator<(Location const & other) const
{
  if(row < other.row) return true;
  if(row > other.row) return false;

  if (col < other.col) return true;
  if (col > other.col) return false;

  if(isValid && !other.isValid) return true;
  return false;
}


