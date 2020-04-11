#pragma once
#include "Figure.h"

class Bishop: public virtual Figure
{
public:
    Bishop(Color color, Position pos);
    ~Bishop();

    bool validateMove(Position moveToPosition, Figure* piece);
};

