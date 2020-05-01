#pragma once
#include "Figure.h"
#include "Rook.h"
#include "Bishop.h"

class Queen: public virtual Figure , public Bishop, public Rook {
public:
    Queen(Color color, Position position);
    ~Queen();

    bool isValidMove(Position newPosition, Figure* figure) override;
};

