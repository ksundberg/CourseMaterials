#ifndef LIONHEART_COMBINED_PNG_DISPLAY_HPP
#define LIONHEART_COMBINED_PNG_DISPLAY_HPP

#include "Display.hpp"

namespace lionheart
{
struct Frame
{
  SituationReport report;
  Blazon p1;
  Blazon p2;
};
class CombinedPngDisplay : public Display
{
public:
  ~CombinedPngDisplay()
  {
    writeFrames();
  }
  void show(SituationReport const &, Blazon const &, Blazon const &);

private:
  std::map<std::string, std::vector<Frame>> frames;
  void writeFrames();
};
}
#endif
