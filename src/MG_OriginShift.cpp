#include "../headers/MG_OriginShift.h"
#include <cmath>

MG_OriginShift::MG_OriginShift(int x, int y) : MazeGenerator(x,y), maze(x,y) {
    steps = 4*x*y*pow(log(sqrt(x*y)),2)/M_PI;
    initializeMaze();
}

MG_OriginShift::~MG_OriginShift() {
}

void MG_OriginShift::initializeMaze() {
    x = size_x-1;
    y = size_y-1;
    for (int iy = 0; iy < size_y; iy++) {
        for (int ix = 0; ix < size_x; ix++) {
            maze.set(ix, iy, State::Right);
        }
        maze.set(size_x-1, iy, State::Down);
    }
}

void MG_OriginShift::generate_maze() {
    for (int i = 0; i < steps; i++) {
        makeGenerationStep();
        //if (!makeGenerationStep()) {i--;}
    }
}

bool MG_OriginShift::makeGenerationStep() {
    int r = std::rand() % 4;
    if (r == 0 && x < size_x-1) {
        // Move Right
        maze.set(x++, y, State::Right);
        maze.set(x, y, State::Left);
        return true;
    }
    else if (r == 1 && x > 0) {
        // Move Left
        maze.set(x--, y, State::Left);
        maze.set(x, y, State::Right);
        return true;
    }
    else if (r == 2 && y > 0) {
        // Move Up
        maze.set(x, y--, State::Up);
        maze.set(x, y, State::Down);
        return true;
    }
    else if (r == 3 && y < size_y-1) {
        // Move Down
        maze.set(x, y++, State::Down);
        maze.set(x, y, State::Up);
        return true;
    }
    else {
        return false;
    }
}

CompressedDirectedMazeGraph& MG_OriginShift::get_maze() {
    return maze;
}

CompressedMaze MG_OriginShift::get_normalized_maze() {
    CompressedMaze cmaze(maze);
    cmaze.normalize();
    return cmaze;
}