#pragma once
#include "Figure.h"

class Square {
public:
    Square();
    virtual ~Square();
   
    Figure* getFigure() const;
    void setFigure(Figure* figure);

    void clearFigure();
    void print();
private:
    Figure* figure = nullptr;
};
