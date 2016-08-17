
#include "catch.hpp"
#include "PngDisplay.hpp"

SCENARIO("PNG display creates files")
{
  std::string filename = "forts.in";
  auto map = lionheart::makeMap(filename);
  GIVEN("A situation report")
  {
    lionheart::SituationReport r;
    lionheart::Blazon p1{lionheart::Color::OR,lionheart::Color::AZURE,lionheart::Style::QUARTERLY,"Test1"};
    lionheart::Blazon p2{lionheart::Color::GULES,lionheart::Color::ARGENT,lionheart::Style::BEND,"Test2"};
    r.turns = 0;
    // convert map to report
    r.things.reserve(map->rows());
    for (int i = 0; i < static_cast<int>(map->rows()); ++i)
    {
      r.things.emplace_back(map->cols());
      for (int j = 0; j < static_cast<int>(map->cols()); ++j)
      {
        auto tile = (*map)[map->at(i, j)];
        // default constructed things are rocks, so just clear out the spaces
        if (tile == lionheart::Tile::SPACE)
        {
          r.things[i][j].type = lionheart::SituationReport::SPACE;
        }
      }
    }
    //set some units
    r.things[4][9].type = lionheart::SituationReport::ALLY;
    r.things[4][9].unit = lionheart::UnitType::CROWN;
    r.things[4][9].direction = lionheart::Direction::NORTH;
    r.things[4][9].hp = 1;

    r.things[6][9].type = lionheart::SituationReport::ALLY;
    r.things[6][9].unit = lionheart::UnitType::KNIGHT;
    r.things[6][9].direction = lionheart::Direction::SOUTH;
    r.things[6][9].hp = 1;

    r.things[8][9].type = lionheart::SituationReport::ALLY;
    r.things[8][9].unit = lionheart::UnitType::INFANTRY;
    r.things[8][9].direction = lionheart::Direction::EAST;
    r.things[8][9].hp = 1;

    r.things[10][9].type = lionheart::SituationReport::ALLY;
    r.things[10][9].unit = lionheart::UnitType::ARCHER;
    r.things[10][9].direction = lionheart::Direction::WEST;
    r.things[10][9].hp = 1;

    r.things[12][9].type = lionheart::SituationReport::ALLY;
    r.things[12][9].unit = lionheart::UnitType::KNIGHT;
    r.things[12][9].direction = lionheart::Direction::NORTH;
    r.things[12][9].hp = 2;

    r.things[14][9].type = lionheart::SituationReport::ALLY;
    r.things[14][9].unit = lionheart::UnitType::ARCHER;
    r.things[14][9].direction = lionheart::Direction::NORTH;
    r.things[14][9].hp = 2;

    r.things[16][9].type = lionheart::SituationReport::ALLY;
    r.things[16][9].unit = lionheart::UnitType::INFANTRY;
    r.things[16][9].direction = lionheart::Direction::NORTH;
    r.things[16][9].hp = 2;

    r.things[18][9].type = lionheart::SituationReport::ALLY;
    r.things[18][9].unit = lionheart::UnitType::ARCHER;
    r.things[18][9].direction = lionheart::Direction::NORTH;
    r.things[18][9].hp = 3;

    r.things[20][9].type = lionheart::SituationReport::ALLY;
    r.things[20][9].unit = lionheart::UnitType::INFANTRY;
    r.things[20][9].direction = lionheart::Direction::NORTH;
    r.things[20][9].hp = 3;

    r.things[22][9].type = lionheart::SituationReport::ALLY;
    r.things[22][9].unit = lionheart::UnitType::ARCHER;
    r.things[22][9].direction = lionheart::Direction::NORTH;
    r.things[22][9].hp = 4;

    r.things[24][9].type = lionheart::SituationReport::ALLY;
    r.things[24][9].unit = lionheart::UnitType::INFANTRY;
    r.things[24][9].direction = lionheart::Direction::NORTH;
    r.things[24][9].hp = 4;

    r.things[4][20].type = lionheart::SituationReport::ENEMY;
    r.things[4][20].unit = lionheart::UnitType::CROWN;
    r.things[4][20].direction = lionheart::Direction::NORTH;
    r.things[4][20].hp = 1;

    r.things[5][20].type = lionheart::SituationReport::ENEMY;
    r.things[5][20].unit = lionheart::UnitType::KNIGHT;
    r.things[5][20].direction = lionheart::Direction::SOUTH;
    r.things[5][20].hp = 1;

    r.things[8][20].type = lionheart::SituationReport::ENEMY;
    r.things[8][20].unit = lionheart::UnitType::INFANTRY;
    r.things[8][20].direction = lionheart::Direction::EAST;
    r.things[8][20].hp = 1;

    r.things[10][20].type = lionheart::SituationReport::ENEMY;
    r.things[10][20].unit = lionheart::UnitType::ARCHER;
    r.things[10][20].direction = lionheart::Direction::WEST;
    r.things[10][20].hp = 1;

    r.things[12][20].type = lionheart::SituationReport::ENEMY;
    r.things[12][20].unit = lionheart::UnitType::KNIGHT;
    r.things[12][20].direction = lionheart::Direction::NORTH;
    r.things[12][20].hp = 2;

    r.things[14][20].type = lionheart::SituationReport::ENEMY;
    r.things[14][20].unit = lionheart::UnitType::ARCHER;
    r.things[14][20].direction = lionheart::Direction::NORTH;
    r.things[14][20].hp = 2;

    r.things[16][20].type = lionheart::SituationReport::ENEMY;
    r.things[16][20].unit = lionheart::UnitType::INFANTRY;
    r.things[16][20].direction = lionheart::Direction::NORTH;
    r.things[16][20].hp = 2;

    r.things[18][20].type = lionheart::SituationReport::ENEMY;
    r.things[18][20].unit = lionheart::UnitType::ARCHER;
    r.things[18][20].direction = lionheart::Direction::NORTH;
    r.things[18][20].hp = 3;

    r.things[20][20].type = lionheart::SituationReport::ENEMY;
    r.things[20][20].unit = lionheart::UnitType::INFANTRY;
    r.things[20][20].direction = lionheart::Direction::NORTH;
    r.things[20][20].hp = 3;

    r.things[22][20].type = lionheart::SituationReport::ENEMY;
    r.things[22][20].unit = lionheart::UnitType::ARCHER;
    r.things[22][20].direction = lionheart::Direction::NORTH;
    r.things[22][20].hp = 4;

    r.things[24][20].type = lionheart::SituationReport::ENEMY;
    r.things[24][20].unit = lionheart::UnitType::INFANTRY;
    r.things[24][20].direction = lionheart::Direction::NORTH;
    r.things[24][20].hp = 4;
    
    THEN("Map is drawn as expected")
    {
      lionheart::PngDisplay d;
      d.setOutput("pngtest");
      d.show(r,p1,p2);
    }
  }
  
}
