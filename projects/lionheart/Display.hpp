#ifndef LIONHEART_DISPLAY_HPP
#define LIONHEART_DISPLAY_HPP
#include "SituationReport.hpp"

namespace lionheart
{
  class Display
  {
    public:
    ~Display()=default;
    virtual void show(SituationReport const &)=0;
  };
}


#endif

