#include <iostream>
#include <cmath>
#include "Bishop.h"
#include "Board.h"

extern Board board; 


Bishop::Bishop(Color color, Position pos)
{
    this->type = "B";
    this->color = color;
    this->position = pos;
}


Bishop::~Bishop()
{ }


bool Bishop::validateMove(Position moveToPos, Figure* piece)
{
    bool validMove = false;

    if((board.getPiece(moveToPos) == nullptr) ||
       ((board.getPiece(moveToPos) != nullptr) && (board.getPiece(moveToPos)->getColor() != this->color)))
    {
        validMove = true;
    }
    else
    {
        validMove = false;
        return validMove;
    }

    if(abs(position.ypos - moveToPos.ypos) == abs(position.xpos - moveToPos.xpos))
    {
        //cannot jump over other pieces
        int xIncrement = (moveToPos.xpos - position.xpos) / (abs(moveToPos.xpos - position.xpos));
		int yIncrement = (moveToPos.ypos - position.ypos) / (abs(moveToPos.ypos - position.ypos));

		for(int i=1; i<abs(position.xpos - moveToPos.xpos); ++i)
		{
		    Position newPosition(position.xpos + xIncrement*i, position.ypos + yIncrement*i);
			if(board.getPiece(newPosition) != nullptr)
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

