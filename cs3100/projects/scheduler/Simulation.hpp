#ifndef CS3100_SCHEDULER_SIMULATION_HPP
#define CS3100_SCHEDULER_SIMULATION_HPP

#include "CacheAlgorithm.hpp"
#include "EventQueue.hpp"
#include "ReadyQueue.hpp"
#include <memory>
#include <vector>

namespace cs3100
{

  struct Device
  {
    bool busy;
    FifoReadyQueue queue;
  };

  struct SimulationParameters
  {
    int cpus;
    int devices;
    int cacheSize;
    float contextSwitchCost;
    float cacheMissCost;
    float maximumTimeSlice;
  };

  class Simulation
  {
    Simulation(SimulationParameters p,
               std::unique_ptr<ReadyQueue>,
               std::unique_ptr<CacheAlgorithm>);
    void run();
    float getEfficiency();
    size_t getJobs() { return jobs.size(); }
    float rawLatency(int);
    float adjustedLatency(int);
    float rawResponseTime(int);
    float adjustedResponseTime(int);

  private:
    EventQueue queue;
    std::unique_ptr<ReadyQueue> ready;
    std::unique_ptr<CacheAlgorithm> cache;
    std::vector<Job> jobs;
    std::vector<Device> devices;
    int idleCpu;
    float curTime;
    const SimulationParameters parameters;
  };
}
#endif
