#pragma once
#include"Colors.h"
#include"Figures.h"

class Square
{
private:

	Figures figure;
	Colors color;
	int x = -1;
	int y = -1;

public:

	void setSpace(Square*);
	void setEmpty();
	void setFigureAndColor(Figures, Colors);

	Figures getFigure();
	Colors getColor();

	void setX(int x) { this-> x = x; }
	void setY(int y) { this-> y = y; }
	int getX() { return x; }
	int getY() { return y; }

	Square();
};
