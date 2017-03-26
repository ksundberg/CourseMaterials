#include "ReadyQueue.hpp"
#include <queue>
namespace cs3100
{

  class ShortestJobFirstReadyQueue : public ReadyQueue
  {
    void add(int) override;
    int next() override;

  private:
    std::queue<int> queue;
  };
}
