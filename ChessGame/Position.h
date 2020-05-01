#pragma once

class Position {
public:
	Position();
	Position(int xPosition, int yPosition);
	~Position();

	void setPositionX(int xPosition);
	void setPositionY(int yPosition);

	int getPositionX()const;
	int getPositionY()const;

private:
	int xPosition = -1;
	int yPosition = -1;
};