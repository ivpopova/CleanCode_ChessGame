#pragma once
#include "Square.h"

const int BOARD_SIZE = 8;

class Board {
public:
    Board();
    virtual ~Board();

    Figure* getFigure(Position figurePosition);
    bool moveFigure(Position currentPosition, Position newPosition);
    void changeFigure(Position position, Figure* figure);
    void print();

private:
    Square board[BOARD_SIZE][BOARD_SIZE];

    void initializeFigures();
    bool isWithinBoard(Position position);
};

