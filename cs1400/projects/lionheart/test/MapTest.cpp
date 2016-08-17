#include "catch.hpp"
#include "Map.hpp"

SCENARIO("Maps can be loaded and read")
{
  GIVEN( "A map loaded from a filename")
  {
    std::string filename="forts.in";
    auto map = lionheart::makeMap(filename);
    WHEN("the boxes are requested")
    {
      auto boxes = map->getBoxes();
      THEN("the number of players is correct")
      {
        REQUIRE(boxes.size() == 2);
      }
      THEN("the first box has the expected value")
      {
        auto& box = boxes[0];
        REQUIRE(box.minRow == 10);
        REQUIRE(box.maxRow == 19);
        REQUIRE(box.minCol == 2);
        REQUIRE(box.maxCol == 7);
      }
      THEN("the second box has the expected value")
      {
        auto& box = boxes[1];
        REQUIRE(box.minRow == 10);
        REQUIRE(box.maxRow == 19);
        REQUIRE(box.minCol == 22);
        REQUIRE(box.maxCol == 27);
      }
    }
    WHEN("bad rows and columns are requested")
    {
        auto neg = map->at(-1,-1);
        auto big = map->at(100,100);
      THEN("negative values yield invalid locations")
      {
        REQUIRE(!neg);
      }
      THEN("big values yield invalid locations")
      {
        REQUIRE(!big);
      }
      THEN("invalid locations yield rock tiles")
      {
        auto negtile = (*map)[neg];
        auto bigtile = (*map)[big];
        REQUIRE(negtile == lionheart::Tile::ROCK);
        REQUIRE(bigtile == lionheart::Tile::ROCK);
      }
    }
    WHEN("good rows and columns are requested")
    {
        auto space = map->at(5,5);
        auto rock = map->at(7,4);
      THEN("values yield valid locations")
      {
        CHECK(space);
        CHECK(space.row == 5);
        CHECK(space.col == 5);
        CHECK(rock);
        CHECK(rock.row == 7);
        CHECK(rock.col == 4);
      }
      THEN("spaces found where expected")
      {
        auto spacetile = (*map)[space];
        REQUIRE(spacetile == lionheart::Tile::SPACE);
      }
      THEN("rocks found where expected")
      {
        auto rocktile = (*map)[rock];
        REQUIRE(rocktile == lionheart::Tile::ROCK);
      }
    }
    WHEN("starting locations are requested")
    {
      auto boxes = map->getBoxes();
      THEN("locations are spaces")
      {
        for(auto&& box:boxes)
        {
          for(int row=box.minRow;row<box.maxRow;++row)
          {
            for(int col=box.minCol;col<box.maxCol;++col)
            {
              auto loc = map->at(row,col);
              REQUIRE(loc);
              REQUIRE(loc.row == row);
              REQUIRE(loc.col == col);
              auto tile = (*map)[loc];
              REQUIRE(tile == lionheart::Tile::SPACE);
            }
          }
        }
      }
    }
  }
}
