#pragma once
#include "Figure.h"

class Bishop : public virtual Figure {
public:
	Bishop(Color color, Position position);
	~Bishop();

	bool isValidMove(Position newPosition, Figure* figure) override;
};

