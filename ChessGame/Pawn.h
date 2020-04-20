#pragma once
#include "Figure.h"

class Pawn: public Figure
{
private:
    bool isDoubleJumpAvailable;
public:
    Pawn(Color color, Position position);
    ~Pawn();

    bool isValidMove(Position position, Figure* figure) override;
    Figure* promote(Position position);
};

