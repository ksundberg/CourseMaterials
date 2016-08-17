#ifndef CS1410_MAZE_HPP
#define CS1410_MAZE_HPP

#include <string>
#include <vector>

class Maze
{
  public:
    Maze();
    void read(std::string filename);
    void solve();
    void display();
  private:
    enum MazeCell
    {
      WALL,
      VISITED,
      EMPTY,
      ON_PATH,
      START,
      END
    };
    std::vector<std::vector<MazeCell>> cells;
    void display(MazeCell);
};

#endif

