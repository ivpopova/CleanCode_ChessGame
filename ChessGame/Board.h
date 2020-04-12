#pragma once
#include "Square.h"

class Board
{
private:
    Square board[8][8];

    void initializeFigures();
    bool isWithinBoard(Position position);

public:
    Board();
    virtual ~Board();

    void print();
    bool moveFigure(Position fromPosition, Position toPosition);
    void changeFigure(Position position, Figure* figure);
    Figure* getFigure(Position figurePosition);
};

