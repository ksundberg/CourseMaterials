#ifndef CS3100_SCHEDULER_TASK_HPP
#define CS3100_SCHEDULER_TASK_HPP

#include <vector>
namespace cs3100
{

  class Task
  {
    const float duration;
    float progress;
    float completionTime;
    const int device;
    enum Type
    {
      CPU,
      IO
    };
    const Type type;
    bool isDone() { return progress >= duration; }
    Task(float dur, int dev, Type t)
      : duration(dur), progress(0.0f), device(dev), type(t)
    {
    }
  };

  struct Job
  {
    const float creationTime;
    std::vector<Task>::iterator cur;
    std::vector<Task> tasks;
  };
}

#endif
