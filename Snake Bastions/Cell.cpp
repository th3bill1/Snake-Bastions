#include <iostream>
#include "Cell.h"
#include "Matrix.h"
#include <fstream>

using namespace std;

Cell::Cell(int _row, int _column, int _value) : row(_row), column(_column), value(_value){}

void Cell::print_value()
{
	if (this->value < 0) cout << '*';
	else cout << this->value;
}

int to1d(int row, int column, int width)
{
	return width*row+column;
}