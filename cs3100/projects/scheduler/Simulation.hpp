#include "EventQueue.hpp"
#include "ReadyQueue.hpp"
#include <memory>
#include <vector>

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
}
