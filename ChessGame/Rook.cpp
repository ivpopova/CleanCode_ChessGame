#pragma once
#include "Rook.h"
#include "Board.h"

extern Board board; 

Rook::Rook(Color color, Position position)
{
    setTypeFigure("R");
    setColor(color);
    setPosition(position);
}


Rook::~Rook()
{ 
}


bool Rook::isValidMove(Position position, Figure* figure)
{
    bool isValid = false;

    if((board.getFigure(position) == nullptr) ||
       (board.getFigure(position) != nullptr && (board.getFigure(position)->getColor() != this->getColor())))
    {
        isValid = true;
    }
    else {
        return isValid;
    }


    if((position.getY() == getCurrentPosition().getY()))
    {
        int xIncrement = (position.getX() - getCurrentPosition().getX()) / (abs(position.getX() - getCurrentPosition().getX()));
        for(int i= getCurrentPosition().getX() + xIncrement; i!=position.getX(); i+=xIncrement)
        {
            Position nextPosition;
            nextPosition.setX (i);
            nextPosition.setY(position.getY());
            if(board.getFigure(nextPosition) != nullptr)
            {
                isValid = false;
                return isValid;
            }
        }
        isValid = true;
    }

    
    if((position.getX() == getCurrentPosition().getX()))
    {
        int yIncrement = (position.getY() - getCurrentPosition().getY()) / (abs(position.getY() - getCurrentPosition().getY()));
        for(int i= getCurrentPosition().getY() +yIncrement; i!=position.getY(); i+=yIncrement)
        {
            Position nextPosition(position.getX(), i);
            if(board.getFigure(nextPosition) != nullptr)
            {
                isValid = false;
                return isValid;
            }
        }
        isValid = true;
    }

    if(isValid && (board.getFigure(position) != nullptr) && (board.getFigure(position)->getTypeFigure() == "K"))
    {
        std::cout << ((this->getColor() == Color::White) ? "White's " : "Black's ") << "king is checked!";
    }

    return isValid;
}
