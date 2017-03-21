struct Event
{
  std::function<void(void)> process;
float const time;
};

bool operator<(Event const & a,Event const & b)
{
return a.time < b.time;
}

