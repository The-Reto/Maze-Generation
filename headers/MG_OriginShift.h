#include "MazeGenerator.h"
#include "CompressedDirectedMazeGraph.h"

#ifndef MG_OS
#define MG_OS

class MG_OriginShift : public MazeGenerator {
    int x,y,steps;
    CompressedDirectedMazeGraph maze;

    public:
    MG_OriginShift(int x, int y);

    ~MG_OriginShift();

    void initializeMaze();

    void generate_maze();

    bool makeGenerationStep();

    CompressedDirectedMazeGraph& get_maze();

    CompressedMaze get_normalized_maze();
};

#endif