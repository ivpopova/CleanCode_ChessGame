#pragma once

class Position {
public:
	Position();
	Position(int xCoordinate, int yCoordinate);
	~Position();

	void setCoordinateX(int xCoordinate);
	void setCoordinateY(int yCoordinate);

	int getCoordinateX()const;
	int getCoordinateY()const;

private:
	int xCoordinate = -1;
	int yCoordinate = -1;
};