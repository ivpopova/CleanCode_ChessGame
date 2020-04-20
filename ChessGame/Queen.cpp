#include "Queen.h"
#include "Board.h"

extern Board board; 

Queen::Queen(Color color, Position position): Figure(), Bishop(color, position), Rook(color, position)
{
    setTypeFigure("Q");
    setColor(color);
    setPosition(position);
}

Queen::~Queen()
{
}

bool Queen::isValidMove(Position position, Figure* figure)
{
    if(Bishop::isValidMove(position, figure) || Rook::isValidMove(position, figure))
    {
        return true;
    }
    return false;
}

