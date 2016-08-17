#ifndef LIONHEART_TOURNAMENT
#define LIONHEART_TOURNAMENT

#include <vector>
#include <memory>
#include "Player.hpp"

namespace lionheart
{
  class Tournament
  {
  public:
    Tournament(){}
    virtual ~Tournament() = default;
    virtual std::vector<std::shared_ptr<Player>> run() = 0;
  };
}

#endif

