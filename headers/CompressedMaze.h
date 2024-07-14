#include "Maze.h"

#ifndef COMP_MAZE
#define COMP_MAZE

class CompressedMaze : public Maze {
    private:
    static const short mask = 0b1111;

    public:
    CompressedMaze(int _size_x, int _size_y);

    CompressedMaze(Maze & _maze);

    State get(int x, int y);

    void set(int x, int y, State v);
};

#endif