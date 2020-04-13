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

bool Knight::isValidMove(Position newPosition, Figure* figure)
{
    bool isValid = false;

    //check if it's possible to move the knight to this square
    if((board.getFigure(newPosition) == nullptr) ||
       (board.getFigure(newPosition) != nullptr && (board.getFigure(newPosition)->getColor() != this->color)))
    {
        isValid = true;
    }
    else
    {
        return isValid;
    }

    if(((abs(position.x - newPosition.x) == 2) && (abs(position.y - newPosition.y) == 1)) ||
       ((abs(position.x - newPosition.x) == 1) && (abs(position.y  - newPosition.y) == 2)))
    {
        isValid = true;
    }

    if(isValid && (board.getFigure(newPosition) != nullptr) && (board.getFigure(newPosition)->getType() == "K"))
    {
        std::cout << ((this->color == Color::White) ? "White's " : "Black's ") << "king is checked!";
    }

    return isValid;
}
