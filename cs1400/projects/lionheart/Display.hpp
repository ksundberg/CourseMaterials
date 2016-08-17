#ifndef LIONHEART_DISPLAY_HPP
#define LIONHEART_DISPLAY_HPP
#include "SituationReport.hpp"
#include "Player.hpp"

namespace lionheart
{
  class Display
  {
  public:
    Display() : output()
    {
    }
    virtual ~Display() = default;
    virtual void
    show(SituationReport const &, Blazon const &, Blazon const &) = 0;
    void setOutput(std::string o)
    {
      output = o;
    };
  protected:
    std::string output;
  };
}

#endif

