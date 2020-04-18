#pragma once
class Position {
private:
	int xPosition = -1;
	int yPosition = -1;
public:
	void setPositionX(int xPosition);
	void setPositionY(int yPosition);

	int getPositionX()const;
	int getPositionY()const;

	Position();
	Position(int xPosition, int yPosition);
	~Position();
};