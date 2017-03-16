#include "EventQueue.hpp"

EventQueue& EventQueue::get()
{
if(!m_instance) m_instance = std::unique_ptr<EventQueue>(new EventQueue());
return *m_instance;
}
