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


bool Rook::isValidMove(Position moveToPosition, Figure* figure)
{
    bool isValid = false;

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


    if((moveToPosition.y == position.y))
    {
        int xIncrement = (moveToPosition.x - position.x) / (abs(moveToPosition.x - position.x));
        for(int i=position.x + xIncrement; i!=moveToPosition.x; i+=xIncrement)
        {
            Position newPos;
            newPos.x = i;
            newPos.y = moveToPosition.y;
            if(board.getFigure(newPos) != nullptr)
            {
                isValid = false;
                return isValid;
            }
        }
        isValid = true;
    }

    
    if((moveToPosition.x == position.x))
    {
        int yIncrement = (moveToPosition.y - position.y) / (abs(moveToPosition.y - position.y));
        for(int i=position.y+yIncrement; i!=moveToPosition.y; i+=yIncrement)
        {
            Position newPos(moveToPosition.x, i);
            if(board.getFigure(newPos) != nullptr)
            {
                isValid = false;
                return isValid;
            }
        }
        isValid = true;
    }

    if(isValid && (board.getFigure(moveToPosition) != nullptr) && (board.getFigure(moveToPosition)->getType() == "K"))
    {
        std::cout << ((this->color == Color::White) ? "White's " : "Black's ") << "king is checked!";
    }

    return isValid;
}
