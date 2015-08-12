#ifndef LIONHEART_COMBINED_PNG_DISPLAY_HPP
#define LIONHEART_COMBINED_PNG_DISPLAY_HPP

#include "Display.hpp"

namespace lionheart
{
  class CombinedPngDisplay: public Display
  {
    public:
      void show(SituationReport const&, Blazon const&, Blazon const&);
    private:
      struct Frame
      {
        SituationReport r;
        Blazon p1;
        Blazon p2;
      };
      std::map<std::string,std::vector<Frame>> frames;
      void writeFrames();
  };
}
#endif
