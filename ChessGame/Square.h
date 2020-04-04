#pragma once
#include"Colors.h"
#include"Figures.h"
class Square
{

	Figures figure;
	Colors color;
	int x, y;
public:
	void setSpace(Square*);
	void setEmpty();
	void setPieceAndColor(Figures, Colors);
	Figures getFigure();
	Colors getColor();
	void setX(int ex) { x = ex; }
	void setY(int why) { y = why; }
	int getX() { return x; }
	int getY() { return y; }
	Square();
};
