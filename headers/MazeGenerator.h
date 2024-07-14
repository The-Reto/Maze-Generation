#include "Maze.h"
#include "CompressedMaze.h"

#ifndef MAZE_GEN
#define MAZE_GEN

class MazeGenerator {
    const int size_x, size_y;
    int x,y;
    Maze maze;

    public:
    MazeGenerator(int x, int y);

    ~MazeGenerator();

    void initializeMaze();

    void mazeGeneration(int steps);

    bool makeGenerationStep();

    Maze& get_maze();

    CompressedMaze get_compressed_maze();
};

#endif