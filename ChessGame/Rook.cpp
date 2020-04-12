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


    if((moveToPosition.ypos == position.ypos))
    {
        int xIncrement = (moveToPosition.xpos - position.xpos) / (abs(moveToPosition.xpos - position.xpos));
        for(int i=position.xpos + xIncrement; i!=moveToPosition.xpos; i+=xIncrement)
        {
            Position newPos;
            newPos.xpos = i;
            newPos.ypos = moveToPosition.ypos;
            if(board.getFigure(newPos) != nullptr)
            {
                isValid = false;
                return isValid;
            }
        }
        isValid = true;
    }

    
    if((moveToPosition.xpos == position.xpos))
    {
        int yIncrement = (moveToPosition.ypos - position.ypos) / (abs(moveToPosition.ypos - position.ypos));
        for(int i=position.ypos+yIncrement; i!=moveToPosition.ypos; i+=yIncrement)
        {
            Position newPos(moveToPosition.xpos, i);
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
