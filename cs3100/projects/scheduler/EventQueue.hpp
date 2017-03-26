#ifndef CS3100_SCHEDULER_EVENT_QUEUE_HPP
#define CS3100_SCHEDULER_EVENT_QUEUE_HPP

#include <memory>
#include <queue>

#include "Event.hpp"
namespace cs3100
{
  class EventQueue
  {
  public:
    static EventQueue& get();
    void add(std::unique_ptr<Event>);
    std::unique_ptr<Event> next();

  private:
    EventQueue();
    static std::unique_ptr<EventQueue> instance;
    std::priority_queue<Event> queue;
  };
}

#endif
