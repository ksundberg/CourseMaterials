
#include "catch.hpp"
#include "Archer.hpp"
#include "Crown.hpp"
#include "Knight.hpp"
#include "Infantry.hpp"

SCENARIO("Units correctly detect what is in range")
{
  //units can only be created with a map
  std::string filename = "forts.in";
  auto map = lionheart::makeMap(filename);
  const int ROW = 10;
  const int COL = 10;
  GIVEN("A Crown Unit")
  {
    std::shared_ptr<lionheart::Unit> unit=
        std::make_shared<lionheart::Crown>(map->at(ROW, COL), lionheart::Direction::NORTH);
    THEN("Only adjacent units in front of the unit are in range")
    {
      //check north
      REQUIRE(unit->getFacing() == lionheart::Direction::NORTH);
      CHECK(unit->inRange(map->at(ROW-1,COL)));
      CHECK(!unit->inRange(map->at(ROW+1,COL)));
      CHECK(!unit->inRange(map->at(ROW,COL-1)));
      CHECK(!unit->inRange(map->at(ROW,COL+1)));
      CHECK(!unit->inRange(map->at(ROW-1,COL-1)));
      CHECK(!unit->inRange(map->at(ROW-1,COL+1)));
      CHECK(!unit->inRange(map->at(ROW+1,COL-1)));
      CHECK(!unit->inRange(map->at(ROW+1,COL+1)));
      CHECK(!unit->inRange(map->at(ROW,COL)));
      // check east
      unit->turn(lionheart::Direction::EAST);
      REQUIRE(unit->getFacing() == lionheart::Direction::EAST);
      CHECK(!unit->inRange(map->at(ROW-1,COL)));
      CHECK(!unit->inRange(map->at(ROW+1,COL)));
      CHECK(!unit->inRange(map->at(ROW,COL-1)));
      CHECK(unit->inRange(map->at(ROW,COL+1)));
      CHECK(!unit->inRange(map->at(ROW-1,COL-1)));
      CHECK(!unit->inRange(map->at(ROW-1,COL+1)));
      CHECK(!unit->inRange(map->at(ROW+1,COL-1)));
      CHECK(!unit->inRange(map->at(ROW+1,COL+1)));
      CHECK(!unit->inRange(map->at(ROW,COL)));
      // check south
      unit->turn(lionheart::Direction::SOUTH);
      REQUIRE(unit->getFacing() == lionheart::Direction::SOUTH);
      CHECK(!unit->inRange(map->at(ROW-1,COL)));
      CHECK(unit->inRange(map->at(ROW+1,COL)));
      CHECK(!unit->inRange(map->at(ROW,COL-1)));
      CHECK(!unit->inRange(map->at(ROW,COL+1)));
      CHECK(!unit->inRange(map->at(ROW-1,COL-1)));
      CHECK(!unit->inRange(map->at(ROW-1,COL+1)));
      CHECK(!unit->inRange(map->at(ROW+1,COL-1)));
      CHECK(!unit->inRange(map->at(ROW+1,COL+1)));
      CHECK(!unit->inRange(map->at(ROW,COL)));
      // check west
      unit->turn(lionheart::Direction::WEST);
      REQUIRE(unit->getFacing() == lionheart::Direction::WEST);
      CHECK(!unit->inRange(map->at(ROW-1,COL)));
      CHECK(!unit->inRange(map->at(ROW+1,COL)));
      CHECK(unit->inRange(map->at(ROW,COL-1)));
      CHECK(!unit->inRange(map->at(ROW,COL+1)));
      CHECK(!unit->inRange(map->at(ROW-1,COL-1)));
      CHECK(!unit->inRange(map->at(ROW-1,COL+1)));
      CHECK(!unit->inRange(map->at(ROW+1,COL-1)));
      CHECK(!unit->inRange(map->at(ROW+1,COL+1)));
      CHECK(!unit->inRange(map->at(ROW,COL)));

    }
  }
GIVEN("A Knight Unit")
  {
    std::shared_ptr<lionheart::Unit> unit = std::make_shared<lionheart::Knight>(
        map->at(ROW, COL), lionheart::Direction::NORTH);

    THEN("Only adjacent units in front of the unit are in range")
    {
      // check north
      REQUIRE(unit->getFacing() == lionheart::Direction::NORTH);
      CHECK(unit->inRange(map->at(ROW-1,COL)));
      CHECK(!unit->inRange(map->at(ROW+1,COL)));
      CHECK(!unit->inRange(map->at(ROW,COL-1)));
      CHECK(!unit->inRange(map->at(ROW,COL+1)));
      CHECK(!unit->inRange(map->at(ROW-1,COL-1)));
      CHECK(!unit->inRange(map->at(ROW-1,COL+1)));
      CHECK(!unit->inRange(map->at(ROW+1,COL-1)));
      CHECK(!unit->inRange(map->at(ROW+1,COL+1)));
      CHECK(!unit->inRange(map->at(ROW,COL)));
      // check east
      unit->turn(lionheart::Direction::EAST);
      REQUIRE(unit->getFacing() == lionheart::Direction::EAST);
      CHECK(!unit->inRange(map->at(ROW-1,COL)));
      CHECK(!unit->inRange(map->at(ROW+1,COL)));
      CHECK(!unit->inRange(map->at(ROW,COL-1)));
      CHECK(unit->inRange(map->at(ROW,COL+1)));
      CHECK(!unit->inRange(map->at(ROW-1,COL-1)));
      CHECK(!unit->inRange(map->at(ROW-1,COL+1)));
      CHECK(!unit->inRange(map->at(ROW+1,COL-1)));
      CHECK(!unit->inRange(map->at(ROW+1,COL+1)));
      CHECK(!unit->inRange(map->at(ROW,COL)));
      // check south
      unit->turn(lionheart::Direction::SOUTH);
      REQUIRE(unit->getFacing() == lionheart::Direction::SOUTH);
      CHECK(!unit->inRange(map->at(ROW-1,COL)));
      CHECK(unit->inRange(map->at(ROW+1,COL)));
      CHECK(!unit->inRange(map->at(ROW,COL-1)));
      CHECK(!unit->inRange(map->at(ROW,COL+1)));
      CHECK(!unit->inRange(map->at(ROW-1,COL-1)));
      CHECK(!unit->inRange(map->at(ROW-1,COL+1)));
      CHECK(!unit->inRange(map->at(ROW+1,COL-1)));
      CHECK(!unit->inRange(map->at(ROW+1,COL+1)));
      CHECK(!unit->inRange(map->at(ROW,COL)));
      // check west
      unit->turn(lionheart::Direction::WEST);
      REQUIRE(unit->getFacing() == lionheart::Direction::WEST);
      CHECK(!unit->inRange(map->at(ROW-1,COL)));
      CHECK(!unit->inRange(map->at(ROW+1,COL)));
      CHECK(unit->inRange(map->at(ROW,COL-1)));
      CHECK(!unit->inRange(map->at(ROW,COL+1)));
      CHECK(!unit->inRange(map->at(ROW-1,COL-1)));
      CHECK(!unit->inRange(map->at(ROW-1,COL+1)));
      CHECK(!unit->inRange(map->at(ROW+1,COL-1)));
      CHECK(!unit->inRange(map->at(ROW+1,COL+1)));
      CHECK(!unit->inRange(map->at(ROW,COL)));


    }
  }
GIVEN("An Infantry Unit")
  {
    std::shared_ptr<lionheart::Unit> unit =
        std::make_shared<lionheart::Infantry>(map->at(ROW, COL),
                                              lionheart::Direction::NORTH);

    THEN("Only adjacent units in front of the unit are in range")
    {
      // check north
      REQUIRE(unit->getFacing() == lionheart::Direction::NORTH);
      CHECK(unit->inRange(map->at(ROW-1,COL)));
      CHECK(!unit->inRange(map->at(ROW+1,COL)));
      CHECK(!unit->inRange(map->at(ROW,COL-1)));
      CHECK(!unit->inRange(map->at(ROW,COL+1)));
      CHECK(!unit->inRange(map->at(ROW-1,COL-1)));
      CHECK(!unit->inRange(map->at(ROW-1,COL+1)));
      CHECK(!unit->inRange(map->at(ROW+1,COL-1)));
      CHECK(!unit->inRange(map->at(ROW+1,COL+1)));
      CHECK(!unit->inRange(map->at(ROW,COL)));
      // check east
      unit->turn(lionheart::Direction::EAST);
      REQUIRE(unit->getFacing() == lionheart::Direction::EAST);
      CHECK(!unit->inRange(map->at(ROW-1,COL)));
      CHECK(!unit->inRange(map->at(ROW+1,COL)));
      CHECK(!unit->inRange(map->at(ROW,COL-1)));
      CHECK(unit->inRange(map->at(ROW,COL+1)));
      CHECK(!unit->inRange(map->at(ROW-1,COL-1)));
      CHECK(!unit->inRange(map->at(ROW-1,COL+1)));
      CHECK(!unit->inRange(map->at(ROW+1,COL-1)));
      CHECK(!unit->inRange(map->at(ROW+1,COL+1)));
      CHECK(!unit->inRange(map->at(ROW,COL)));
      // check south
      unit->turn(lionheart::Direction::SOUTH);
      REQUIRE(unit->getFacing() == lionheart::Direction::SOUTH);
      CHECK(!unit->inRange(map->at(ROW-1,COL)));
      CHECK(unit->inRange(map->at(ROW+1,COL)));
      CHECK(!unit->inRange(map->at(ROW,COL-1)));
      CHECK(!unit->inRange(map->at(ROW,COL+1)));
      CHECK(!unit->inRange(map->at(ROW-1,COL-1)));
      CHECK(!unit->inRange(map->at(ROW-1,COL+1)));
      CHECK(!unit->inRange(map->at(ROW+1,COL-1)));
      CHECK(!unit->inRange(map->at(ROW+1,COL+1)));
      CHECK(!unit->inRange(map->at(ROW,COL)));
      // check west
      unit->turn(lionheart::Direction::WEST);
      REQUIRE(unit->getFacing() == lionheart::Direction::WEST);
      CHECK(!unit->inRange(map->at(ROW-1,COL)));
      CHECK(!unit->inRange(map->at(ROW+1,COL)));
      CHECK(unit->inRange(map->at(ROW,COL-1)));
      CHECK(!unit->inRange(map->at(ROW,COL+1)));
      CHECK(!unit->inRange(map->at(ROW-1,COL-1)));
      CHECK(!unit->inRange(map->at(ROW-1,COL+1)));
      CHECK(!unit->inRange(map->at(ROW+1,COL-1)));
      CHECK(!unit->inRange(map->at(ROW+1,COL+1)));
      CHECK(!unit->inRange(map->at(ROW,COL)));


    }
  }
GIVEN("An Archer Unit")
  {
std::shared_ptr<lionheart::Unit> unit =
        std::make_shared<lionheart::Archer>(map->at(ROW, COL),
                                              lionheart::Direction::NORTH);


    THEN("Only units in 3x3 box in front of unit are in range")
    {
      // check north
      REQUIRE(unit->getFacing() == lionheart::Direction::NORTH);
      CHECK(!unit->inRange(map->at(ROW - 3, COL - 3)));
      CHECK(!unit->inRange(map->at(ROW - 3, COL - 2)));
      CHECK(unit->inRange(map->at(ROW - 3, COL - 1)));
      CHECK(unit->inRange(map->at(ROW - 3, COL + 0)));
      CHECK(unit->inRange(map->at(ROW - 3, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW - 3, COL + 2)));
      CHECK(!unit->inRange(map->at(ROW - 3, COL + 3)));
      CHECK(!unit->inRange(map->at(ROW - 2, COL - 3)));
      CHECK(!unit->inRange(map->at(ROW - 2, COL - 2)));
      CHECK(unit->inRange(map->at(ROW - 2, COL - 1)));
      CHECK(unit->inRange(map->at(ROW - 2, COL + 0)));
      CHECK(unit->inRange(map->at(ROW - 2, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW - 2, COL + 2)));
      CHECK(!unit->inRange(map->at(ROW - 2, COL + 3)));
      CHECK(!unit->inRange(map->at(ROW - 1, COL - 3)));
      CHECK(!unit->inRange(map->at(ROW - 1, COL - 2)));
      CHECK(unit->inRange(map->at(ROW - 1, COL - 1)));
      CHECK(unit->inRange(map->at(ROW - 1, COL + 0)));
      CHECK(unit->inRange(map->at(ROW - 1, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW - 1, COL + 2)));
      CHECK(!unit->inRange(map->at(ROW - 1, COL + 3)));
      CHECK(!unit->inRange(map->at(ROW + 0, COL - 3)));
      CHECK(!unit->inRange(map->at(ROW + 0, COL - 2)));
      CHECK(!unit->inRange(map->at(ROW + 0, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW + 0, COL + 0)));
      CHECK(!unit->inRange(map->at(ROW + 0, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW + 0, COL + 2)));
      CHECK(!unit->inRange(map->at(ROW + 0, COL + 3)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL - 3)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL - 2)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL + 0)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL + 2)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL + 3)));
      CHECK(!unit->inRange(map->at(ROW + 2, COL - 3)));
      CHECK(!unit->inRange(map->at(ROW + 2, COL - 2)));
      CHECK(!unit->inRange(map->at(ROW + 2, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW + 2, COL + 0)));
      CHECK(!unit->inRange(map->at(ROW + 2, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW + 2, COL + 2)));
      CHECK(!unit->inRange(map->at(ROW + 2, COL + 3)));
      CHECK(!unit->inRange(map->at(ROW + 3, COL - 3)));
      CHECK(!unit->inRange(map->at(ROW + 3, COL - 2)));
      CHECK(!unit->inRange(map->at(ROW + 3, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW + 3, COL + 0)));
      CHECK(!unit->inRange(map->at(ROW + 3, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW + 3, COL + 2)));
      CHECK(!unit->inRange(map->at(ROW + 3, COL + 3)));

            // check east
      unit->turn(lionheart::Direction::EAST);
      REQUIRE(unit->getFacing() == lionheart::Direction::EAST);
      CHECK(!unit->inRange(map->at(ROW - 3, COL - 3)));
      CHECK(!unit->inRange(map->at(ROW - 3, COL - 2)));
      CHECK(!unit->inRange(map->at(ROW - 3, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW - 3, COL + 0)));
      CHECK(!unit->inRange(map->at(ROW - 3, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW - 3, COL + 2)));
      CHECK(!unit->inRange(map->at(ROW - 3, COL + 3)));
      CHECK(!unit->inRange(map->at(ROW - 2, COL - 3)));
      CHECK(!unit->inRange(map->at(ROW - 2, COL - 2)));
      CHECK(!unit->inRange(map->at(ROW - 2, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW - 2, COL + 0)));
      CHECK(!unit->inRange(map->at(ROW - 2, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW - 2, COL + 2)));
      CHECK(!unit->inRange(map->at(ROW - 2, COL + 3)));
      CHECK(!unit->inRange(map->at(ROW - 1, COL - 3)));
      CHECK(!unit->inRange(map->at(ROW - 1, COL - 2)));
      CHECK(!unit->inRange(map->at(ROW - 1, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW - 1, COL + 0)));
      CHECK(unit->inRange(map->at(ROW - 1, COL + 1)));
      CHECK(unit->inRange(map->at(ROW - 1, COL + 2)));
      CHECK(unit->inRange(map->at(ROW - 1, COL + 3)));
      CHECK(!unit->inRange(map->at(ROW + 0, COL - 3)));
      CHECK(!unit->inRange(map->at(ROW + 0, COL - 2)));
      CHECK(!unit->inRange(map->at(ROW + 0, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW + 0, COL + 0)));
      CHECK(unit->inRange(map->at(ROW + 0, COL + 1)));
      CHECK(unit->inRange(map->at(ROW + 0, COL + 2)));
      CHECK(unit->inRange(map->at(ROW + 0, COL + 3)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL - 3)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL - 2)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL + 0)));
      CHECK(unit->inRange(map->at(ROW + 1, COL + 1)));
      CHECK(unit->inRange(map->at(ROW + 1, COL + 2)));
      CHECK(unit->inRange(map->at(ROW + 1, COL + 3)));
      CHECK(!unit->inRange(map->at(ROW + 2, COL - 3)));
      CHECK(!unit->inRange(map->at(ROW + 2, COL - 2)));
      CHECK(!unit->inRange(map->at(ROW + 2, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW + 2, COL + 0)));
      CHECK(!unit->inRange(map->at(ROW + 2, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW + 2, COL + 2)));
      CHECK(!unit->inRange(map->at(ROW + 2, COL + 3)));
      CHECK(!unit->inRange(map->at(ROW + 3, COL - 3)));
      CHECK(!unit->inRange(map->at(ROW + 3, COL - 2)));
      CHECK(!unit->inRange(map->at(ROW + 3, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW + 3, COL + 0)));
      CHECK(!unit->inRange(map->at(ROW + 3, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW + 3, COL + 2)));
      CHECK(!unit->inRange(map->at(ROW + 3, COL + 3)));


      // check south
      unit->turn(lionheart::Direction::SOUTH);
      REQUIRE(unit->getFacing() == lionheart::Direction::SOUTH);
CHECK(!unit->inRange(map->at(ROW - 3, COL - 3)));
      CHECK(!unit->inRange(map->at(ROW - 3, COL - 2)));
      CHECK(!unit->inRange(map->at(ROW - 3, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW - 3, COL + 0)));
      CHECK(!unit->inRange(map->at(ROW - 3, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW - 3, COL + 2)));
      CHECK(!unit->inRange(map->at(ROW - 3, COL + 3)));
      CHECK(!unit->inRange(map->at(ROW - 2, COL - 3)));
      CHECK(!unit->inRange(map->at(ROW - 2, COL - 2)));
      CHECK(!unit->inRange(map->at(ROW - 2, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW - 2, COL + 0)));
      CHECK(!unit->inRange(map->at(ROW - 2, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW - 2, COL + 2)));
      CHECK(!unit->inRange(map->at(ROW - 2, COL + 3)));
      CHECK(!unit->inRange(map->at(ROW - 1, COL - 3)));
      CHECK(!unit->inRange(map->at(ROW - 1, COL - 2)));
      CHECK(!unit->inRange(map->at(ROW - 1, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW - 1, COL + 0)));
      CHECK(!unit->inRange(map->at(ROW - 1, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW - 1, COL + 2)));
      CHECK(!unit->inRange(map->at(ROW - 1, COL + 3)));
      CHECK(!unit->inRange(map->at(ROW + 0, COL - 3)));
      CHECK(!unit->inRange(map->at(ROW + 0, COL - 2)));
      CHECK(!unit->inRange(map->at(ROW + 0, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW + 0, COL + 0)));
      CHECK(!unit->inRange(map->at(ROW + 0, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW + 0, COL + 2)));
      CHECK(!unit->inRange(map->at(ROW + 0, COL + 3)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL - 3)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL - 2)));
      CHECK(unit->inRange(map->at(ROW + 1, COL - 1)));
      CHECK(unit->inRange(map->at(ROW + 1, COL + 0)));
      CHECK(unit->inRange(map->at(ROW + 1, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL + 2)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL + 3)));
      CHECK(!unit->inRange(map->at(ROW + 2, COL - 3)));
      CHECK(!unit->inRange(map->at(ROW + 2, COL - 2)));
      CHECK(unit->inRange(map->at(ROW + 2, COL - 1)));
      CHECK(unit->inRange(map->at(ROW + 2, COL + 0)));
      CHECK(unit->inRange(map->at(ROW + 2, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW + 2, COL + 2)));
      CHECK(!unit->inRange(map->at(ROW + 2, COL + 3)));
      CHECK(!unit->inRange(map->at(ROW + 3, COL - 3)));
      CHECK(!unit->inRange(map->at(ROW + 3, COL - 2)));
      CHECK(unit->inRange(map->at(ROW + 3, COL - 1)));
      CHECK(unit->inRange(map->at(ROW + 3, COL + 0)));
      CHECK(unit->inRange(map->at(ROW + 3, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW + 3, COL + 2)));
      CHECK(!unit->inRange(map->at(ROW + 3, COL + 3)));


            // check west
      unit->turn(lionheart::Direction::WEST);
      REQUIRE(unit->getFacing() == lionheart::Direction::WEST);
      CHECK(!unit->inRange(map->at(ROW - 3, COL - 3)));
      CHECK(!unit->inRange(map->at(ROW - 3, COL - 2)));
      CHECK(!unit->inRange(map->at(ROW - 3, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW - 3, COL + 0)));
      CHECK(!unit->inRange(map->at(ROW - 3, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW - 3, COL + 2)));
      CHECK(!unit->inRange(map->at(ROW - 3, COL + 3)));
      CHECK(!unit->inRange(map->at(ROW - 2, COL - 3)));
      CHECK(!unit->inRange(map->at(ROW - 2, COL - 2)));
      CHECK(!unit->inRange(map->at(ROW - 2, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW - 2, COL + 0)));
      CHECK(!unit->inRange(map->at(ROW - 2, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW - 2, COL + 2)));
      CHECK(!unit->inRange(map->at(ROW - 2, COL + 3)));
      CHECK(unit->inRange(map->at(ROW - 1, COL - 3)));
      CHECK(unit->inRange(map->at(ROW - 1, COL - 2)));
      CHECK(unit->inRange(map->at(ROW - 1, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW - 1, COL + 0)));
      CHECK(!unit->inRange(map->at(ROW - 1, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW - 1, COL + 2)));
      CHECK(!unit->inRange(map->at(ROW - 1, COL + 3)));
      CHECK(unit->inRange(map->at(ROW + 0, COL - 3)));
      CHECK(unit->inRange(map->at(ROW + 0, COL - 2)));
      CHECK(unit->inRange(map->at(ROW + 0, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW + 0, COL + 0)));
      CHECK(!unit->inRange(map->at(ROW + 0, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW + 0, COL + 2)));
      CHECK(!unit->inRange(map->at(ROW + 0, COL + 3)));
      CHECK(unit->inRange(map->at(ROW + 1, COL - 3)));
      CHECK(unit->inRange(map->at(ROW + 1, COL - 2)));
      CHECK(unit->inRange(map->at(ROW + 1, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL + 0)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL + 2)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL + 3)));
      CHECK(!unit->inRange(map->at(ROW + 2, COL - 3)));
      CHECK(!unit->inRange(map->at(ROW + 2, COL - 2)));
      CHECK(!unit->inRange(map->at(ROW + 2, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW + 2, COL + 0)));
      CHECK(!unit->inRange(map->at(ROW + 2, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW + 2, COL + 2)));
      CHECK(!unit->inRange(map->at(ROW + 2, COL + 3)));
      CHECK(!unit->inRange(map->at(ROW + 3, COL - 3)));
      CHECK(!unit->inRange(map->at(ROW + 3, COL - 2)));
      CHECK(!unit->inRange(map->at(ROW + 3, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW + 3, COL + 0)));
      CHECK(!unit->inRange(map->at(ROW + 3, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW + 3, COL + 2)));
      CHECK(!unit->inRange(map->at(ROW + 3, COL + 3)));




    }
  }
}
