struct Event
{
virtual void process() = 0;
float const time;
};

bool operator<(Event const & a,Event const & b)
{
return a.time < b.time;
}

