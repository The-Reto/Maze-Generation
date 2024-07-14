# Compiler
CC = g++ -std=c++2a

# Lib Flags
LF = -c
OPF = 

# Paths
LIBS_PATH = ./lib/
SRC_PATH = ./src/
H_PATH = ./headers/
EXEC_PATH = ./execs/

LIBS = $(LIBS_PATH)Maze.o $(LIBS_PATH)CompressedMaze.o $(LIBS_PATH)MG_OriginShift.o $(LIBS_PATH)CompressedDirectedMazeGraph.o

PRODUCTS = $(EXEC_PATH)main

default: Libs Products

clean:
	rm $(EXEC_PATH)* $(LIBS_PATH)*.o

Libs: $(LIBS)

Products: $(PRODUCTS)

$(LIBS_PATH)%.o: $(SRC_PATH)%.cpp $(H_PATH)%.h
	$(CC) $(LF) -o $@ $(OPF) $<


$(EXEC_PATH)%: $(SRC_PATH)%.cpp
	$(CC) -o $@ $(OPF) $+

# Dependency Chains
$(EXEC_PATH)main: $(LIBS_PATH)Maze.o $(LIBS_PATH)CompressedMaze.o $(LIBS_PATH)MG_OriginShift.o $(LIBS_PATH)CompressedDirectedMazeGraph.o