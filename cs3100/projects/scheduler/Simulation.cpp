#include <random>

namespace
{
int getInt(int low,int high)
{
thread_local std::random_device rd;
thread_local std::mt19937 mt(rd());
std::uniform_int_distribution<> dist(low,high);
return dist(mt);
}
}

int Simulation::createJob()
{
Job j;
j.tasks.resize(getInt(10,100));
std::generate(j.tasks.begin(),j.tasks.end(),[](){
return Task(getDuration(),getInt(0,devices),getType());});
j.cur = tasks.begin();
jobs.push_back(j);
return jobs.size();
}

void Simulation::scheduleJob()
{
  if(cpu == 0)return; //No idle cpu
  auto next = ready->next();
  if(next < 0)return; //No ready task
  //Allocate cpu
  --cpu;
  //Add cpu done event
  auto timeToFinish = jobs[next].cur->duration - jobs[next].cur->progress;
  auto timeAllocated = std::min(timeSlice,timeToFinish);
  queue.push_back(Event{[this]{jobDone(next,timeAllocated)},curTime+timeAllocated+contextSwitchPenalty});
}

void Simulation::jobDone(int job,float time)
{
  jobs[job].cur->progress += time;
  ++cpu;
  if(jobs[job].cur->progress < jobs[job].cur->duration)
  {
    ready.add(job);
  }
  else
  {
    ++(jobs[job].cur);
    if(jobs[job].cur != jobs[job].tasks.end())
    {
      //schedule io
    }
  }
  scheduleJob();

}
