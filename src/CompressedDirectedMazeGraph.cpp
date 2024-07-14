#include "../headers/CompressedDirectedMazeGraph.h"
#include <bit>
#include <string.h>

CompressedDirectedMazeGraph::CompressedDirectedMazeGraph(int _size_x, int _size_y) : Maze(_size_x, _size_y, 4) {
}

CompressedDirectedMazeGraph::CompressedDirectedMazeGraph(Maze & _maze) : Maze(_maze.size_x, _maze.size_y, 4) {
    for (int y = 0; y < size_y; y++) {
        for (int x =  0; x < size_x; x++) {
            set(x, y, _maze.get(x,y));
        }
    }
}

State CompressedDirectedMazeGraph::get(int x, int y) {
    const static State staes[4] = {State::Right, State::Left, State::Down, State::Up};
    const int index = (x>>2) + (size_x>>2) * y, shift = 2 * (3 - (x%4));
    return staes[ (maze[index] >> shift) & mask ];
}

void CompressedDirectedMazeGraph::set(int x, int y, State v) {
    const int index = (x>>2) + (size_x>>2) * y, shift = 2 * (3 - (x%4));
    if (std::popcount((u_int8_t) v) > 1)
    {
        throw std::invalid_argument( "CompressedDirectedMazeGraph can only contain States: Right, Left, Down, Up" );
    }
    maze[index] = State( (maze[index] & ~(mask << shift)) | ((ffs(v)-1) << shift) );

}

void CompressedDirectedMazeGraph::visualizeMaze() {
    static const std::string pipes_out[4] = {"⮞","⮜","⮟","⮝"};
    int index, shift;
    for (int y = 0; y < size_y; y++) {
        for (int x =  0; x < size_x; x++) {
            std::cout << pipes_out[( maze[(x>>2) + (size_x>>2) * y] >> (2 * (3 - (x%4))) ) & mask];
        }
        std::cout << "\n";
    }
}