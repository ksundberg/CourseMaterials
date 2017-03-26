#include "FifoReadyQueue.hpp"

namespace cs3100
{
  void FifoReadyQueue::add(int x) { queue.push(x); }

  int FifoReadyQueue::next()
  {
    auto result = queue.front();
    queue.pop();
    return result;
  }
}
