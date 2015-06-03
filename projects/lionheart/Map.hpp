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
    const int row;
    const int col;
  private:
    Location(int row, int col):row(row),col(col),isValid(true){}
    bool isValid;
    friend LionheartMap;
  };
  LionheartMap(std::vector<std::vector<Tile>> tiles,
               std::vector<StartBox> boxes);
  Tile operator[](Location const &) const;
  Location at(int row, int col) const;

private:
  std::vector<std::vector<Tile>> tiles;
  std::vector<StartBox> boxes;
  
};

std::shared_ptr<LionheartMap const> makeMap(std::string);
#endif

