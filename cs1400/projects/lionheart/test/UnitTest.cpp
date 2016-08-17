
#include "catch.hpp"
#include "Archer.hpp"
#include "Crown.hpp"
#include "Knight.hpp"
#include "Infantry.hpp"

SCENARIO("Units move correctly")
{
  std::string filename = "forts.in";
  auto map = lionheart::makeMap(filename);
  const int ROW = 12;
  const int COL = 12;
  GIVEN("Any Unit")
  {
    std::vector<std::shared_ptr<lionheart::Unit>> units;
    units.push_back(std::make_shared<lionheart::Crown>(0, map->at(ROW, COL), lionheart::Direction::NORTH));
    units.push_back(std::make_shared<lionheart::Knight>(1, map->at(ROW, COL), lionheart::Direction::NORTH));
    units.push_back(std::make_shared<lionheart::Archer>(2, map->at(ROW, COL), lionheart::Direction::NORTH));
    units.push_back(std::make_shared<lionheart::Infantry>(3, map->at(ROW, COL), lionheart::Direction::NORTH));
    THEN("Units can not move more than horses")
    {
      for (auto &&unit : units)
      {
        REQUIRE(unit->getFacing() == lionheart::Direction::NORTH);
        auto current = unit->getLocation();
        auto target = map->at(current.row - 10, current.col);
        REQUIRE(target);
        unit->move(target);
        auto newLoc = unit->getLocation();
        CHECK(target.row != newLoc.row);
        CHECK(current.row == newLoc.row);
        CHECK(current.col == newLoc.col);
      }
    }
    THEN("Units can not move direction they are not facing")
    {
      for (auto &&unit : units)
      {
        {
          REQUIRE(unit->getFacing() == lionheart::Direction::NORTH);
          auto current = unit->getLocation();
          {
            auto target = map->at(current.row + 1, current.col);
            REQUIRE(target);
            unit->move(target);
            auto newLoc = unit->getLocation();
            REQUIRE(current.row == newLoc.row);
            REQUIRE(current.col == newLoc.col);
          }
          {
            auto target = map->at(current.row, current.col + 1);
            REQUIRE(target);
            unit->move(target);
            auto newLoc = unit->getLocation();
            REQUIRE(current.row == newLoc.row);
            REQUIRE(current.col == newLoc.col);
          }
          {
            auto target = map->at(current.row, current.col - 1);
            REQUIRE(target);
            unit->move(target);
            auto newLoc = unit->getLocation();
            REQUIRE(current.row == newLoc.row);
            REQUIRE(current.col == newLoc.col);
          }
        }
        {
          unit->turn(lionheart::Direction::EAST);
          REQUIRE(unit->getFacing() == lionheart::Direction::EAST);
          auto current = unit->getLocation();
          {
            auto target = map->at(current.row, current.col - 1);
            REQUIRE(target);
            unit->move(target);
            auto newLoc = unit->getLocation();
            REQUIRE(current.row == newLoc.row);
            REQUIRE(current.col == newLoc.col);
          }
          {
            auto target = map->at(current.row + 1, current.col);
            REQUIRE(target);
            unit->move(target);
            auto newLoc = unit->getLocation();
            REQUIRE(current.row == newLoc.row);
            REQUIRE(current.col == newLoc.col);
          }
          {
            auto target = map->at(current.row - 1, current.col);
            REQUIRE(target);
            unit->move(target);
            auto newLoc = unit->getLocation();
            REQUIRE(current.row == newLoc.row);
            REQUIRE(current.col == newLoc.col);
          }
        }
        {
          unit->turn(lionheart::Direction::WEST);
          REQUIRE(unit->getFacing() == lionheart::Direction::WEST);
          auto current = unit->getLocation();
          {
            auto target = map->at(current.row, current.col + 1);
            REQUIRE(target);
            unit->move(target);
            auto newLoc = unit->getLocation();
            REQUIRE(current.row == newLoc.row);
            REQUIRE(current.col == newLoc.col);
          }
          {
            auto target = map->at(current.row + 1, current.col);
            REQUIRE(target);
            unit->move(target);
            auto newLoc = unit->getLocation();
            REQUIRE(current.row == newLoc.row);
            REQUIRE(current.col == newLoc.col);
          }
          {
            auto target = map->at(current.row - 1, current.col);
            REQUIRE(target);
            unit->move(target);
            auto newLoc = unit->getLocation();
            REQUIRE(current.row == newLoc.row);
            REQUIRE(current.col == newLoc.col);
          }
        }

        {
          unit->turn(lionheart::Direction::SOUTH);
          REQUIRE(unit->getFacing() == lionheart::Direction::SOUTH);
          auto current = unit->getLocation();
          {
            auto target = map->at(current.row - 1, current.col);
            REQUIRE(target);
            unit->move(target);
            auto newLoc = unit->getLocation();
            REQUIRE(current.row == newLoc.row);
            REQUIRE(current.col == newLoc.col);
          }
          {
            auto target = map->at(current.row, current.col + 1);
            REQUIRE(target);
            unit->move(target);
            auto newLoc = unit->getLocation();
            REQUIRE(current.row == newLoc.row);
            REQUIRE(current.col == newLoc.col);
          }
          {
            auto target = map->at(current.row, current.col - 1);
            REQUIRE(target);
            unit->move(target);
            auto newLoc = unit->getLocation();
            REQUIRE(current.row == newLoc.row);
            REQUIRE(current.col == newLoc.col);
          }
        }
      }
    }
    THEN("Units can not move diagonally")
    {
      for (auto &&unit : units)
      {
        REQUIRE(unit->getFacing() == lionheart::Direction::NORTH);
        auto current = unit->getLocation();
        auto target = map->at(current.row - 1, current.col - 1);
        REQUIRE(target);
        unit->move(target);
        auto newLoc = unit->getLocation();
        CHECK(target.row != newLoc.row);
        CHECK(target.col != newLoc.col);
        CHECK(current.row == newLoc.row);
        CHECK(current.col == newLoc.col);
      }
    }
  }
  GIVEN("Mounted Units")
  {
    std::vector<std::shared_ptr<lionheart::Unit>> units;
    units.push_back(std::make_shared<lionheart::Crown>(0,
        map->at(ROW, COL), lionheart::Direction::NORTH));
    units.push_back(std::make_shared<lionheart::Knight>(1,
        map->at(ROW, COL), lionheart::Direction::NORTH));
    THEN("Unit can move north")
    {
      for (auto &&unit : units)
      {
        for (int i = 1; i <= 4; ++i)
        {
          REQUIRE(unit->getFacing() == lionheart::Direction::NORTH);
          auto current = unit->getLocation();
          auto target = map->at(current.row - i, current.col);
          CAPTURE(i);
          CAPTURE(current.row);
          CAPTURE(current.col);
          REQUIRE(target);
          unit->move(target);
          auto newLoc = unit->getLocation();
          CHECK(target.row == newLoc.row);
          CHECK(target.col == newLoc.col);
        }
      }
    }
    THEN("Unit can move south")
    {
      for (auto &&unit : units)
      {
        unit->turn(lionheart::Direction::SOUTH);
        for (int i = 1; i <= 5; ++i)
        {
          REQUIRE(unit->getFacing() == lionheart::Direction::SOUTH);
          auto current = unit->getLocation();
          auto target = map->at(current.row + i, current.col);
          REQUIRE(target);
          unit->move(target);
          auto newLoc = unit->getLocation();
          CHECK(target.row == newLoc.row);
          CHECK(target.col == newLoc.col);
        }
      }
    }
    THEN("Unit can move east")
    {
      for (auto &&unit : units)
      {
        unit->turn(lionheart::Direction::EAST);
        for (int i = 1; i <= 5; ++i)
        {
          REQUIRE(unit->getFacing() == lionheart::Direction::EAST);
          auto current = unit->getLocation();
          auto target = map->at(current.row, current.col + i);
          CAPTURE(i);
          CAPTURE(current.row);
          CAPTURE(current.col);
          REQUIRE(target);
          unit->move(target);
          auto newLoc = unit->getLocation();
          CHECK(target.row == newLoc.row);
          CHECK(target.col == newLoc.col);
        }
      }
    }
    THEN("Unit can move west")
    {
      for (auto &&unit : units)
      {
        unit->turn(lionheart::Direction::WEST);
        for (int i = 1; i <= 4; ++i)
        {
          REQUIRE(unit->getFacing() == lionheart::Direction::WEST);
          auto current = unit->getLocation();
          auto target = map->at(current.row, current.col - i);

          REQUIRE(target);
          unit->move(target);
          auto newLoc = unit->getLocation();
          CHECK(target.row == newLoc.row);
          CHECK(target.col == newLoc.col);
        }
      }
    }
  }
  GIVEN("Not mounted units")
  {
    std::vector<std::shared_ptr<lionheart::Unit>> units;
    units.push_back(std::make_shared<lionheart::Archer>(0,
        map->at(ROW, COL), lionheart::Direction::NORTH));
    units.push_back(std::make_shared<lionheart::Infantry>(1,
        map->at(ROW, COL), lionheart::Direction::NORTH));
    const int i = 1; // distance that units can move
    THEN("Unit can move north")
    {
      for (auto &&unit : units)
      {
        REQUIRE(unit->getFacing() == lionheart::Direction::NORTH);
        auto current = unit->getLocation();
        auto target = map->at(current.row - i, current.col);
        REQUIRE(target);
        unit->move(target);
        auto newLoc = unit->getLocation();
        CHECK(target.row == newLoc.row);
        CHECK(target.col == newLoc.col);
      }
    }
    THEN("Unit can move south")
    {
      for (auto &&unit : units)
      {
        unit->turn(lionheart::Direction::SOUTH);
        REQUIRE(unit->getFacing() == lionheart::Direction::SOUTH);
        auto current = unit->getLocation();
        auto target = map->at(current.row + i, current.col);
        REQUIRE(target);
        unit->move(target);
        auto newLoc = unit->getLocation();
        CHECK(target.row == newLoc.row);
        CHECK(target.col == newLoc.col);
      }
    }
    THEN("Unit can move east")
    {
      for (auto &&unit : units)
      {
        unit->turn(lionheart::Direction::EAST);
        REQUIRE(unit->getFacing() == lionheart::Direction::EAST);
        auto current = unit->getLocation();
        auto target = map->at(current.row, current.col + i);
        CAPTURE(i);
        CAPTURE(current.row);
        CAPTURE(current.col);
        REQUIRE(target);
        unit->move(target);
        auto newLoc = unit->getLocation();
        CHECK(target.row == newLoc.row);
        CHECK(target.col == newLoc.col);
      }
    }
    THEN("Unit can move west")
    {
      for (auto &&unit : units)
      {
        unit->turn(lionheart::Direction::WEST);
        REQUIRE(unit->getFacing() == lionheart::Direction::WEST);
        auto current = unit->getLocation();
        auto target = map->at(current.row, current.col - i);

        REQUIRE(target);
        unit->move(target);
        auto newLoc = unit->getLocation();
        CHECK(target.row == newLoc.row);
        CHECK(target.col == newLoc.col);
      }
    }
  }
}

SCENARIO("Units correctly detect what is in range")
{
  // units can only be created with a map
  std::string filename = "forts.in";
  auto map = lionheart::makeMap(filename);
  const int ROW = 10;
  const int COL = 10;
  GIVEN("A Crown Unit")
  {
    std::shared_ptr<lionheart::Unit> unit =
      std::make_shared<lionheart::Crown>(0, map->at(ROW, COL), lionheart::Direction::NORTH);
    THEN("Only adjacent units in front of the unit are in range")
    {
      // check north
      REQUIRE(unit->getFacing() == lionheart::Direction::NORTH);
      CHECK(unit->inRange(map->at(ROW - 1, COL)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL)));
      CHECK(!unit->inRange(map->at(ROW, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW - 1, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW - 1, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW, COL)));
      // check east
      unit->turn(lionheart::Direction::EAST);
      REQUIRE(unit->getFacing() == lionheart::Direction::EAST);
      CHECK(!unit->inRange(map->at(ROW - 1, COL)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL)));
      CHECK(!unit->inRange(map->at(ROW, COL - 1)));
      CHECK(unit->inRange(map->at(ROW, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW - 1, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW - 1, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW, COL)));
      // check south
      unit->turn(lionheart::Direction::SOUTH);
      REQUIRE(unit->getFacing() == lionheart::Direction::SOUTH);
      CHECK(!unit->inRange(map->at(ROW - 1, COL)));
      CHECK(unit->inRange(map->at(ROW + 1, COL)));
      CHECK(!unit->inRange(map->at(ROW, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW - 1, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW - 1, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW, COL)));
      // check west
      unit->turn(lionheart::Direction::WEST);
      REQUIRE(unit->getFacing() == lionheart::Direction::WEST);
      CHECK(!unit->inRange(map->at(ROW - 1, COL)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL)));
      CHECK(unit->inRange(map->at(ROW, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW - 1, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW - 1, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW, COL)));
    }
  }
  GIVEN("A Knight Unit")
  {
    std::shared_ptr<lionheart::Unit> unit = std::make_shared<lionheart::Knight>(0,
        map->at(ROW, COL), lionheart::Direction::NORTH);

    THEN("Only adjacent units in front of the unit are in range")
    {
      // check north
      REQUIRE(unit->getFacing() == lionheart::Direction::NORTH);
      CHECK(unit->inRange(map->at(ROW - 1, COL)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL)));
      CHECK(!unit->inRange(map->at(ROW, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW - 1, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW - 1, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW, COL)));
      // check east
      unit->turn(lionheart::Direction::EAST);
      REQUIRE(unit->getFacing() == lionheart::Direction::EAST);
      CHECK(!unit->inRange(map->at(ROW - 1, COL)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL)));
      CHECK(!unit->inRange(map->at(ROW, COL - 1)));
      CHECK(unit->inRange(map->at(ROW, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW - 1, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW - 1, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW, COL)));
      // check south
      unit->turn(lionheart::Direction::SOUTH);
      REQUIRE(unit->getFacing() == lionheart::Direction::SOUTH);
      CHECK(!unit->inRange(map->at(ROW - 1, COL)));
      CHECK(unit->inRange(map->at(ROW + 1, COL)));
      CHECK(!unit->inRange(map->at(ROW, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW - 1, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW - 1, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW, COL)));
      // check west
      unit->turn(lionheart::Direction::WEST);
      REQUIRE(unit->getFacing() == lionheart::Direction::WEST);
      CHECK(!unit->inRange(map->at(ROW - 1, COL)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL)));
      CHECK(unit->inRange(map->at(ROW, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW - 1, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW - 1, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW, COL)));
    }
  }
  GIVEN("An Infantry Unit")
  {
    std::shared_ptr<lionheart::Unit> unit =
        std::make_shared<lionheart::Infantry>(0,map->at(ROW, COL),
                                              lionheart::Direction::NORTH);

    THEN("Only adjacent units in front of the unit are in range")
    {
      // check north
      REQUIRE(unit->getFacing() == lionheart::Direction::NORTH);
      CHECK(unit->inRange(map->at(ROW - 1, COL)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL)));
      CHECK(!unit->inRange(map->at(ROW, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW - 1, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW - 1, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW, COL)));
      // check east
      unit->turn(lionheart::Direction::EAST);
      REQUIRE(unit->getFacing() == lionheart::Direction::EAST);
      CHECK(!unit->inRange(map->at(ROW - 1, COL)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL)));
      CHECK(!unit->inRange(map->at(ROW, COL - 1)));
      CHECK(unit->inRange(map->at(ROW, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW - 1, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW - 1, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW, COL)));
      // check south
      unit->turn(lionheart::Direction::SOUTH);
      REQUIRE(unit->getFacing() == lionheart::Direction::SOUTH);
      CHECK(!unit->inRange(map->at(ROW - 1, COL)));
      CHECK(unit->inRange(map->at(ROW + 1, COL)));
      CHECK(!unit->inRange(map->at(ROW, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW - 1, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW - 1, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW, COL)));
      // check west
      unit->turn(lionheart::Direction::WEST);
      REQUIRE(unit->getFacing() == lionheart::Direction::WEST);
      CHECK(!unit->inRange(map->at(ROW - 1, COL)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL)));
      CHECK(unit->inRange(map->at(ROW, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW - 1, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW - 1, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL - 1)));
      CHECK(!unit->inRange(map->at(ROW + 1, COL + 1)));
      CHECK(!unit->inRange(map->at(ROW, COL)));
    }
  }
  GIVEN("An Archer Unit")
  {
    std::shared_ptr<lionheart::Unit> unit = std::make_shared<lionheart::Archer>(0,
        map->at(ROW, COL), lionheart::Direction::NORTH);

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

SCENARIO("Units correctly detect what is in range for problems found in testing")
{  // units can only be created with a map
  std::string filename = "forts.in";
  auto map = lionheart::makeMap(filename);
  GIVEN("An Archer Unit as 10,3")
  {
    std::shared_ptr<lionheart::Unit> unit = std::make_shared<lionheart::Archer>(0,
        map->at(10, 3), lionheart::Direction::EAST);
    THEN("These units are not in range")
    {
      CHECK(!unit->inRange(map->at(11,24)));
      CHECK(!unit->inRange(map->at(11,25)));
    }
  }
}
