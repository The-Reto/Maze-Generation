#include <iostream>
#include <cmath>
#include <ctime>

class MazeGenerator {
    enum state {
        Origin,
        Right,
        Left,
        Down = 4,
        Up = 8
    };

    const int x_size,y_size;
    int x,y;
    state* board;

    public:
    MazeGenerator(int _x_size=16, int _y_size=16) : x_size(_x_size), y_size(_y_size) {
        board = new state[x_size*y_size];
        initializeMaze();
    }

    void initializeMaze() {
        x = x_size-1;
        y = y_size-1;
        for (int iy = 0; iy < y_size; iy++) {
            for (int ix = 0; ix < x_size-1; ix++) {
                board[ix+x_size*iy] = Right;
            }
            board[x_size-1+x_size*iy] = Down;
        }
    }

    void mazeGeneration(int steps) {
        for (int i = 0; i < steps; i++) {
            if (makeGenerationStep()) {}
            else {i--;}
        }
    }

    bool makeGenerationStep() {
        int r = std::rand() % 4;
        if (r == 0 && x < x_size-1) {
            // Move Right
            board[x+x_size*y] = Right;
            x++;
            return true;
        }
        else if (r == 1 && x > 0) {
            // Move Left
            board[x+x_size*y] = Left;
            x--;
            return true;
        }
        else if (r == 2 && y > 0) {
            // Move Up
            board[x+x_size*y] = Up;
            y--;
            return true;
        }
        else if (r == 3 && y < y_size-1) {
            // Move Down
            board[x+x_size*y] = Down;
            y++;
            return true;
        }
        else {
            return false;
        }
    }

    void visualizeDirectedTree(){
        static const std::string arrows_out[5] = {"e","⮞","⮜","⮟","⮝"};
        for (int i = 0; i < y_size; i++) {
            for (int j =  0; j < x_size; j++) {
                switch (board[j+x_size*i])
                {
                case Right:
                    std::cout << arrows_out[1];
                    break;
                case Left:
                    std::cout << arrows_out[2];
                    break;
                case Down:
                    std::cout << arrows_out[3];
                    break;
                case Up:
                    std::cout << arrows_out[4];
                    break;
                default:
                    std::cout << arrows_out[0];
                    break;
                }
            }
            std::cout << "\n";
        }
    }

        void visualizeMaze(){
        static const std::string pipes_out[16] = {"e","╞","╡","═","╥","╔","╗","╦", "╨","╚","╝","╩","║","╠","╣","╬"};
        for (int i = 0; i < y_size; i++) {
            for (int j =  0; j < x_size; j++) {
                short c = board[j+x_size*i]; // up,dwn,l,r

                // Incomming
                if (i < y_size-1 && board[j+x_size*(i+1)] == Up ) {c |= Down;}                    
                if (i > 0        && board[j+x_size*(i-1)] == Down ) {c |= Up;}
                if (j < x_size-1 && board[j+1+x_size*i]   == Left ) {c |= Right;}
                if (j > 0        && board[j-1+x_size*i]   == Right ) {c |= Left;}

                std::cout << pipes_out[c];
            }
            std::cout << "\n";
        }
    }
};



int main(int argc, char *argv[]){
    std::srand(std::time(nullptr));
    int x = 64, y = 32, steps = 4*x*y*pow(log(sqrt(x*y)),2)/M_PI;

    MazeGenerator gen(x, y);
    std::cout << "Generating...\n";
    gen.mazeGeneration(steps);
    std::cout << "Done!\n";
    gen.visualizeMaze();
    gen.visualizeDirectedTree();

}