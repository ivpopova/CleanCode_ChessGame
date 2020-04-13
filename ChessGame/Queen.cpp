#include "Queen.h"
#include "Board.h"

extern Board board; 

Queen::Queen(Color color, Position position): Figure(), Bishop(color, position), Rook(color, position)
{
    this->type = "Q";
    this->color = color;
    this->position = position;
}

Queen::~Queen()
{
}

bool Queen::isValidMove(Position newPosition, Figure* figure)
{
    if(Bishop::isValidMove(newPosition, figure) || Rook::isValidMove(newPosition, figure))
    {
        return true;
    }
    return false;
}

