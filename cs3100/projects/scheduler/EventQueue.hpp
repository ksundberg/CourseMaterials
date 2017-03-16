#include <queue>
#include <memory>

#include "Event.hpp"

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
}
