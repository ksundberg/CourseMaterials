void FifoReadyQueue::add(int x)
{
  queue.push_back(x);
}

int FifoReadyQueue::next()
{
  auto result = queue.front();
  queue.pop_front();
  return result;
}
