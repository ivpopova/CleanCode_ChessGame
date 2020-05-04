#include <iostream>
#include "Figure.h"
#include "King.h"
#include "Board.h"

extern Board board; 

King::King(Color color, Position position) {
    setTypeFigure("K");
    setColor(color);
    setCurrentPosition(position);
}

King::~King(){
}


bool King::isValidMove(Position newPosition, Figure* figure) {
 bool isValid = false;

    //check if it's possible to move the king to this square
    if((board.getFigureFromPosition(newPosition) == nullptr) ||
       (board.getFigureFromPosition(newPosition) != nullptr && (board.getFigureFromPosition(newPosition)->getColor() != this->getColor()))) {
        isValid = true;
    }
    else {
        return isValid;
    }

    
    if(newPosition.getCoordinateY() == (getCurrentPosition().getCoordinateY() + 1) && newPosition.getCoordinateX() == (getCurrentPosition().getCoordinateX() - 1)) {
        isValid = true;
    }
    else if(newPosition.getCoordinateY() == (getCurrentPosition().getCoordinateY() + 1) && newPosition.getCoordinateX() == getCurrentPosition().getCoordinateX()) {
        isValid = true;
    }
    else if(newPosition.getCoordinateY() == (getCurrentPosition().getCoordinateY() + 1) && newPosition.getCoordinateX() == (getCurrentPosition().getCoordinateX() + 1)) {
        isValid = true;
    }
    else if(newPosition.getCoordinateY() == getCurrentPosition().getCoordinateY() && newPosition.getCoordinateX() == (getCurrentPosition().getCoordinateX() - 1)) {
        isValid = true;
    }
    else if(newPosition.getCoordinateY() == getCurrentPosition().getCoordinateY() && newPosition.getCoordinateX() == (getCurrentPosition().getCoordinateX() + 1)) {
        isValid = true;
    }
    else if(newPosition.getCoordinateY() == (getCurrentPosition().getCoordinateY() - 1) && newPosition.getCoordinateX() == (getCurrentPosition().getCoordinateX()  - 1)) {
        isValid = true;
    }
    else if(newPosition.getCoordinateY() == (getCurrentPosition().getCoordinateY() - 1) && newPosition.getCoordinateX() == getCurrentPosition().getCoordinateX()) {
        isValid = true;
    }
    else if(newPosition.getCoordinateY() == (getCurrentPosition().getCoordinateY() - 1) && newPosition.getCoordinateX() == (getCurrentPosition().getCoordinateX() + 1)) {
        isValid = true;
    }
    else {
        isValid = false;
    }

    if(isValid && (board.getFigureFromPosition(newPosition) != nullptr) && (board.getFigureFromPosition(newPosition)->getTypeFigure() == "K")) {
        std::cout << ((this->getColor() == Color::White) ? "White's " : "Black's ") << "king is checked!";
    }

    return isValid;
}
