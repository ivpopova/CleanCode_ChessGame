#pragma once
#include "Figure.h"

class Rook: public virtual Figure
{
public:
    Rook(Color color, Position position);
    ~Rook();

    bool isValidMove(Position moveToPosition, Figure* figure);
};
