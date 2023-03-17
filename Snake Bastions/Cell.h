#pragma once
#include <fstream>
#include "Matrix.h"
using namespace std;
class Cell {
private:
    int value; //-1 if hole
    int row;
    int column;
    bool hasSnake = 0;
public:
    Cell(int row, int column, int value);
    void print_value();
};

int to1d(int row, int column, int width);