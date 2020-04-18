#include "Position.h"

void Position::setPositionX(int xPosition)
{
	this->xPosition = xPosition;
}

void Position::setPositionY(int yPosition)
{
	this->yPosition = yPosition;
}

int Position::getPositionX() const
{
	return this->xPosition;
}

int Position::getPositionY() const
{
	return this->yPosition;
}

Position::Position()
{
	setPositionX(-1);
	setPositionY(-1);
}

Position::Position(int xPosition, int yPosition)
{
	setPositionX(xPosition);
	setPositionY(yPosition);
}

Position::~Position()
{
}
