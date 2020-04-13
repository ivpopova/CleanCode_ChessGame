#include "Square.h"
#include "Figure.h"

Square::Square()
{
    chessFigure = nullptr;
}

Square::~Square()
{ }

Figure* Square::getFigure() const
{
    return chessFigure;
}


void Square::setFigure(Figure* figure)
{
    this->chessFigure = figure;
}


void Square::clearFigure()
{
    this->chessFigure = nullptr;
}

void Square::print()
{
    chessFigure->print();
}
