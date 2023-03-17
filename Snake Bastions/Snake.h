#pragma once
#include "Cell.h"
#include <fstream>

enum Direction { LEFT, UP, RIGHT, DOWN };

using namespace std;
class Snake {
private:
    int maxLength;
    int points = 0;
    int currentRow = -1;
    int currentColumn = -1;
    int currentLength = 1;
public:
    Snake(int maxLength = 0);
    void collectPoints(Cell cell);
    void move(Direction d);
    void teleport(Cell hole);
};
Snake* init_snakes(ifstream* input, int num_of_snakes = 0);