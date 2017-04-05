#include "FifoReadyQueue.hpp"

namespace cs3100
{
  void FifoReadyQueue::add(int x) { queue.push(x); }

  int FifoReadyQueue::next()
  {
    if (queue.empty()) return -1;
    auto result = queue.front();
    queue.pop();
    return result;
  }
}
