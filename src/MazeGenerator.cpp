#include "../headers/MazeGenerator.h"

MazeGenerator::MazeGenerator(int x, int y) : maze(x, y), size_x(x), size_y(y) {
    initializeMaze();
}

MazeGenerator::~MazeGenerator() {
}

void MazeGenerator::initializeMaze() {
    x = size_x-1;
    y = size_y-1;
    for (int iy = 0; iy < size_y; iy++) {
        for (int ix = 0; ix < size_x-1; ix++) {
            maze.set(ix, iy, State::Right);
        }
        maze.set(size_x-1, iy, State::Down);
    }
    maze.set(x, y, State::Origin);
}

void MazeGenerator::mazeGeneration(int steps) {
    for (int i = 0; i < steps; i++) {
        if (!makeGenerationStep()) {i--;}
    }
    maze.normalize();
}

bool MazeGenerator::makeGenerationStep() {
    int r = std::rand() % 4;
    if (r == 0 && x < size_x-1) {
        // Move Right
        maze.set(x, y, State::Right);
        x++;
        maze.set(x, y, State::Origin);
        return true;
    }
    else if (r == 1 && x > 0) {
        // Move Left
        maze.set(x, y, State::Left);
        x--;
        maze.set(x, y, State::Origin);
        return true;
    }
    else if (r == 2 && y > 0) {
        // Move Up
        maze.set(x, y, State::Up);
        y--;
        maze.set(x, y, State::Origin);
        return true;
    }
    else if (r == 3 && y < size_y-1) {
        // Move Down
        maze.set(x, y, State::Down);
        y++;
        maze.set(x, y, State::Origin);
        return true;
    }
    else {
        return false;
    }
}

Maze& MazeGenerator::get_maze() {
    return maze;
}

CompressedMaze MazeGenerator::get_compressed_maze() {
    return CompressedMaze(maze);
}