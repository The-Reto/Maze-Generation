#include "../headers/CompressedMaze.h"

CompressedMaze::CompressedMaze(int _size_x, int _size_y) : Maze(_size_x, _size_y, 2) {
}

CompressedMaze::CompressedMaze(Maze & _maze) : Maze(_maze.size_x, _maze.size_y, 2) {
    for (int y = 0; y < size_y; y++) {
        for (int x =  0; x < size_x; x++) {
            set(x, y, _maze.get(x,y));
        }
    }
}

State CompressedMaze::get(int x, int y)  {
    const int index = x/2 + size_x/2 * y;
    if (x % 2) {
         return State(maze[index] & mask);
    }
    return State(maze[index] >> 4);
}

void CompressedMaze::set(int x, int y, State v)  {
    const int index = x/2 + size_x/2 * y;
    if (x % 2) {
        maze[index] = State( (maze[index] & (mask<<4)) | v );
    }
    else {
        maze[index] = State( (maze[index] & mask) | (v<<4) );
    }
}
