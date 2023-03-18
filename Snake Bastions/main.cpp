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
    ifstream* input_point = &input; //Pointer to ifstream is neccesary because you cannot copy ifstream for a call of function
    input >> columns >> rows >> numberofSnakes;
    cout << columns << ' ' << rows << ' ' << numberofSnakes << endl;
    Matrix matrix = { rows, columns, nullptr }; //Initializing matrix
    Snake* snakes = init_snakes(input_point,numberofSnakes); //Reading snakes length from the file
    print_snakes(snakes, numberofSnakes); // Printing snakes to check if read correctly
    cout << endl;
    matrix.init_cells(input_point, matrix); //Reading cells from the file
    matrix.print_matrix(); //Printing matrix to check if read correctly
    cout << endl << endl << endl;
    input.close();
    //Test if it walks (spoiler: yes it does)
    snakes[1].set_starting_pos(0, 5, matrix);
    for (int i = 0; i < 10; i++)
    {
        snakes[1].move(UP, matrix);
    }   
    cout << snakes[1].points;
}