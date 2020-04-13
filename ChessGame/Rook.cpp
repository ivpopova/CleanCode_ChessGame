#pragma once
#include "Rook.h"
#include "Board.h"

extern Board board; 

Rook::Rook(Color color, Position position)
{
    this->type = "R";
    this->color = color;
    this->position = position;
}


Rook::~Rook()
{ 
}


bool Rook::isValidMove(Position newPosition, Figure* figure)
{
    bool isValid = false;

    if((board.getFigure(newPosition) == nullptr) ||
       (board.getFigure(newPosition) != nullptr && (board.getFigure(newPosition)->getColor() != this->color)))
    {
        isValid = true;
    }
    else
    {
        isValid = false;
        return isValid;
    }


    if((newPosition.y == position.y))
    {
        int xIncrement = (newPosition.x - position.x) / (abs(newPosition.x - position.x));
        for(int i=position.x + xIncrement; i!=newPosition.x; i+=xIncrement)
        {
            Position newPos;
            newPos.x = i;
            newPos.y = newPosition.y;
            if(board.getFigure(newPos) != nullptr)
            {
                isValid = false;
                return isValid;
            }
        }
        isValid = true;
    }

    
    if((newPosition.x == position.x))
    {
        int yIncrement = (newPosition.y - position.y) / (abs(newPosition.y - position.y));
        for(int i=position.y+yIncrement; i!=newPosition.y; i+=yIncrement)
        {
            Position newPos(newPosition.x, i);
            if(board.getFigure(newPos) != nullptr)
            {
                isValid = false;
                return isValid;
            }
        }
        isValid = true;
    }

    if(isValid && (board.getFigure(newPosition) != nullptr) && (board.getFigure(newPosition)->getType() == "K"))
    {
        std::cout << ((this->color == Color::White) ? "White's " : "Black's ") << "king is checked!";
    }

    return isValid;
}
