#include "EventQueue.hpp"
namespace cs3100
{
  EventQueue& EventQueue::get()
  {
    if (!instance) instance = std::unique_ptr<EventQueue>(new EventQueue());
    return *instance;
  }
}
