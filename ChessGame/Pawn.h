#pragma once
#include "Figure.h"

class Pawn: public Figure
{
private:
    bool doubleJumpAvailable;
public:
    Pawn(Color color, Position pos);
    ~Pawn();

    bool validateMove(Position moveToPosition, Figure* piece);
    Figure* promote(Position position);
};

