#ifndef CS3100_SCHEDULER_READY_QUEUE_HPP
#define CS3100_SCHEDULER_READY_QUEUE_HPP
namespace cs3100
{
  class ReadyQueue
  {
  public:
    ReadyQueue(){}
    virtual void add(int) = 0;
    virtual int next() = 0;
  };
}
#endif
