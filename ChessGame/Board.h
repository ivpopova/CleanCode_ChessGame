#pragma once
#include "Square.h"

class Board
{
private:
    Square board[8][8];

    void initializePieces();
    bool isWithinBoard(Position pos);

public:
    Board();
    virtual ~Board();

    void print();
    bool movePiece(Position fromPos, Position toPos);
    void changePiece(Position pos, Figure* piece);
    Figure* getPiece(Position piecePos);
};

