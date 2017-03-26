#ifndef CS3100_SCHEDULER_CACHE_ALGORITHM_HPP
#define CS3100_SCHEDULER_CACHE_ALGORITHM_HPP
namespace cs3100
{
  class CacheAlgorithm
  {
  public:
    CacheAlgorithm();
    bool in(int) = 0;
    void load(int) = 0;
  };
}
#endif
