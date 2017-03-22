#include "EventQueue.hpp"
#include "ReadyQueue.hpp"
#include <memory>
#include <vector>

struct Device
{
  bool busy;
  FifoReadyQueue queue;
};

class Simulation
{
Simulation();
void run();
private:
EventQueue queue;
std::unique_ptr<ReadyQueue> ready;
std::vector<Job> jobs;
int cpu;
float curTime;
const float timeSlice;
const float contextSwitchPenalty;
std::vector<Device> devices;
}
