#include <iostream>
#include <cmath>
#include "Bishop.h"
#include "Board.h"

extern Board board; 


Bishop::Bishop(Color color, Position position)
{
    this->type = "B";
    this->color = color;
    this->position = position;
}


Bishop::~Bishop()
{ }


bool Bishop::isValidMove(Position moveToPosition, Figure* figure)
{
    bool isValid = false;

    if((board.getFigure(moveToPosition) == nullptr) ||
       ((board.getFigure(moveToPosition) != nullptr) && (board.getFigure(moveToPosition)->getColor() != this->color)))
    {
        isValid = true;
    }
    else
    {
        isValid = false;
        return isValid;
    }

    if(abs(position.ypos - moveToPosition.ypos) == abs(position.xpos - moveToPosition.xpos))
    {
        //cannot jump over other pieces
        int xIncrement = (moveToPosition.xpos - position.xpos) / (abs(moveToPosition.xpos - position.xpos));
		int yIncrement = (moveToPosition.ypos - position.ypos) / (abs(moveToPosition.ypos - position.ypos));

		for(int i=1; i<abs(position.xpos - moveToPosition.xpos); ++i)
		{
		    Position newPosition(position.xpos + xIncrement*i, position.ypos + yIncrement*i);
			if(board.getFigure(newPosition) != nullptr)
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

