#include "PngDisplay.hpp"

#include <png.h>
#include <cstdio>

namespace
{
  const int TILE_HEIGHT = 32;
  const int TILE_WIDTH = 32;
}

void drawRock(png_bytep* /*row_pointers*/,
              int /*top*/,
              int /*left*/)
{
}

void drawSpace(png_bytep* row_pointers,
              int top,
              int left)
{
  for(int i = 0;i<TILE_HEIGHT;++i)
    for(int j=0;j<TILE_WIDTH;++j)
    {
      row_pointers[top+i][left+j] = 0;
    }
}

void drawUnit(png_bytep* /*row_pointers*/,
              int /*top*/,
              int /*left*/,
              lionheart::SituationReport::Thing const& /*thing*/,
              lionheart::Blazon const& /*blazon*/)
{
}

void drawThing(png_bytep* row_pointers,
              int top,
              int left,
              lionheart::SituationReport::Thing const& thing,
              lionheart::Blazon const& ally,
              lionheart::Blazon const& enemy)
{
    switch (thing.type)
    {
    case lionheart::SituationReport::ROCK:
      drawRock(row_pointers,top,left);
      break;
    case lionheart::SituationReport::SPACE:
      drawSpace(row_pointers,top,left);
      break;
    case lionheart::SituationReport::ALLY:
      drawUnit(row_pointers,top,left,thing, ally);
      break;
    case lionheart::SituationReport::ENEMY:
      drawUnit(row_pointers,top,left,thing, enemy);
      break;
    }
}


void lionheart::PngDisplay::show(lionheart::SituationReport const& report, Blazon const& /*p1*/, Blazon const& /*p2*/)
{
  if (report.things.empty()) return;
  std::cout << "In PngDisplay" << std::endl;
}
