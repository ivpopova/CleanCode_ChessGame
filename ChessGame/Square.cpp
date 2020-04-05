#include "Square.h"

Square::Square()
{
	figure = Figures::EMPTY;
	color = Colors::NONE;
}

void Square::setSpace(Square* space)
{
	color = space->getColor();
	figure = space->getFigure();
}

void Square::setEmpty()
{
	color = Colors::NONE;
	figure = Figures::EMPTY;
}

Figures Square::getFigure()
{
	return figure;
}

Colors Square::getColor()
{
	return color;
}

void Square::setFigureAndColor(Figures figure, Colors color)
{
	this->figure = figure;
	this->color = color;

}