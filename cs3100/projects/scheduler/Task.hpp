#ifndef CS3100_SCHEDULER_TASK_HPP
#define CS3100_SCHEDULER_TASK_HPP

#include <vector>
namespace cs3100
{

  struct Task
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
      : duration(dur),
        progress(0.0f),
        completionTime(-1.0f),
        device(dev),
        type(t)
    {
    }
    Task(Task const& o) = default;
  };

  struct Job
  {
    Job(float, int, int);
    const float creationTime;
    unsigned int cur;
    std::vector<Task> tasks;
  };
}

#endif
