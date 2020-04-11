#pragma once
#include "Figure.h"

class Rook: public virtual Figure
{
public:
    Rook(Color color, Position pos);
    ~Rook();

    bool validateMove(Position moveToPosition, Figure* piece);
};
