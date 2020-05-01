#include <iostream>
#include <cmath>
#include "Knight.h"
#include "Board.h"

extern Board board; 


Knight::Knight(Color color, Position position) {
    setTypeFigure("N");
    setColor(color);
    setPosition(position);
}


Knight::~Knight() {
}

bool Knight::isValidMove(Position newPosition, Figure* figure) {
    bool isValid = false;

    //check if it's possible to move the knight to this square
    if ((board.getFigure(newPosition) == nullptr) ||
       (board.getFigure(newPosition) != nullptr && (board.getFigure(newPosition)->getColor() != this->getColor()))) {
        
        isValid = true;
    }
    else {

        return isValid;
    }

    if (((abs(getCurrentPosition().getPositionX() - newPosition.getPositionX()) == 2) && (abs(getCurrentPosition().getPositionY() - newPosition.getPositionY()) == 1)) ||
       ((abs(getCurrentPosition().getPositionX() - newPosition.getPositionX()) == 1) && (abs(getCurrentPosition().getPositionY() - newPosition.getPositionY()) == 2))) {
       
        isValid = true;
    }

    if (isValid && (board.getFigure(newPosition) != nullptr) && (board.getFigure(newPosition)->getTypeFigure() == "K")) {
        std::cout << ((this->getColor() == Color::White) ? "White's " : "Black's ") << "king is checked!";
    }

    return isValid;
}
