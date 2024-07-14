#include <ctime>
#include <iostream>
#include "../headers/MG_OriginShift.h"
#include <string.h>



int main(int argc, char *argv[]){
    std::srand(std::time(nullptr));
    const int x = 64, y = 32;

    MG_OriginShift gen(x,y);

    std::cout << "Init Maze:" << std::endl;
    gen.get_maze().visualizeMaze();
    std::cout << std::endl;

    gen.generate_maze();
    std::cout << "Maze:" << std::endl;
    gen.get_maze().visualizeMaze();
    std::cout << std::endl;

    std::cout << "\nNormalized Maze:" << std::endl;
    gen.get_normalized_maze().visualizeMaze();
}