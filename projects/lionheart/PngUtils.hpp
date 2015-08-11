#ifndef LIONHEART_PNG_UTILS_HPP
#define LIONHEART_PNG_UTILS_HPP

#include "SituationReport.hpp"
#include "Player.hpp"

#include <png.h>
#include <vector>

namespace lionheart
{
  const int TILE_HEIGHT = 32;
  const int TILE_WIDTH = 32;
  void drawThing(std::vector<std::vector<png_byte>>& data,
                 int top,
                 int left,
                 lionheart::SituationReport::Thing const& thing,
                 lionheart::Blazon const& ally,
                 lionheart::Blazon const& enemy);
}

#endif
