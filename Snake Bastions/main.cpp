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
    input.open(file()); //Choosing input source file 
    ifstream* input_point = &input; //Pointer to ifstream is neccesary because you cannot copy of ifstream for a call of function
    input >> columns >> rows >> numberofSnakes;
    Matrix matrix = { rows, columns, nullptr }; //Initializing matrix
    Snake* snakes = init_snakes(input_point,numberofSnakes); //Reading snakes length from the file
    matrix.init_cells(input_point, matrix); //Reading cells from the file
    matrix.print_matrix(); //Printing matrix for safety
    if (input.is_open()) input.close(); //Closing the file
}