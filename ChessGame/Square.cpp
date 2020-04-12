#include "Square.h"
#include "Figure.h"

Square::Square()
{
    chessFigure = nullptr;
}

Square::~Square()
{ }

Figure* Square::getFigure()
{
    return chessFigure;
}


void Square::setFigure(Figure* figure)
{
    this->chessFigure = figure;
}


void Square::clear()
{
    this->chessFigure = nullptr;
}

void Square::print()
{
    chessFigure->print();
}
