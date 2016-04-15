#ifndef LIONHEART_MAP_HPP
#define LIONHEART_MAP_HPP

#include <vector>
#include <map>
#include <memory>
#include <iostream>

namespace lionheart
{
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

class Map
{
public:
  class Location
  {
  public:
    Location()
        : row()
        , col()
        , isValid(false)
    {
    }
    Location(Location const &) = default;
    operator bool() const
    {
      return isValid;
    }
    bool operator<(Location const &other) const;
    bool operator==(Location const &other) const;
    const int row;
    const int col;

  private:
    Location(int row, int col)
        : row(row)
        , col(col)
        , isValid(true)
    {
    }
    bool isValid;
    friend Map;
  };
  Map(std::string name, std::vector<std::vector<Tile>> tiles, std::vector<StartBox> boxes);
  Tile operator[](Location const &) const;
  Location at(int row, int col) const;
  std::vector<StartBox> getBoxes() const
  {
    return boxes;
  }
  size_t rows() const
  {
    return tiles.size();
  }
  size_t cols() const
  {
    if (tiles.empty())
      return 0;
    return tiles[0].size();
  }
  std::string getName() const { return name; }

private:
  std::vector<std::vector<Tile>> tiles;
  std::vector<StartBox> boxes;
  std::string name;
};

std::shared_ptr<Map const> makeMap(std::string);
}
#endif

