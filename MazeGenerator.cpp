#include <iostream>
#include <cmath>
#include <ctime>

class MazeGenerator {
    const int x_size,y_size;
    int x,y;
    char* board;

    public:
    MazeGenerator(int _x_size=16, int _y_size=16) : x_size(_x_size), y_size(_y_size) {
        board = new char[x_size*y_size];
        initializeMaze();
    }

    void initializeMaze() {
        x = x_size-1;
        y = y_size-1;
        for (int iy = 0; iy < y_size; iy++) {
            for (int ix = 0; ix < x_size-1; ix++) {
                board[ix+x_size*iy] = 'R';
            }
            board[x_size-1+x_size*iy] = 'D';
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
            board[x+x_size*y] = 'R';
            x++;
            return true;
        }
        else if (r == 1 && x > 0) {
            // Move Left
            board[x+x_size*y] = 'L';
            x--;
            return true;
        }
        else if (r == 2 && y > 0) {
            // Move Up
            board[x+x_size*y] = 'U';
            y--;
            return true;
        }
        else if (r == 3 && y < y_size-1) {
            // Move Down
            board[x+x_size*y] = 'D';
            y++;
            return true;
        }
        else {
            return false;
        }
    }

    void visualizeDirectedTree(){
        for (int i = 0; i < y_size; i++) {
            for (int j =  0; j < x_size; j++) {

                // Outgoing
                if      ( board[j+x_size*i] == 'R' ) { std::cout << "⮞"; }
                else if ( board[j+x_size*i] == 'L' ) { std::cout << "⮜"; }
                else if ( board[j+x_size*i] == 'D' ) { std::cout << "⮟"; }
                else if ( board[j+x_size*i] == 'U' ) { std::cout << "⮝"; }
            }
            std::cout << "\n";
        }
    }

        void visualizeMaze(){
        static const std::string out[16] = {"e","═","═","═","║","╔","╗","╦", "║","╚","╝","╩","║","╠","╣","╬"};
        for (int i = 0; i < y_size; i++) {
            for (int j =  0; j < x_size; j++) {
                short c = 0; // up,dwn,l,r

                // Outgoing
                if      ( board[j+x_size*i] == 'R' ) { c |= 1; }
                else if ( board[j+x_size*i] == 'L' ) { c |= 2; }
                else if ( board[j+x_size*i] == 'D' ) { c |= 4; }
                else if ( board[j+x_size*i] == 'U' ) { c |= 8; }

                // Incomming
                if (i < y_size-1 && board[j+x_size*(i+1)] == 'U' ) {c |= 4;}                    
                if (i > 0        && board[j+x_size*(i-1)] == 'D' ) {c |= 8;}
                if (j < x_size-1 && board[j+1+x_size*i]   == 'L' ) {c |= 1;}
                if (j > 0        && board[j-1+x_size*i]   == 'R' ) {c |= 2;}

                std::cout << out[c];
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