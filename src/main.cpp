#include <ctime>
#include <cmath>
#include <iostream>
#include "../headers/MazeGenerator.h"


int main(int argc, char *argv[]){
    std::srand(std::time(nullptr));
    const int x = 64, y = 32, steps = 4*x*y*pow(log(sqrt(x*y)),2)/M_PI;

    MazeGenerator gen(x,y);
    gen.mazeGeneration(steps);
    std::cout << "Maze:" << std::endl;
    gen.get_maze().visualizeMaze();

    std::cout << "\nCompressed Maze:" << std::endl;
    gen.get_compressed_maze().visualizeMaze();
}