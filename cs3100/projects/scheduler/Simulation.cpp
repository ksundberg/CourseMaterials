#include "Simulation.hpp"
#include <random>

namespace
{
  int getInt(int low, int high)
  {
    thread_local std::random_device rd;
    thread_local std::mt19937 mt(rd());
    std::uniform_int_distribution<> dist(low, high);
    return dist(mt);
  }
}

namespace cs3100
{

  void Simulation::createJob()
  {
    Job j;
    j.tasks.resize(getInt(10, 100));
    std::generate(j.tasks.begin(), j.tasks.end(), []() {
      return Task(getDuration(), getInt(0, devices.size()), getType());
    });
    j.cur = tasks.begin();
    jobs.push_back(j);
    ready->add(jobs.size());
    scheduleJob();
  }

  void Simulation::scheduleJob()
  {
    if (cpu == 0) return; // No idle cpu
    auto next = ready->next();
    if (next < 0) return; // No ready task
    // Allocate cpu
    --cpu;
    // Add cpu done event
    auto timeToFinish = jobs[next].cur->duration - jobs[next].cur->progress;
    auto timeAllocated = std::min(timeSlice, timeToFinish);
    queue.emplace_back([this] { jobDone(next, timeAllocated) },
                       curTime + timeAllocated + contextSwitchPenalty);
  }

  void Simulation::scheduleIo(int job)
  {
    auto dev = jobs[job].cur->device;
    if (devices[dev].busy)
    {
      device[dev].queue.add(job);
    }
    auto finishTime = jobs[job].cur->duration;
    queue.emplace_back(
      [this]() { ioDone(job, finishTime); }, curTime + finishTime);
  }

  void Simulation::jobDone(int job, float time)
  {
    jobs[job].cur->progress += time;
    ++cpu;
    if (jobs[job].cur->progress < jobs[job].cur->duration)
    {
      ready->add(job);
    }
    else
    {
      ++(jobs[job].cur);
      if (jobs[job].cur != jobs[job].tasks.end())
      {
        scheduleIo(job);
      }
    }
    scheduleJob();
  }

  void Simulation::ioDone(int job, float time)
  {
    auto dev = jobs[job].cur->device;
    devices[dev].busy = false;
    auto next = devices[dev].queue.next();
    if (next >= 0) scheduleIo(next);
    jobs[job].cur->progress += time;
    ++(jobs[job].cur);
    if (jobs[job].cur != jobs[job].tasks.end())
    {
      ready->add(job);
      scheduleJob();
    }
  }

  void Simualation::run()
  {
    for (float t = 0.0f; t < 100.0f; t += 10.0f)
    {
      queue.emplace_back([this]() { createJob(); }, t);
    }
    while (!queue.empty())
    {
      auto e = queue.front();
      queue.pop_front();
      curTime = e.time;
      e.process();
    }
  }
}
