#include "Maze.h"
#include <stdexcept>

#ifndef COMP_DIR_MAZE
#define COMP_DIR_MAZE

class CompressedDirectedMazeGraph : public Maze {
    private:
    static const short mask = 0b11;

    public:
    CompressedDirectedMazeGraph(int _size_x, int _size_y);

    CompressedDirectedMazeGraph(Maze & _maze);

    State get(int x, int y);

    void set(int x, int y, State v);

    void visualizeMaze();
};

#endif