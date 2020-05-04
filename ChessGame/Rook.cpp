#pragma once
#include "Rook.h"
#include "Board.h"

extern Board board; 

Rook::Rook(Color color, Position position) {
    setTypeFigure("R");
    setColor(color);
    setCurrentPosition(position);
}


Rook::~Rook() { 
}


bool Rook::isValidMove(Position newPosition, Figure* figure) {
    bool isValid = false;

    if ((board.getFigureFromPosition(newPosition) == nullptr) ||
       (board.getFigureFromPosition(newPosition) != nullptr && (board.getFigureFromPosition(newPosition)->getColor() != this->getColor()))) {
        isValid = true;
    }
    else {
        return isValid;
    }


    if ((newPosition.getCoordinateY() == getCurrentPosition().getCoordinateY())) {
        int xIncrement = (newPosition.getCoordinateX() - getCurrentPosition().getCoordinateX()) / (abs(newPosition.getCoordinateX() - getCurrentPosition().getCoordinateX()));
        
        for (int i= getCurrentPosition().getCoordinateX() + xIncrement; i!=newPosition.getCoordinateX(); i+=xIncrement) {
            Position stepByStepNewPosition(i, newPosition.getCoordinateY());
 
            if (board.getFigureFromPosition(stepByStepNewPosition) != nullptr) {
                isValid = false;

                return isValid;
            }
        }

        isValid = true;
    }

    
    if ((newPosition.getCoordinateX() == getCurrentPosition().getCoordinateX())) {
        int yIncrement = (newPosition.getCoordinateY() - getCurrentPosition().getCoordinateY()) / (abs(newPosition.getCoordinateY() - getCurrentPosition().getCoordinateY()));
        
        for (int i= getCurrentPosition().getCoordinateY()+yIncrement; i!=newPosition.getCoordinateY(); i+=yIncrement) {
            Position stepByStepNewPosition(newPosition.getCoordinateX(), i);

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
