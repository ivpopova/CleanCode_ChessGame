#pragma once
#include "Square.h"

const int BOARD_SIZE = 8;

class Board
{
private:
    Square board[BOARD_SIZE][BOARD_SIZE];

    void initializeFigures();
    bool isWithinBoard(Position position);

public:
    Board();
    virtual ~Board();

    void print();
    bool moveFigure(Position currentPosition, Position newPosition);
    void changeFigure(Position position, Figure* figure);
    Figure* getFigure(Position figurePosition);
};

