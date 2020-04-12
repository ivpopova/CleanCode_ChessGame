#pragma once
#include "Figure.h"

class Knight: public Figure
{
public:

    Knight(Color color, Position position);
    ~Knight();

    bool isValidMove(Position moveToPosition, Figure* figure);
};

