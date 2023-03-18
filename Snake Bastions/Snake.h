#pragma once
#include "Cell.h"
#include "Matrix.h"
#include <fstream>

enum Direction { LEFT, UP, RIGHT, DOWN };

using namespace std;
class Snake {
public:
    int maxLength;
    int points = 0;
    int currentRow = -1;
    int currentColumn = -1;
    int currentLength = 1;
    Snake(int maxLength = 0);
    void collectPoints(Cell cell);
    void move(Direction d, Matrix m);
    void teleport(Cell hole);
    void set_starting_pos(int row, int column, Matrix m);
};
Snake* init_snakes(ifstream* input, int num_of_snakes = 0);
void print_snakes(Snake* snakes, int numberofSnakes);
Cell get_snakes_cell(Snake, Matrix);