#pragma once
#include "Cell.h"

using namespace std;

class Matrix {  
public:
    int rows;
    int columns;
    int* cells;
    Matrix(int rows = 0, int columns = 0, int* cells = nullptr);
    void init_cells(ifstream* input, Matrix m);
    void print_matrix();
};



