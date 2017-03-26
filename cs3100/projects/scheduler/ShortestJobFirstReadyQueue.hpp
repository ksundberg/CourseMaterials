#include "ReadyQueue.hpp"
#include <queue>

class ShortestJobFirstReadyQueue : public ReadyQueue
{
  void add(int) override;
  int next() override;

private:
  std::queue<int> queue;
};
