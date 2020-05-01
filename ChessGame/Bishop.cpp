#include <iostream>
#include <cmath>
#include "Bishop.h"
#include "Board.h"

extern Board board; 


Bishop::Bishop(Color color, Position position) {
    setTypeFigure("B");
    setColor(color);
    setPosition(position);
}


Bishop::~Bishop() { 
}


bool Bishop::isValidMove(Position newPosition, Figure* figure) {

    bool isValid = false;
    
    if ((board.getFigure(newPosition) == nullptr) || ((board.getFigure(newPosition) != nullptr) && 
   (board.getFigure(newPosition)->getColor() != this->getColor()))) {
        isValid = true;
    }
    else {
        return isValid;
    }

    int currentX = getCurrentPosition().getPositionX();
    int currentY = getCurrentPosition().getPositionY();
    int newX = newPosition.getPositionX();
    int newY = newPosition.getPositionY();

    if (abs(currentY - newY) == abs(currentX - newX)) {
        
        int xIncrement = (newX - currentX) / (abs(newX - currentX));
		int yIncrement = (newY - currentY) / (abs(newY - currentY));

		for (int i=1; i<abs(currentX - newX); ++i) {
		    Position stepByStepNewPosition(currentX + xIncrement*i, currentY + yIncrement*i);
			
            if (board.getFigure(stepByStepNewPosition) != nullptr) {
                isValid = false;
                return isValid;
            }
		}

        isValid = true;
    }

    if (isValid && (board.getFigure(newPosition) != nullptr) && (board.getFigure(newPosition)->getTypeFigure() == "K")) {
        std::cout << ((this->getColor() == Color::White) ? "White's " : "Black's ") << "king is checked!";
    }

    return isValid;
}

#include <iostream>
#include <cmath>
#include "Bishop.h"
#include "Board.h"

extern Board board; 


Bishop::Bishop(Color color, Position position) {
    setTypeFigure("B");
    setColor(color);
    setPosition(position);
}


Bishop::~Bishop() { 
}


bool Bishop::isValidMove(Position newPosition, Figure* figure) {

    bool isValid = false;
    
    if ((board.getFigure(newPosition) == nullptr) || ((board.getFigure(newPosition) != nullptr) && 
   (board.getFigure(newPosition)->getColor() != this->getColor()))) {
        isValid = true;
    }
    else {
        return isValid;
    }

    int currentX = getCurrentPosition().getPositionX();
    int currentY = getCurrentPosition().getPositionY();
    int newX = newPosition.getPositionX();
    int newY = newPosition.getPositionY();

    if (abs(currentY - newY) == abs(currentX - newX)) {
        
        int xIncrement = (newX - currentX) / (abs(newX - currentX));
		int yIncrement = (newY - currentY) / (abs(newY - currentY));

		for (int i=1; i<abs(currentX - newX); ++i) {
		    Position stepByStepNewPosition(currentX + xIncrement*i, currentY + yIncrement*i);
			
            if (board.getFigure(stepByStepNewPosition) != nullptr) {
                isValid = false;
                return isValid;
            }
		}

        isValid = true;
    }

    if (isValid && (board.getFigure(newPosition) != nullptr) && (board.getFigure(newPosition)->getTypeFigure() == "K")) {
        std::cout << ((this->getColor() == Color::White) ? "White's " : "Black's ") << "king is checked!";
    }

    return isValid;
    
}

