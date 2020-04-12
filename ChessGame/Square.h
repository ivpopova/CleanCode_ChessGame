#pragma once
#include "Figure.h"

class Square
{
private:
    Figure *chessFigure;

public:
    Square();
    virtual ~Square();

    Figure* getFigure();
    void setFigure(Figure *figure);
    void clear();
    void print();
};
