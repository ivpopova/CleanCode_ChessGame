#pragma once
#include "Bishop.h"

class King: public Figure
{
public:
    King(Color color, Position position);
    ~King();

    bool isValidMove(Position position, Figure* figure) override;
};
