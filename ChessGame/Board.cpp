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
    board[position.getCoordinateY()][position.getCoordinateX()].clearFigure();
    board[position.getCoordinateY()][position.getCoordinateX()].setFigure(figure);
}


void Board::initializeFigures() {
    // Pawns
    for (int col=0; col< BOARD_SIZE; ++col) {
        Position blackPawn(col,6);
        board[blackPawn.getCoordinateY()][blackPawn.getCoordinateX()].setFigure(new Pawn(Black, blackPawn));

        Position whitePawn(col,1);
        board[whitePawn.getCoordinateY()][blackPawn.getCoordinateX()].setFigure(new Pawn(White, whitePawn));
    }


    // Rooks
    Position whiteLeftRook(0,0);
    board[whiteLeftRook.getCoordinateY()][whiteLeftRook.getCoordinateX()].setFigure(new Rook(White, whiteLeftRook));

    Position whiteRightRook (7,0);
    board[whiteRightRook.getCoordinateY()][whiteRightRook.getCoordinateX()].setFigure(new Rook(White, whiteRightRook));

    Position blackLeftRook (0,7);
    board[blackLeftRook.getCoordinateY()][blackLeftRook.getCoordinateX()].setFigure(new Rook(Black, blackLeftRook));

    Position blackRightRook (7,7);
    board[blackRightRook.getCoordinateY()][blackRightRook.getCoordinateX()].setFigure(new Rook(Black, blackRightRook));


    // Knights
    Position whiteLeftKnight (1,0);
    board[whiteLeftKnight.getCoordinateY()][whiteLeftKnight.getCoordinateX()].setFigure(new Knight(White, whiteLeftKnight));

    Position whiteRightKnight (6,0);
    board[whiteRightKnight.getCoordinateY()][whiteRightKnight.getCoordinateX()].setFigure(new Knight(White, whiteRightKnight));

    Position blackLeftKnight (1,7);
    board[blackLeftKnight.getCoordinateY()][blackLeftKnight.getCoordinateX()].setFigure(new Knight(Black, blackLeftKnight));

    Position blackRightKnight (6,7);
    board[blackRightKnight.getCoordinateY()][blackRightKnight.getCoordinateX()].setFigure(new Knight(Black, blackRightKnight));


    // Bishops
    Position whiteLeftBishop (2,0);
    board[whiteLeftBishop.getCoordinateY()][whiteLeftBishop.getCoordinateX()].setFigure(new Bishop(White, whiteLeftBishop));

    Position whiteRightBishop (5,0);
    board[whiteRightBishop.getCoordinateY()][whiteRightBishop.getCoordinateX()].setFigure(new Bishop(White, whiteRightBishop));

    Position blackLeftBishop (2,7);
    board[blackLeftBishop.getCoordinateY()][blackLeftBishop.getCoordinateX()].setFigure(new Bishop(Black, blackLeftBishop));

    Position blackRightBishop (5,7);
    board[blackRightBishop.getCoordinateY()][blackRightBishop.getCoordinateX()].setFigure(new Bishop(Black, blackRightBishop));


    // Kings
    Position whiteKing (4,0);
    board[whiteKing.getCoordinateY()][whiteKing.getCoordinateX()].setFigure(new King(White, whiteKing));

    Position blackKing (4,7);
    board[blackKing.getCoordinateY()][blackKing.getCoordinateX()].setFigure(new King(Black, blackKing));


    // Queens
    Position whiteQueen (3,0);
    board[whiteQueen.getCoordinateY()][whiteQueen.getCoordinateX()].setFigure(new Queen(White, whiteQueen));

    Position blackQueen (3,7);
    board[blackQueen.getCoordinateY()][blackQueen.getCoordinateX()].setFigure(new Queen(Black, blackQueen));
}


bool Board::moveFigure(Position currentPosition, Position newPosition) {
    bool isMoveCompleted = false;

    Figure* figure = board[currentPosition.getCoordinateY()][currentPosition.getCoordinateX()].getFigure();
    if (figure != nullptr && figure->isValidMove(newPosition, figure) && isWithinBoard(newPosition)) {
        figure->print();
        figure->setCurrentPosition(newPosition);

        board[newPosition.getCoordinateY()][newPosition.getCoordinateX()].setFigure(figure);
        board[currentPosition.getCoordinateY()][currentPosition.getCoordinateX()].clearFigure();

        isMoveCompleted = true;
    }

    return isMoveCompleted;
}


Figure* Board::getFigureFromPosition(Position figurePosition) {
    return board[figurePosition.getCoordinateY()][figurePosition.getCoordinateX()].getFigure();
}


bool Board::isWithinBoard(Position position) {
    if ((0 <= position.getCoordinateX() && position.getCoordinateX() <= 7) && (0 <= position.getCoordinateY() && position.getCoordinateY() <= 7)) {
        return true;
    }

    return false;
}
