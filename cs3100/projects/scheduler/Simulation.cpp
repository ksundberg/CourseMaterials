#include "Simulation.hpp"
#include <random>

namespace
{
  float getFloat(float mean, float dev)
  {
    thread_local std::random_device rd;
    thread_local std::mt19937 mt(rd());
    std::normal_distribution<float> dist(mean, dev);
    return dist(mt);
  }
}

namespace cs3100
{

  void Simulation::createJob()
  {
    Job j(curTime, parameters.devices-1, parameters.cacheSize-1);
    jobs.push_back(j);
    ready->add(jobs.size() - 1);
    scheduleJob();
  }

  void Simulation::scheduleJob()
  {
    if (idleCpu == 0) return; // No idle cpu
    auto next = ready->next();
    if (next < 0) return; // No ready task
    // Allocate cpu
    --idleCpu;
    // Add cpu done event
    auto& task = jobs[next].tasks[jobs[next].cur];
    auto timeToFinish = task.duration - task.progress;
    auto timeAllocated = std::min(parameters.maximumTimeSlice, timeToFinish);
    auto jobDoneTime = curTime + timeAllocated + parameters.contextSwitchCost;
    // Check for page in cache
    auto page = task.device;
    if (!cache->in(page))
    {
      queue.push(Event([this, page] { cache->load(page); },
                       curTime + parameters.cacheMissCost));
      jobDoneTime += parameters.cacheMissCost;
    }

    queue.push(
      Event([this, next, timeAllocated] { jobDone(next, timeAllocated); },
            jobDoneTime));
  }

  void Simulation::scheduleIo(int job)
  {
    auto dev = jobs[job].tasks[jobs[job].cur].device;
    if (devices[dev].busy)
    {
      devices[dev].queue.add(job);
    }
    auto finishTime = jobs[job].tasks[jobs[job].cur].duration;
    queue.push(Event([this, job, finishTime]() { ioDone(job, finishTime); },
                     curTime + finishTime));
  }

  void Simulation::jobDone(int job, float time)
  {
    jobs[job].tasks[jobs[job].cur].progress += time;
    ++idleCpu;
    if (jobs[job].tasks[jobs[job].cur].progress <
        jobs[job].tasks[jobs[job].cur].duration)
    {
      ready->add(job);
    }
    else
    {
      jobs[job].tasks[jobs[job].cur].completionTime = curTime;
      jobs[job].cur += 1;
      if (jobs[job].cur < jobs[job].tasks.size())
      {
        if (jobs[job].tasks[jobs[job].cur].type == Task::Type::CPU)
        {
          ready->add(job);
        }
        else
        {
          scheduleIo(job);
        }
      }
    }
    scheduleJob();
  }

  void Simulation::ioDone(int job, float time)
  {
    auto dev = jobs[job].tasks[jobs[job].cur].device;
    devices[dev].busy = false;
    auto next = devices[dev].queue.next();
    if (next >= 0) scheduleIo(next);
    jobs[job].tasks[jobs[job].cur].progress += time;
    jobs[job].tasks[jobs[job].cur].completionTime = curTime;
    jobs[job].cur += 1;
    if (jobs[job].cur < jobs[job].tasks.size())
    {
      if (jobs[job].tasks[jobs[job].cur].type == Task::Type::CPU)
      {
        ready->add(job);
        scheduleJob();
      }
      else
      {
        scheduleIo(job);
      }
    }
  }

  void Simulation::run()
  {
    idleCpu = parameters.cpus;
    auto startTime = 0.0f;
    for (int i = 0; i < parameters.jobs; ++i)
    {
      queue.push(Event([this]() { createJob(); }, startTime));
      startTime += getFloat(
        parameters.meanTimeBetweenJobs, parameters.stddevTimeBetweenJobs);
    }
    while (!queue.empty())
    {
      auto&& e = queue.top();
      curTime = e.time;
      e.process();
      queue.pop();
    }
  }

  float Simulation::rawLatency(int)
  {
    // TODO Assignment 1: Fill out this calculation
    return 0.0f;
  }

  float Simulation::adjustedLatency(int job)
  {
    // start with raw latency
    auto adj = rawLatency(job);
    // remove latency time that is not due to scheduling
    for (auto&& t : jobs[job].tasks)
    {
      adj -= t.duration;
    }
    return adj;
  }

  float Simulation::rawResponseTime(int)
  {
    // TODO Assignment 1: Fill out this calculation
    return 0.0f;
  }

  float Simulation::adjustedResponseTime(int job)
  {
    // TODO Assignment 1 (optional): Fill out this calculation
    return rawResponseTime(job);
  }

  float Simulation::getEfficiency()
  {
    // TODO Assignment 1: Fill out this calculation
    return 0.0f;
  }
}
