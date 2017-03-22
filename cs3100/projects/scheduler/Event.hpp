struct Event
{
  Event(std::function<void(void)>p,float t):process(p),time(t){}
  std::function<void(void)> process;
float const time;
};

bool operator<(Event const & a,Event const & b)
{
return a.time < b.time;
}

