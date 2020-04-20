#pragma once
#include "Figure.h"

class Square
{
private:
    Figure *chessFigure=nullptr;

public:
    Square();
    virtual ~Square();

    Figure* getFigure() const;
    void setFigure(Figure* figure);
    void clearFigure();
    void print();
};
