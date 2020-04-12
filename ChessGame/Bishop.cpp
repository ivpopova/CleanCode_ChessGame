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

    int currentX = position.x;
    int currentY = position.y;
    int moveToX = moveToPosition.x;
    int moveToY = moveToPosition.y;

    if(abs(currentY - moveToY) == abs(currentX - moveToX))
    {
        //cannot jump over other pieces
        int xIncrement = (moveToX - currentX) / (abs(moveToX - currentX));
		int yIncrement = (moveToY - currentY) / (abs(moveToY - currentY));

		for(int i=1; i<abs(currentX - moveToX); ++i)
		{
		    Position newPosition(currentX + xIncrement*i, currentY + yIncrement*i);
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

