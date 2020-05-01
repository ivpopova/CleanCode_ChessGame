#include <cstring>
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Board.h"

extern Board board; 

Pawn::Pawn(Color color, Position position) {
    setTypeFigure("P");
    setColor(color);
    setPosition(position);
    this->isDoubleJumpAvailable = true;
}


Pawn::~Pawn() { 
}

Figure* Pawn::promote(Position position) {
    std::string input;
    Figure* figure = nullptr;

    std::cout << "Choose with which piece to replace this pawn (Q - Queen, R - Rook, N - Knight, B - Bishop)";
    while (std::cin >> input) {
        if (input == "Q" || input == "q") {
            if (getColor() == Color::White) {
                figure = new Queen(Color::White, position);
            }
            else {
                figure = new Queen(Color::Black, position);
            }

            board.changeFigure(position, figure);
            return figure;
        }
        else if (input == "R"|| input == "r") {
            if (getColor() == Color::White) {
                figure = new Rook(Color::White, position);
            }
            else {
                figure = new Rook(Color::Black, position);
            }

            board.changeFigure(position, figure);
            return figure;
        }
        else if (input == "N" || input == "n") {
            if (getColor() == Color::White) {
                 figure = new Knight(Color::White, position);
            }
            else {
                 figure = new Knight(Color::Black, position);
            }

            board.changeFigure(position, figure);
            return figure;
        }
        else if (input == "B" || input == "b") {
            if (getColor() == Color::White) {
                figure = new Bishop(Color::White, position);
            }
            else {
                 figure = new Bishop(Color::Black, position);
            }

            board.changeFigure(position, figure);
            return figure;
        }
        else {
            std::cout << "Invalid choice, choose again (Q - Queen, R - Rook, N - Knight, B - Bishop)";
        }
    }

    return figure;
}


bool Pawn::isValidMove(Position newPosition, Figure* figure) {
    bool isValid = false;

    int allowableMove1 = 1;
    int allowableMove2 = 2;

    //if black on turn, the movement is downwards on board
    if (getColor() == Color::Black) {
        allowableMove1 = -1;
        allowableMove2 = -2;
    }

    Position stepBystepNewPosition(getCurrentPosition().getPositionY() + allowableMove1, getCurrentPosition().getPositionX());

    if (newPosition.getPositionY() == (getCurrentPosition().getPositionY() + allowableMove1) && newPosition.getPositionX() == getCurrentPosition().getPositionX() && board.getFigure(newPosition) == nullptr)  {
      
        if (newPosition.getPositionY() == 7 || newPosition.getPositionY() == 0) {

            figure = promote(newPosition);
        }

        isValid = true;
        isDoubleJumpAvailable = false;
    }
    else if (isDoubleJumpAvailable == true && newPosition.getPositionY() == (getCurrentPosition().getPositionY() + allowableMove2) && newPosition.getPositionX() == getCurrentPosition().getPositionX()
            && board.getFigure(newPosition) == nullptr && board.getFigure(stepBystepNewPosition) == nullptr) {

        isValid = true;
        isDoubleJumpAvailable = false;
    }
    else if (newPosition.getPositionY() == getCurrentPosition().getPositionY() + allowableMove1 && (newPosition.getPositionX() == getCurrentPosition().getPositionX() - 1 || newPosition.getPositionX() == getCurrentPosition().getPositionX() + 1)) {
        
        if (board.getFigure(newPosition) != nullptr && (board.getFigure(newPosition)->getColor() != this->getColor())) {
            
            if(newPosition.getPositionY() == 7 || newPosition.getPositionY() == 0) {
                figure = promote(newPosition);
                figure->print();
            }

            isValid = true;
            isDoubleJumpAvailable = false;
        }
    }

    if(isValid && (board.getFigure(newPosition) != nullptr) && (board.getFigure(newPosition)->getTypeFigure() == "K")) {
        std::cout << ((this->getColor() == Color::White) ? "White's " : "Black's ") << "king is checked!";
    }

    return isValid;
}

