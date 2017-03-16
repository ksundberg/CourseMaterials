#include <iostream>
#include "EventQueue.hpp"

int main(int argc,char**argv)
{
  auto plan = parse(argc,argv);

//We really do mean assignment here
  while((auto cur = EventQueue::get().next()))
  {
    cur->process();
  }
}
