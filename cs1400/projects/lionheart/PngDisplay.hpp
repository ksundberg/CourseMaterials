#ifndef LIONHEART_PNG_DISPLAY_HPP
#define LIONHEART_PNG_DISPLAY_HPP

#include "Display.hpp"

namespace lionheart
{
  class PngDisplay: public Display
  {
    public:
      void show(SituationReport const&, Blazon const&, Blazon const&);
  };
}
#endif
