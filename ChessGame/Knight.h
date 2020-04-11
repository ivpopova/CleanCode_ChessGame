#pragma once
#include "Figure.h"

class Knight: public Figure
{
public:

    Knight(Color color, Position pos);
    ~Knight();

    bool validateMove(Position moveToPosition, Figure* piece);
};

