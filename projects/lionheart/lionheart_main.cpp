#include "Game.hpp"
#include "Plan.hpp"
#include "SingleElimination.hpp"
#include "AnsiDisplay.hpp"
#include "ConsoleDisplay.hpp"
#include "getPlayers.hpp"

#include <iostream>
#include <string>
#include <algorithm>

std::shared_ptr<lionheart::Display> defaultDisplay()
{
#if defined(WIN32) || defined(WIN64)
  return std::make_shared<lionheart::ConsoleDisplay>();
#else
  return std::make_shared<lionheart::AnsiDisplay>();
#endif
}

std::shared_ptr<lionheart::Display> getDisplay(std::string name)
{
  std::transform(name.begin(), name.end(), name.begin(), ::tolower);
  if (name == "ansi") return std::make_shared<lionheart::AnsiDisplay>();
  if (name == "plain") return std::make_shared<lionheart::ConsoleDisplay>();
  if (name == "none") return nullptr;
  return defaultDisplay();
}

std::shared_ptr<lionheart::Tournament> getTournament(std::string name,
                                                     std::shared_ptr<lionheart::Player> /*keyPlayer*/,
                                                     std::vector<std::shared_ptr<lionheart::Player>> players,
                                                     std::shared_ptr<lionheart::Display> display)
{
  std::transform(name.begin(), name.end(), name.begin(), ::tolower);
  if (name == "single") return std::make_shared<lionheart::SingleElimination>(players,display);
  if (name == "swiss") return nullptr;
  if (name == "gauntlet") return nullptr;
  //default
  return std::make_shared<lionheart::SingleElimination>(players,display);
}

int main(int argc, char** argv)
{

  auto players = lionheart::getPlayers();
  std::shared_ptr<lionheart::Tournament> tournament;
  std::shared_ptr<lionheart::Player> keyPlayer;

  auto display = defaultDisplay();
  
  /*Parse command line*/
  if(argc >= 2)
  {
     //set display
    display = getDisplay(argv[1]);
  }
  if (argc >= 4) {
    // set player
    auto found = std::find_if(players.begin(), players.end(), [&](std::shared_ptr<lionheart::Player> p) -> bool
                                                              {
                                                                if (!p) return false;
                                                                return p->getBlazon().name == argv[3];
                                                              });
    if(found != players.end())
    {
      keyPlayer = *found;
    }
  }
  if(argc >= 3)
  {
    //set type after setting player as it matters for some tournament types
    tournament = getTournament(argv[2],keyPlayer,players,display);
  }
  else
  {
    tournament = getTournament("",keyPlayer,players,display);
  }
  if(tournament)
  {
    tournament->run();
  }
}
