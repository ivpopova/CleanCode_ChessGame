#pragma once
#include "Figure.h"

class Square
{
private:
    Figure *chessPiece;

public:
    Square();
    virtual ~Square();

    Figure* getPiece();
    void setPiece(Figure *piece);
    void clear();
    void print();
};
