#include <iostream>
#include "Figure.h"
#include "King.h"
#include "Board.h"

extern Board board; 

King::King(Color color, Position position)
{
    this->type = "K";
    this->color = color;
    this->position = position;
}

King::~King()
{ }


bool King::isValidMove(Position moveToPosition, Figure* figure)
{
 bool isValid = false;

    //check if it's possible to move the king to this square
    if((board.getFigure(moveToPosition) == nullptr) ||
       (board.getFigure(moveToPosition) != nullptr && (board.getFigure(moveToPosition)->getColor() != this->color)))
    {
        isValid = true;
    }
    else
    {
        isValid = false;
        return isValid;
    }

    //(x-1,y+1), (x,y+1), (x+1,y+1),
    if(moveToPosition.y == (position.y + 1) && moveToPosition.x == (position.x - 1))
    {
        isValid = true;
    }
    else if(moveToPosition.y == (position.y + 1) && moveToPosition.x == position.x)
    {
        isValid = true;
    }
    else if(moveToPosition.y == (position.y + 1) && moveToPosition.x == (position.x + 1))
    {
        isValid = true;
    }
    //(x-1,y), (x+1,y),
    else if(moveToPosition.y == position.y && moveToPosition.x == (position.x - 1))
    {
        isValid = true;
    }
    else if(moveToPosition.y == position.y && moveToPosition.x == (position.x + 1))
    {
        isValid = true;
    }
    //(x-1,y-1), (x,y-1), (x+1,y-1),
    else if(moveToPosition.y == (position.y - 1) && moveToPosition.x == (position.x - 1))
    {
        isValid = true;
    }
    else if(moveToPosition.y == (position.y - 1) && moveToPosition.x == position.x)
    {
        isValid = true;
    }
    else if(moveToPosition.y == (position.y - 1) && moveToPosition.x == (position.x + 1))
    {
        isValid = true;
    }
    else
    {
        isValid = false;
    }

    if(isValid && (board.getFigure(moveToPosition) != nullptr) && (board.getFigure(moveToPosition)->getType() == "K"))
    {
        std::cout << ((this->color == Color::White) ? "White's " : "Black's ") << "king is checked!";
    }

    return isValid;
}
