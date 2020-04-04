#include "Square.h"

Square::Square()
{
	figure = EMPTY;
	color = NONE;
}

void Square::setSpace(Square* space)
{
	color = space->getColor();
	figure = space->getFigure();
}

void Square::setEmpty()
{
	color = NONE;
	figure = EMPTY;
}

Figures Square::getFigure()
{
	return figure;
}

Colors Square::getColor()
{
	return color;
}

void Square::setPieceAndColor(Figures p, Colors c)
{
	figure = p;
	color = c;

}