#include "Queen.h"
#include "Board.h"

extern Board board; 

Queen::Queen(Color color, Position pos): Figure(), Bishop(color, pos), Rook(color, pos)
{
    this->type = "Q";
    this->color = color;
    this->position = pos;
}

Queen::~Queen()
{
}

bool Queen::validateMove(Position moveToPos, Figure* piece)
{
    if(Bishop::validateMove(moveToPos, piece) || Rook::validateMove(moveToPos, piece))
    {
        return true;
    }
    return false;
}

