#include <iostream>
#include <cmath>
#include "Bishop.h"
#include "Board.h"

extern Board board; 


Bishop::Bishop(Color color, Position position)
{
    setTypeFigure("B");
    setColor(color);
    setPosition(position);
}


Bishop::~Bishop()
{ }


bool Bishop::isValidMove(Position position, Figure* figure)
{
    bool isValid = false;
    

    if((board.getFigure(position) == nullptr) || ((board.getFigure(position) != nullptr) && 
   (board.getFigure(position)->getColor() != this->getColor())))
    {
        isValid = true;
    }
    else
    {
        return isValid;
    }

    int currentX = getCurrentPosition().getX();
    int currentY = getCurrentPosition().getY();
    int newX = position.getX();
    int newY = position.getY();

    if(abs(currentY - newY) == abs(currentX - newX))
    {
        //cannot jump over other pieces
        int xIncrement = (newX - currentX) / (abs(newX - currentX));
		int yIncrement = (newY - currentY) / (abs(newY - currentY));

		for(int i=1; i<abs(currentX - newX); ++i)
		{
		    Position nextPosition(currentX + xIncrement*i, currentY + yIncrement*i);
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

