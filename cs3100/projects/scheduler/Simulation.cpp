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
    Job j(curTime,parameters.devices,parameters.cacheSize);
    jobs.push_back(j);
    ready->add(jobs.size());
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
    auto timeToFinish = jobs[next].cur->duration - jobs[next].cur->progress;
    auto timeAllocated = std::min(parameters.maximumTimeSlice, timeToFinish);
    queue.push(
      Event([this, next, timeAllocated] { jobDone(next, timeAllocated); },
            curTime + timeAllocated + parameters.contextSwitchCost));
  }

  void Simulation::scheduleIo(int job)
  {
    auto dev = jobs[job].cur->device;
    if (devices[dev].busy)
    {
      devices[dev].queue.add(job);
    }
    auto finishTime = jobs[job].cur->duration;
    queue.push(
      Event([this,job,finishTime]() { ioDone(job, finishTime); }, curTime + finishTime));
  }

  void Simulation::jobDone(int job, float time)
  {
    jobs[job].cur->progress += time;
    ++idleCpu;
    if (jobs[job].cur->progress < jobs[job].cur->duration)
    {
      ready->add(job);
    }
    else
    {
      ++(jobs[job].cur);
      if (jobs[job].cur != jobs[job].tasks.end())
      {
        if (jobs[job].cur->type == Task::Type::CPU)
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
    auto dev = jobs[job].cur->device;
    devices[dev].busy = false;
    auto next = devices[dev].queue.next();
    if (next >= 0) scheduleIo(next);
    jobs[job].cur->progress += time;
    ++(jobs[job].cur);
    if (jobs[job].cur != jobs[job].tasks.end())
    {
      if (jobs[job].cur->type == Task::Type::CPU)
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
    //TODO Assignment 1: Fill out this calculation
    return 0.0f;
  }
  
  float Simulation::adjustedLatency(int job)
  {
    //start with raw latency
    auto adj = rawLatency(job);
    //remove latency time that is not due to scheduling
    for(auto&& t:jobs[job].tasks)
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

