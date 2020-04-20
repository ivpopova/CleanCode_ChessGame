#include "Position.h"

void Position::setX(int xPosition)
{
	this->xPosition = xPosition;
}

void Position::setY(int yPosition)
{
	this->yPosition = yPosition;
}

int Position::getX() const
{
	return this->xPosition;
}

int Position::getY() const
{
	return this->yPosition;
}

Position::Position()
{
	setX(-1);
	setY(-1);
}

Position::Position(int xPosition, int yPosition)
{
	setX(xPosition);
	setY(yPosition);
}

Position::~Position()
{
}
