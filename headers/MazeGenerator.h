#include "Maze.h"
#include "CompressedMaze.h"

#ifndef MAZE_GEN
#define MAZE_GEN

class MazeGenerator {
    protected:
    const int size_x, size_y;

    public:
    MazeGenerator(int x, int y) : size_x(x), size_y(y) {};

    virtual ~MazeGenerator() {};

    virtual void generate_maze() = 0;

    virtual Maze& get_maze() = 0;
};

#endif