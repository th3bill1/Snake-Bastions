#include <iostream>
#include <fstream>
#include <string>
#include "Matrix.h"
#include "Snake.h"
#include "Menu.h"

using namespace std;

void main(int argc, const char* argv[]) {
    int rows, columns, numberofSnakes;

    ifstream input;
    input.open(file());
    ifstream* input_point = &input;
    input >> columns >> rows >> numberofSnakes;
    Matrix matrix = { rows, columns, nullptr };
    Snake* snakes = init_snakes(input_point,numberofSnakes);
    matrix.init_cells(input_point, matrix);
    matrix.print_cells();
    if (input.is_open()) input.close();
}