#pragma once
#include "Rook.h"
#include "Board.h"

extern Board board; 

Rook::Rook(Color color, Position pos)
{
    this->type = "R";
    this->color = color;
    this->position = pos;
}


Rook::~Rook()
{ 
}


bool Rook::validateMove(Position moveToPos, Figure* piece)
{
    bool validMove = false;

    if((board.getPiece(moveToPos) == nullptr) ||
       (board.getPiece(moveToPos) != nullptr && (board.getPiece(moveToPos)->getColor() != this->color)))
    {
        validMove = true;
    }
    else
    {
        validMove = false;
        return validMove;
    }


    if((moveToPos.ypos == position.ypos))
    {
        int xIncrement = (moveToPos.xpos - position.xpos) / (abs(moveToPos.xpos - position.xpos));
        for(int i=position.xpos + xIncrement; i!=moveToPos.xpos; i+=xIncrement)
        {
            Position newPos;
            newPos.xpos = i;
            newPos.ypos = moveToPos.ypos;
            if(board.getPiece(newPos) != nullptr)
            {
                validMove = false;
                return validMove;
            }
        }
        validMove = true;
    }

    
    if((moveToPos.xpos == position.xpos))
    {
        int yIncrement = (moveToPos.ypos - position.ypos) / (abs(moveToPos.ypos - position.ypos));
        for(int i=position.ypos+yIncrement; i!=moveToPos.ypos; i+=yIncrement)
        {
            Position newPos(moveToPos.xpos, i);
            if(board.getPiece(newPos) != nullptr)
            {
                validMove = false;
                return validMove;
            }
        }
        validMove = true;
    }

    if(validMove && (board.getPiece(moveToPos) != nullptr) && (board.getPiece(moveToPos)->getType() == "K"))
    {
        std::cout << ((this->color == Color::White) ? "White's " : "Black's ") << "king is checked!";
    }

    return validMove;
}
