#include <vector>

class Task
{
const float duration;
float progress;
const int device;
enum Type
{
CPU,IO
};
const Type type;
bool isDone(){return progress >= duration;}
Task(float dur,int dev,type t):duration(dur),progress(0.0f),device(dev),type(t){}
};

struct Job
{
std::vector<Task>::iterator cur;
std::vector<Task> tasks;
};
