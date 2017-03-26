#ifndef CS3100_SCHEDULER_READY_QUEUE_HPP
#define CS3100_SCHEDULER_READY_QUEUE_HPP
namespace cs3100
{
  class ReadyQueue
  {
  public:
    ReadyQueue();
    void add(int) = 0;
    int next() = 0;
  }
}
#endif
