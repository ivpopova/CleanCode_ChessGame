#include <iostream>
#include <cmath>
#include "Knight.h"
#include "Board.h"

extern Board board; 


Knight::Knight(Color color, Position position)
{
    this->type = "N";
    this->color = color;
    this->position = position;
}


Knight::~Knight()
{ }

bool Knight::isValidMove(Position moveToPosition, Figure* figure)
{
    bool isValid = false;

    //check if it's possible to move the knight to this square
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

    if(((abs(position.x - moveToPosition.x) == 2) && (abs(position.y - moveToPosition.y) == 1)) ||
       ((abs(position.x - moveToPosition.x) == 1) && (abs(position.y  - moveToPosition.y) == 2)))
    {
        isValid = true;
    }

    if(isValid && (board.getFigure(moveToPosition) != nullptr) && (board.getFigure(moveToPosition)->getType() == "K"))
    {
        std::cout << ((this->color == Color::White) ? "White's " : "Black's ") << "king is checked!";
    }
    return isValid;
}
