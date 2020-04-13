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


bool Bishop::isValidMove(Position newPosition, Figure* figure)
{
    bool isValid = false;
    

    if((board.getFigure(newPosition) == nullptr) ||
       ((board.getFigure(newPosition) != nullptr) && (board.getFigure(newPosition)->getColor() != this->color)))
    {
        isValid = true;
    }
    else
    {
        return isValid;
    }

    int currentX = position.x;
    int currentY = position.y;
    int newX = newPosition.x;
    int newY = newPosition.y;

    if(abs(currentY - newY) == abs(currentX - newX))
    {
        //cannot jump over other pieces
        int xIncrement = (newX - currentX) / (abs(newX - currentX));
		int yIncrement = (newY - currentY) / (abs(newY - currentY));

		for(int i=1; i<abs(currentX - newX); ++i)
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

    if(isValid && (board.getFigure(newPosition) != nullptr) && (board.getFigure(newPosition)->getType() == "K"))
    {
        std::cout << ((this->color == Color::White) ? "White's " : "Black's ") << "king is checked!";
    }
    return isValid;
}

