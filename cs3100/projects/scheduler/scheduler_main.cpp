#include "AlwaysInCache.hpp"
#include "FifoReadyQueue.hpp"
#include "Simulation.hpp"
#include <iostream>
#include <limits>

namespace
{
  void report(cs3100::Simulation& s)
  {
    /*TODO create a report based on the results in s*/
    std::cout << "Efficiency : " << s.getEfficiency() << std::endl;
    std::cout << "Task\tLatency\tResponseTime" << std::endl;
    for (size_t i = 0; i < s.getJobs(); ++i)
    {
      std::cout << i << "\t" << s.rawLatency(i) << "\t" << s.rawResponseTime(i)
                << std::endl;
    }
  }

  template <typename ReadyType, typename CacheType>
  void runSimulation(cs3100::SimulationParameters const& p)
  {
    cs3100::Simulation s(
      p, std::make_unique<ReadyType>(), std::make_unique<CacheType>());
    s.run();
    report(s);
  }
}

int main()
{
  /*TODO vary the simulation parameters to get richer results for your report*/
  cs3100::SimulationParameters fifo;
  fifo.cpus = 4;
  fifo.devices = 2;
  fifo.cacheSize = 0;
  fifo.contextSwitchCost = 0.1f;
  fifo.cacheMissCost = 1.0f;
  fifo.maximumTimeSlice = std::numeric_limits<float>::max();
  fifo.jobs = 10;
  fifo.meanTimeBetweenJobs = 10.0f;
  fifo.stddevTimeBetweenJobs = 2.0f;
  // create simulation with specific parameters and algorithms
  runSimulation<cs3100::FifoReadyQueue, cs3100::AlwaysInCache>(fifo);

  cs3100::SimulationParameters roundRobin;
  roundRobin.cpus = 4;
  roundRobin.devices = 2;
  roundRobin.cacheSize = 0;
  roundRobin.contextSwitchCost = 0.1f;
  roundRobin.cacheMissCost = 1.0f;
  roundRobin.maximumTimeSlice = 5.0f;
  roundRobin.jobs = 10;
  roundRobin.meanTimeBetweenJobs = 10.0f;
  roundRobin.stddevTimeBetweenJobs = 2.0f;
  // create simulation with specific parameters and algorithms
  runSimulation<cs3100::FifoReadyQueue, cs3100::AlwaysInCache>(roundRobin);
}
