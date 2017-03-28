#ifndef CS3100_SCHEDULER_FIFO_READY_QUEUE_HPP
#define CS3100_SCHEDULER_FIFO_READY_QUEUE_HPP

#include "ReadyQueue.hpp"
#include <queue>

namespace cs3100
{

  class FifoReadyQueue : public ReadyQueue
  {
  public:
    void add(int) override;
    int next() override;

  private:
    std::queue<int> queue;
  };
}

#endif
