#pragma once
#include "Bishop.h"

class King: public Figure
{
public:
    King(Color color, Position position);
    ~King();

    bool isValidMove(Position moveToPosition, Figure* figure);
};
