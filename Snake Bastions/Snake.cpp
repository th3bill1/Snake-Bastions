#include <iostream>
#include <fstream>
#include "Snake.h"

using namespace std;

Snake::Snake(int _maxLength) : maxLength(_maxLength){}

void Snake::collectPoints(Cell cell)
{
}

void Snake::move(Direction d)
{
}

void Snake::teleport(Cell hole)
{
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
