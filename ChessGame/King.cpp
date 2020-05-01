#include <iostream>
#include "Figure.h"
#include "King.h"
#include "Board.h"

extern Board board; 

King::King(Color color, Position position)
{
    setTypeFigure("K");
    setColor(color);
    setPosition(position);
}

King::~King()
{ }


bool King::isValidMove(Position newPosition, Figure* figure)
{
 bool isValid = false;

    //check if it's possible to move the king to this square
    if((board.getFigure(newPosition) == nullptr) ||
       (board.getFigure(newPosition) != nullptr && (board.getFigure(newPosition)->getColor() != this->getColor())))
    {
        isValid = true;
    }
    else
    {
        return isValid;
    }

    
    if(newPosition.getPositionY() == (getCurrentPosition().getPositionY() + 1) && newPosition.getPositionX() == (getCurrentPosition().getPositionX() - 1))
    {
        isValid = true;
    }
    else if(newPosition.getPositionY() == (getCurrentPosition().getPositionY() + 1) && newPosition.getPositionX() == getCurrentPosition().getPositionX())
    {
        isValid = true;
    }
    else if(newPosition.getPositionY() == (getCurrentPosition().getPositionY() + 1) && newPosition.getPositionX() == (getCurrentPosition().getPositionX() + 1))
    {
        isValid = true;
    }
    else if(newPosition.getPositionY() == getCurrentPosition().getPositionY() && newPosition.getPositionX() == (getCurrentPosition().getPositionX() - 1))
    {
        isValid = true;
    }
    else if(newPosition.getPositionY() == getCurrentPosition().getPositionY() && newPosition.getPositionX() == (getCurrentPosition().getPositionX() + 1))
    {
        isValid = true;
    }
    else if(newPosition.getPositionY() == (getCurrentPosition().getPositionY() - 1) && newPosition.getPositionX() == (getCurrentPosition().getPositionX()  - 1))
    {
        isValid = true;
    }
    else if(newPosition.getPositionY() == (getCurrentPosition().getPositionY() - 1) && newPosition.getPositionX() == getCurrentPosition().getPositionX())
    {
        isValid = true;
    }
    else if(newPosition.getPositionY() == (getCurrentPosition().getPositionY() - 1) && newPosition.getPositionX() == (getCurrentPosition().getPositionX() + 1))
    {
        isValid = true;
    }
    else
    {
        isValid = false;
    }

    if(isValid && (board.getFigure(newPosition) != nullptr) && (board.getFigure(newPosition)->getTypeFigure() == "K"))
    {
        std::cout << ((this->getColor() == Color::White) ? "White's " : "Black's ") << "king is checked!";
    }

    return isValid;
}
