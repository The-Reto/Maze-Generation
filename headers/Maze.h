#include <iostream>

#ifndef MAZE
#define MAZE

enum State : std::uint8_t {
    Origin=0,
    Right,
    Left,
    LeftRight,
    Down,    
    DownRight,
    DownLeft,
    DownLeftRight,
    Up,
    UpRight,
    UpLeft,
    UpLeftRight,
    UpDown,
    UpDownRight,
    UpDownLeft,
    UpDownLeftRight
};

class Maze {
    public:
    const int size_x, size_y;

    protected:
    State* maze;
    Maze(int _size_x, int _size_y, int divisor);

    public:
    Maze(int _size_x, int _size_y);

    ~Maze();

    virtual State get(int x, int y);

    virtual void set(int x, int y, State val);

    void normalize();

    virtual void visualizeMaze();
};

#endif