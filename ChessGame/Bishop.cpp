#include <iostream>
#include <cmath>
#include "Bishop.h"
#include "Board.h"

extern Board board; 


Bishop::Bishop(Color color, Position position) {
    setTypeFigure("B");
    setColor(color);
    setCurrentPosition(position);
}


Bishop::~Bishop() { 
}


bool Bishop::isValidMove(Position newPosition, Figure* figure) {

    bool isValid = false;
    
    if ((board.getFigureFromPosition(newPosition) == nullptr) || ((board.getFigureFromPosition(newPosition) != nullptr) && 
   (board.getFigureFromPosition(newPosition)->getColor() != this->getColor()))) {
        isValid = true;
    }
    else {
        return isValid;
    }

    int currentX = getCurrentPosition().getCoordinateX();
    int currentY = getCurrentPosition().getCoordinateY();
    int newX = newPosition.getCoordinateX();
    int newY = newPosition.getCoordinateY();

    if (abs(currentY - newY) == abs(currentX - newX)) {
        
        int xIncrement = (newX - currentX) / (abs(newX - currentX));
		int yIncrement = (newY - currentY) / (abs(newY - currentY));

		for (int i=1; i<abs(currentX - newX); ++i) {
		    Position stepByStepNewPosition(currentX + xIncrement*i, currentY + yIncrement*i);
			
            if (board.getFigureFromPosition(stepByStepNewPosition) != nullptr) {
                isValid = false;
                return isValid;
            }
		}

        isValid = true;
    }

    if (isValid && (board.getFigureFromPosition(newPosition) != nullptr) && (board.getFigureFromPosition(newPosition)->getTypeFigure() == "K")) {
        std::cout << ((this->getColor() == Color::White) ? "White's " : "Black's ") << "king is checked!";
    }

    return isValid;
}

