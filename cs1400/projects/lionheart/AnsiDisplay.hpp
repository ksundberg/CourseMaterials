#ifndef LIONHEART_ANSI_DISPLAY_HPP
#define LIONHEART_ANSI_DISPLAY_HPP

#include "Display.hpp"

namespace lionheart
{
  class AnsiDisplay: public Display
  {
    public:
      void show(SituationReport const&, Blazon const&, Blazon const&);
  };
}
#endif
