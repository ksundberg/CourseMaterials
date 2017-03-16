#include <vector>

class Task
{
float duration;
float progress;
int device;
enum Type
{
CPU,IO
};
Type type;
bool isDone(){return progress >= duration;}
};

struct Job
{
std::vector<Task>::iterator cur;
std::vector<Task> tasks;
};
