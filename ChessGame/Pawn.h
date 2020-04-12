#pragma once
#include "Figure.h"

class Pawn: public Figure
{
private:
    bool doubleJumpAvailable;
public:
    Pawn(Color color, Position position);
    ~Pawn();

    bool isValidMove(Position moveToPosition, Figure* figure);
    Figure* promote(Position position);
};

