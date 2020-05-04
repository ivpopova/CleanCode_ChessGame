#include <iostream>
#include <cmath>
#include "Knight.h"
#include "Board.h"

extern Board board; 


Knight::Knight(Color color, Position position) {
    setTypeFigure("N");
    setColor(color);
    setCurrentPosition(position);
}


Knight::~Knight() {
}

bool Knight::isValidMove(Position newPosition, Figure* figure) {
    bool isValid = false;

    if ((board.getFigureFromPosition(newPosition) == nullptr) ||
       (board.getFigureFromPosition(newPosition) != nullptr && (board.getFigureFromPosition(newPosition)->getColor() != this->getColor()))) {
        
        isValid = true;
    }
    else {

        return isValid;
    }

    if (((abs(getCurrentPosition().getCoordinateX() - newPosition.getCoordinateX()) == 2) && (abs(getCurrentPosition().getCoordinateY() - newPosition.getCoordinateY()) == 1)) ||
       ((abs(getCurrentPosition().getCoordinateX() - newPosition.getCoordinateX()) == 1) && (abs(getCurrentPosition().getCoordinateY() - newPosition.getCoordinateY()) == 2))) {
       
        isValid = true;
    }

    if (isValid && (board.getFigureFromPosition(newPosition) != nullptr) && (board.getFigureFromPosition(newPosition)->getTypeFigure() == "K")) {
        std::cout << ((this->getColor() == Color::White) ? "White's " : "Black's ") << "king is checked!";
    }

    return isValid;
}
