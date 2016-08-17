#include "catch.hpp"
#include "getPlayers.hpp"

SCENARIO("Blazons are unique")
{
    auto players = lionheart::getPlayers();
  GIVEN("Given all blazon pairs")
  {
    std::vector<std::pair<lionheart::Blazon,lionheart::Blazon>> pairs;
    for(auto i=0u;i<players.size();++i)
    {
      for(auto j=i+1;j<players.size();++j)
      {
        pairs.push_back(
            std::make_pair(players[i]->getBlazon(), players[j]->getBlazon()));
      }
    }
    THEN("No blazon is identical")
    {
      for(auto&&p:pairs)
      {
        auto identicalBlazon = ((p.first.primary == p.second.primary) &&
                                (p.first.secondary == p.second.secondary) &&
                                (p.first.style == p.second.style));
        CHECK_FALSE(identicalBlazon);
        if(identicalBlazon)
        {
          std::cerr << p.first.name << " identical to " << p.second.name << std::endl;
        }
      }
      
    }
  }
}
