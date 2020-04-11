#pragma once
#include "Bishop.h"

class King: public Figure
{
public:
    King(Color color, Position pos);
    ~King();

    bool validateMove(Position moveToPosition, Figure* piece);
};
