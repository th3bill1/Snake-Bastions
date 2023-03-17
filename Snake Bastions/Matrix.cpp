#include "Matrix.h"
#include <iostream>
using namespace std;
Matrix::Matrix(int _rows, int _columns, int* _cells) : rows(_rows), columns(_columns), cells(_cells) {}

void Matrix::init_cells(ifstream* input, Matrix m)
{
	Cell* cells = (Cell*)malloc(sizeof(Cell) * m.rows * m.columns);
	if (input->is_open() && cells)
	{

		for (int i = 0; i < m.rows; i++)
		{
			for (int j = 0; j < m.columns; j++)
			{
				char value;
				*input >> value;
				if (isdigit(value)) cells[to1d(i, j, m.columns)] = { i, j, (int)value - 48 };
				else cells[to1d(i, j, m.columns)] = { i, j, -1 };
			}
		}
		this->cells = (int*)cells;
	}
	else this->cells = nullptr;
}

void Matrix::print_cells()
{
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->columns; j++)
		{
			Cell* cell_pointer = (Cell*)this->cells;
			cell_pointer[to1d(i, j, this->columns)].print_value();
			cout << ' ';
		}
		cout << endl;
	}
}
