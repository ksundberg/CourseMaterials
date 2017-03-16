#include "ReadyQueue.hpp"
#include <queue>

class FifoReadyQueue: public ReadyQueue
{
void add(int) override;
int next() override;
private:
std::queue<int> queue;
};
