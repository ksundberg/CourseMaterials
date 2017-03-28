#ifndef CS3100_SCHEDULER_TASK_HPP
#define CS3100_SCHEDULER_TASK_HPP

#include <vector>
namespace cs3100
{

  struct Task
  {
    float duration;
    float progress;
    float completionTime;
    int device;
    enum Type
    {
      CPU,
      IO
    };
    Type type;
    bool isDone() { return progress >= duration; }
    Task(float dur, int dev, Type t)
      : duration(dur), progress(0.0f), device(dev), type(t)
    {
    }
  };

  struct Job
  {
    Job(float, int, int);
    const float creationTime;
    std::vector<Task>::iterator cur;
    std::vector<Task> tasks;
  };
}

#endif
