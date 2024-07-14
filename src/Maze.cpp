#include "../headers/Maze.h"

Maze::Maze(int _size_x, int _size_y, int divisor)  : size_x(_size_x), size_y(_size_y) {
    maze = new State[size_x * size_y / divisor];
}

Maze::Maze(int _size_x, int _size_y)  : size_x(_size_x), size_y(_size_y) {
    maze = new State[size_x * size_y];
}

Maze::~Maze() {
    delete maze;
}

State Maze::get(int x, int y) {
    return maze[x + size_x * y];
}

void Maze::set(int x, int y, State val) {
    maze[x + size_x * y] = val;
}

void Maze::normalize() {
    for (int y = 0; y < size_y; y++) {
        for (int x =  0; x < size_x; x++) {
            if (x > 0        && ( (get(x-1,y) & State::Right) != 0) ) { set(x,y,State( get(x,y)|State::Left  ) ); }
            if (x < size_x-1 && ( (get(x+1,y) & State::Left ) != 0) ) { set(x,y,State( get(x,y)|State::Right ) ); }
            if (y > 0        && ( (get(x,y-1) & State::Down ) != 0) ) { set(x,y,State( get(x,y)|State::Up    ) ); }
            if (y < size_y-1 && ( (get(x,y+1) & State::Up   ) != 0) ) { set(x,y,State( get(x,y)|State::Down  ) ); }
        }
    }
}

void Maze::visualizeMaze(){
    static const std::string pipes_out[16] = {"e","╞","╡","═","╥","╔","╗","╦", "╨","╚","╝","╩","║","╠","╣","╬"};
    for (int y = 0; y < size_y; y++) {
        for (int x =  0; x < size_x; x++) {
            std::cout << pipes_out[get(x,y)];
        }
        std::cout << "\n";
    }
}