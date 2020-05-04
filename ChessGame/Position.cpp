#include "Position.h"

void Position::setCoordinateX(int xCoordinate) {
	this->xCoordinate = xCoordinate;
}

void Position::setCoordinateY(int yCoordinate) {
	this->yCoordinate = yCoordinate;
}

int Position::getCoordinateX() const {
	return this->xCoordinate;
}

int Position::getCoordinateY() const {
	return this->yCoordinate;
}

Position::Position() {
	setCoordinateX(-1);
	setCoordinateY(-1);
}

Position::Position(int xPosition, int yPosition) {
	setCoordinateX(xPosition);
	setCoordinateY(yPosition);
}

Position::~Position() {
}
