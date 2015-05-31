#ifndef LIONHEART_MAP_HPP
#define LIONHEART_MAP_HPP

#include <vector>
#include <map>
#include <memory>
#include <iostream>

enum class Tile
{
  SPACE,
  ROCK
};

enum class Direction
{
  NORTH,
  SOUTH,
  EAST,
  WEST
};

struct PathLeg
{
  int length;
  int Direction;
};

struct StartBox
{
  int minRow;
  int maxRow;
  int minCol;
  int maxCol;
};

class LionheartMap
{
public:
  class Location
  {
  public:
    Location():row(),col(),isValid(false){}
    Location(Location const &)=default;
    operator bool() const{return isValid;}
    bool operator<(Location const& other) const;

  private:
    Location(int row, int col):row(row),col(col),isValid(true){}
    int row;
    int col;
    bool isValid;
    friend LionheartMap;
  };
  LionheartMap(std::istream&);
  Tile operator[](Location const &) const;
  Location at(int row, int col) const;
  int distance(Location const &, Location const &) const;
  std::vector<PathLeg> path(Location const &from, Location const &to) const;

private:
  std::vector<std::vector<Tile>> tiles;
  std::vector<StartBox> boxes;
  std::map<Location,std::map<Location,std::vector<PathLeg>>> paths;
  
};

std::shared_ptr<LionheartMap const> makeMap(std::string);
#endif

