#include "AlwaysInCache.hpp"
#include "FifoReadyQueue.hpp"
#include "Simulation.hpp"
#include <iostream>
#include <limits>

int main()
{
  /*TODO vary the simulation parameters to get richer results for your report*/
  cs3100::SimulationParameters p;
  p.cpus = 4;
  p.devices = 2;
  p.cacheSize = 0;
  p.contextSwitchCost = 0.1f;
  p.cacheMissCost = 1.0f;
  p.maximumTimeSlice = std::numeric_limits<float>::max();
  p.jobs = 100;
  p.meanTimeBetweenJobs = 10.0f;
  p.stddevTimeBetweenJobs = 2.0f;
  // create simulation with specific parameters and algorithms
  cs3100::Simulation s(p,
                       std::make_unique<cs3100::FifoReadyQueue>(),
                       std::make_unique<cs3100::AlwaysInCache>());
  // run simulation
  s.run();
  /*TODO create a report based on the results in s*/
  std::cout << "Efficiency : " << s.getEfficiency() << std::endl;
  std::cout << "Task\tLatency\tResponseTime" << std::endl;
  for (size_t i = 0; i < s.getJobs(); ++i)
  {
    std::cout << i << "\t" << s.rawLatency(i) << "\t" << s.rawResponseTime(i)
              << std::endl;
  }
}
