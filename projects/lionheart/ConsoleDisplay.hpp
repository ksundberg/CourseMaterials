#ifndef LIONHEART_CONSOLE_DISPLAY_HPP
#define LIONHEART_CONSOLE_DISPLAY_HPP

#include "Display.hpp"

namespace lionheart
{
  class ConsoleDisplay: public Display
  {
    public:
      void show(SituationReport const&, Blazon const&, Blazon const&);
  };
}
#endif
