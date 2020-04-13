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


bool King::isValidMove(Position newPosition, Figure* figure)
{
 bool isValid = false;

    //check if it's possible to move the king to this square
    if((board.getFigure(newPosition) == nullptr) ||
       (board.getFigure(newPosition) != nullptr && (board.getFigure(newPosition)->getColor() != this->color)))
    {
        isValid = true;
    }
    else
    {
        return isValid;
    }

    //(x-1,y+1), (x,y+1), (x+1,y+1),
    if(newPosition.y == (position.y + 1) && newPosition.x == (position.x - 1))
    {
        isValid = true;
    }
    else if(newPosition.y == (position.y + 1) && newPosition.x == position.x)
    {
        isValid = true;
    }
    else if(newPosition.y == (position.y + 1) && newPosition.x == (position.x + 1))
    {
        isValid = true;
    }
    //(x-1,y), (x+1,y),
    else if(newPosition.y == position.y && newPosition.x == (position.x - 1))
    {
        isValid = true;
    }
    else if(newPosition.y == position.y && newPosition.x == (position.x + 1))
    {
        isValid = true;
    }
    //(x-1,y-1), (x,y-1), (x+1,y-1),
    else if(newPosition.y == (position.y - 1) && newPosition.x == (position.x - 1))
    {
        isValid = true;
    }
    else if(newPosition.y == (position.y - 1) && newPosition.x == position.x)
    {
        isValid = true;
    }
    else if(newPosition.y == (position.y - 1) && newPosition.x == (position.x + 1))
    {
        isValid = true;
    }
    else
    {
        isValid = false;
    }

    if(isValid && (board.getFigure(newPosition) != nullptr) && (board.getFigure(newPosition)->getType() == "K"))
    {
        std::cout << ((this->color == Color::White) ? "White's " : "Black's ") << "king is checked!";
    }

    return isValid;
}
