#include <iostream>
#include <cmath>
#include "Knight.h"
#include "Board.h"

extern Board board; 


Knight::Knight(Color color, Position position)
{
    setTypeFigure("N");
    setColor(color);
    setPosition(position);
}


Knight::~Knight()
{ }

bool Knight::isValidMove(Position position, Figure* figure)
{
    bool isValid = false;

    //check if it's possible to move the knight to this square
    if((board.getFigure(position) == nullptr) ||
       (board.getFigure(position) != nullptr && (board.getFigure(position)->getColor() != this->getColor())))
    {
        isValid = true;
    }
    else
    {
        return isValid;
    }

    if(((abs(getCurrentPosition().getX() - position.getX()) == 2) && (abs(getCurrentPosition().getY() - position.getY()) == 1)) ||
       ((abs(getCurrentPosition().getX() - position.getX()) == 1) && (abs(getCurrentPosition().getY() - position.getY()) == 2)))
    {
        isValid = true;
    }

    if(isValid && (board.getFigure(position) != nullptr) && (board.getFigure(position)->getTypeFigure() == "K"))
    {
        std::cout << ((this->getColor() == Color::White) ? "White's " : "Black's ") << "king is checked!";
    }

    return isValid;
}
