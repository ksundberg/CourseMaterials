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
