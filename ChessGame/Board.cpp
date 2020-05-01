#include "Board.h"
#include "Figure.h"
#include "Pawn.h"
#include "Rook.h"
#include "Queen.h"
#include "Knight.h"
#include "King.h"
#include "Bishop.h"


Board::Board() {
    initializeFigures();
}


Board::~Board() {
}

void Board::print()
{
    for (int row = BOARD_SIZE-1; row >= 0; row--) {
        std::cout << "   ";

        for (int col=0; col< BOARD_SIZE; ++col) {
            std::cout << "-----";
        }

        std::cout << "-\n";

        //print vertical row divider and chess piece
        std::cout << row + 1 << "  ";
        for (int col=0; col< BOARD_SIZE; ++col) {
            std::cout << "| ";

            Figure *currentFigure = board[row][col].getFigure();
            if (currentFigure != nullptr) {
                currentFigure->print();
            }
            else {
                std::cout << "  ";
            }

            std::cout << " ";
        }

        std::cout << "|" << std::endl;
    }

    //print horizontal divider for the bottom of the board
    std::cout << "   ";
    for (int col=0; col< BOARD_SIZE; ++col) {
        std::cout << "-----";
    }

    std::cout << "-\n";

    //print Letters on the bottom of the board
    std::cout << "   ";
    for (int col=0; col< BOARD_SIZE; ++col) {
        std::cout << "  " << (char)(col + 97) << "  ";
    }

    std::cout << "\n\n";
}


void Board::changeFigure(Position position, Figure* figure) {
    board[position.getPositionY()][position.getPositionX()].clearFigure();
    board[position.getPositionY()][position.getPositionX()].setFigure(figure);
}


void Board::initializeFigures() {
    // Pawns
    for (int col=0; col< BOARD_SIZE; ++col) {
        Position blackPawn(col,6);
        board[blackPawn.getPositionY()][blackPawn.getPositionX()].setFigure(new Pawn(Black, blackPawn));

        Position whitePawn(col,1);
        board[whitePawn.getPositionY()][blackPawn.getPositionX()].setFigure(new Pawn(White, whitePawn));
    }


    // Rooks
    Position whiteLeftRook(0,0);
    board[whiteLeftRook.getPositionY()][whiteLeftRook.getPositionX()].setFigure(new Rook(White, whiteLeftRook));

    Position whiteRightRook (7,0);
    board[whiteRightRook.getPositionY()][whiteRightRook.getPositionX()].setFigure(new Rook(White, whiteRightRook));

    Position blackLeftRook (0,7);
    board[blackLeftRook.getPositionY()][blackLeftRook.getPositionX()].setFigure(new Rook(Black, blackLeftRook));

    Position blackRightRook (7,7);
    board[blackRightRook.getPositionY()][blackRightRook.getPositionX()].setFigure(new Rook(Black, blackRightRook));


    // Knights
    Position whiteLeftKnight (1,0);
    board[whiteLeftKnight.getPositionY()][whiteLeftKnight.getPositionX()].setFigure(new Knight(White, whiteLeftKnight));

    Position whiteRightKnight (6,0);
    board[whiteRightKnight.getPositionY()][whiteRightKnight.getPositionX()].setFigure(new Knight(White, whiteRightKnight));

    Position blackLeftKnight (1,7);
    board[blackLeftKnight.getPositionY()][blackLeftKnight.getPositionX()].setFigure(new Knight(Black, blackLeftKnight));

    Position blackRightKnight (6,7);
    board[blackRightKnight.getPositionY()][blackRightKnight.getPositionX()].setFigure(new Knight(Black, blackRightKnight));


    // Bishops
    Position whiteLeftBishop (2,0);
    board[whiteLeftBishop.getPositionY()][whiteLeftBishop.getPositionX()].setFigure(new Bishop(White, whiteLeftBishop));

    Position whiteRightBishop (5,0);
    board[whiteRightBishop.getPositionY()][whiteRightBishop.getPositionX()].setFigure(new Bishop(White, whiteRightBishop));

    Position blackLeftBishop (2,7);
    board[blackLeftBishop.getPositionY()][blackLeftBishop.getPositionX()].setFigure(new Bishop(Black, blackLeftBishop));

    Position blackRightBishop (5,7);
    board[blackRightBishop.getPositionY()][blackRightBishop.getPositionX()].setFigure(new Bishop(Black, blackRightBishop));


    // Kings
    Position whiteKing (4,0);
    board[whiteKing.getPositionY()][whiteKing.getPositionX()].setFigure(new King(White, whiteKing));

    Position blackKing (4,7);
    board[blackKing.getPositionY()][blackKing.getPositionX()].setFigure(new King(Black, blackKing));


    // Queens
    Position whiteQueen (3,0);
    board[whiteQueen.getPositionY()][whiteQueen.getPositionX()].setFigure(new Queen(White, whiteQueen));

    Position blackQueen (3,7);
    board[blackQueen.getPositionY()][blackQueen.getPositionX()].setFigure(new Queen(Black, blackQueen));
}


bool Board::moveFigure(Position currentPosition, Position newPosition) {
    
    bool isMoveCompleted = false;

    Figure* figure = board[currentPosition.getPositionY()][currentPosition.getPositionX()].getFigure();
    if (figure != nullptr && figure->isValidMove(newPosition, figure) && isWithinBoard(newPosition)) {
        figure->print();
        figure->setPosition(newPosition);

        board[newPosition.getPositionY()][newPosition.getPositionX()].setFigure(figure);
        board[currentPosition.getPositionY()][currentPosition.getPositionX()].clearFigure();

        isMoveCompleted = true;
    }

    return isMoveCompleted;
}


Figure* Board::getFigure(Position figurePosition) {
    return board[figurePosition.getPositionY()][figurePosition.getPositionX()].getFigure();
}


bool Board::isWithinBoard(Position position) {
    if ((0 <= position.getPositionX() && position.getPositionX() <= 7) && (0 <= position.getPositionY() && position.getPositionY() <= 7)) {
        return true;
    }

    return false;
}
