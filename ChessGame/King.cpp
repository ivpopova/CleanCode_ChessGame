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


bool King::isValidMove(Position position, Figure* figure)
{
 bool isValid = false;

    //check if it's possible to move the king to this square
    if((board.getFigure(position) == nullptr) ||
       (board.getFigure(position) != nullptr && (board.getFigure(position)->getColor() != this->getColor())))
    {
        isValid = true;
    }
    else
    {
        return isValid;
    }

    //(x-1,y+1), (x,y+1), (x+1,y+1),
    if(position.getY() == (getCurrentPosition().getY() + 1) && position.getX() == (getCurrentPosition().getX() - 1))
    {
        isValid = true;
    }
    else if(position.getY() == (getCurrentPosition().getY() + 1) && position.getX() == getCurrentPosition().getX())
    {
        isValid = true;
    }
    else if(position.getY() == (getCurrentPosition().getY() + 1) && position.getX() == (getCurrentPosition().getX() + 1))
    {
        isValid = true;
    }
    //(x-1,y), (x+1,y),
    else if(position.getY() == getCurrentPosition().getY() && position.getX() == (getCurrentPosition().getX() - 1))
    {
        isValid = true;
    }
    else if(position.getY() == getCurrentPosition().getY() && position.getX() == (getCurrentPosition().getX() + 1))
    {
        isValid = true;
    }
    //(x-1,y-1), (x,y-1), (x+1,y-1),
    else if(position.getY() == (getCurrentPosition().getY() - 1) && position.getX() == (getCurrentPosition().getX()  - 1))
    {
        isValid = true;
    }
    else if(position.getY() == (getCurrentPosition().getY() - 1) && position.getX() == getCurrentPosition().getX())
    {
        isValid = true;
    }
    else if(position.getY() == (getCurrentPosition().getY() - 1) && position.getX() == (getCurrentPosition().getX() + 1))
    {
        isValid = true;
    }
    else
    {
        isValid = false;
    }

    if(isValid && (board.getFigure(position) != nullptr) && (board.getFigure(position)->getTypeFigure() == "K"))
    {
        std::cout << ((this->getColor() == Color::White) ? "White's " : "Black's ") << "king is checked!";
    }

    return isValid;
}
