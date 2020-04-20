#pragma once

class Position {
private:
	int xPosition = -1;
	int yPosition = -1;

public:
	void setX(int xPosition);
	void setY(int yPosition);

	int getX()const;
	int getY()const;

	Position();
	Position(int xPosition, int yPosition);
	~Position();
};