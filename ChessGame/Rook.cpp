#pragma once
#include "Rook.h"
#include "Board.h"

extern Board board; 

Rook::Rook(Color color, Position position) {
    setTypeFigure("R");
    setColor(color);
    setPosition(position);
}


Rook::~Rook() { 
}


bool Rook::isValidMove(Position newPosition, Figure* figure) {
    bool isValid = false;

    if ((board.getFigure(newPosition) == nullptr) ||
       (board.getFigure(newPosition) != nullptr && (board.getFigure(newPosition)->getColor() != this->getColor()))) {
        isValid = true;
    }
    else {
        return isValid;
    }


    if ((newPosition.getPositionY() == getCurrentPosition().getPositionY())) {
        int xIncrement = (newPosition.getPositionX() - getCurrentPosition().getPositionX()) / (abs(newPosition.getPositionX() - getCurrentPosition().getPositionX()));
        
        for (int i= getCurrentPosition().getPositionX() + xIncrement; i!=newPosition.getPositionX(); i+=xIncrement) {
            Position stepByStepNewPosition(i, newPosition.getPositionY());
 
            if (board.getFigure(stepByStepNewPosition) != nullptr) {
                isValid = false;

                return isValid;
            }
        }

        isValid = true;
    }

    
    if ((newPosition.getPositionX() == getCurrentPosition().getPositionX())) {
        int yIncrement = (newPosition.getPositionY() - getCurrentPosition().getPositionY()) / (abs(newPosition.getPositionY() - getCurrentPosition().getPositionY()));
        
        for (int i= getCurrentPosition().getPositionY()+yIncrement; i!=newPosition.getPositionY(); i+=yIncrement) {
            Position stepByStepNewPosition(newPosition.getPositionX(), i);

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
