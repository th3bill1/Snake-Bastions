#include <iostream>
#include <fstream>
#include "Snake.h"

using namespace std;

Snake::Snake(int _maxLength) : maxLength(_maxLength){}

void Snake::collectPoints(Cell cell)
{
    cout << endl << cell.value << endl;
    if (cell.value == -1) this->teleport(cell);
    else this->points += cell.value;
}

void Snake::move(Direction d, Matrix m)
{
    if (this->currentLength != this->maxLength)
    {
        if (d == LEFT)
        {
            this->currentColumn--;
            if (this->currentColumn == -1) this->currentColumn = m.columns - 1;
        }
        if (d == UP)
        {
            this->currentRow--;
            if (this->currentRow == -1) this->currentRow = m.rows - 1;
        }
        if (d == RIGHT)
        {
            this->currentColumn++;
            if (this->currentColumn == m.columns) this->currentColumn = 0;
        }
        if (d == DOWN)
        {
            this->currentRow++;
            if (this->currentRow == m.rows) this->currentRow = 0;
        }
        this->currentLength++;
        Cell* new_cell = (Cell*)m.cells;
        this->collectPoints(get_snakes_cell(*this,m));
    }
}

void Snake::teleport(Cell hole)
{
    if (this->currentLength != this->maxLength)
    {
        this->currentColumn = hole.column;
        this->currentRow = hole.row;
    }
}

void Snake::set_starting_pos(int row, int column, Matrix m)
{
    if (row >= 0 && row < m.rows && column >= 0 && column < m.columns)
    {
        this->currentRow = row;
        this->currentColumn = column;
        this->collectPoints(get_snakes_cell(*this, m));
    }
}

Snake* init_snakes(ifstream* input, int num_of_snakes)
{
    if (num_of_snakes > 0 && (input->is_open()))
    {
        Snake* snakes = (Snake*)malloc(sizeof(Snake) * (num_of_snakes));
        if (snakes)
        {
            for (int i = 0; i < num_of_snakes; i++)
            {
                int value;
                *input >> value;
                snakes[i] = { value };
            }
        }
        return snakes;
    }
    return nullptr;
}

void print_snakes(Snake* snakes, int numberofSnakes)
{
    for (int i = 0; i < numberofSnakes; i++)
    {
        cout << snakes[i].maxLength << ' ';
    }
}

Cell get_snakes_cell(Snake s, Matrix m)
{
    Cell* new_cell = (Cell*)m.cells;
    return new_cell[to1d(s.currentRow, s.currentColumn, m.columns)];
}
