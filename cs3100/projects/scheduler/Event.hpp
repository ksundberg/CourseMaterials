#ifndef CS3100_SCHEDULER_EVENT_HPP
#define CS3100_SCHEDULER_EVENT_HPP
namespace cs3100
{

  struct Event
  {
    Event(std::function<void(void)> p, float t) : process(p), time(t) {}
    std::function<void(void)> process;
    float const time;
  };

  bool operator<(Event const& a, Event const& b) { return a.time < b.time; }
}
#endif
