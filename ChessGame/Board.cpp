#include "Board.h"
#include "Figure.h"
#include "Pawn.h"
#include "Rook.h"
#include "Queen.h"
#include "Knight.h"
#include "King.h"
#include "Bishop.h"


Board::Board()
{
    initializeFigures();
}


Board::~Board()
{ }

void Board::printBoard()
{
    //print horizontal divider for the top of the board
    for(int row = BOARD_SIZE-1; row >= 0; row--)
    {
        std::cout << "   ";
        for(int col=0; col< BOARD_SIZE; ++col)
        {
            std::cout << "-----";
        }
        std::cout << "-\n";

        //print vertical row divider and chess piece
        std::cout << row + 1 << "  ";
        for(int col=0; col< BOARD_SIZE; ++col)
        {
            std::cout << "| ";
            Figure *currentFigure = board[row][col].getFigure();
            if(currentFigure != nullptr)
            {
                currentFigure->print();
            }
            else
            {
                std::cout << "  ";
            }
            std::cout << " ";
        }
        std::cout << "|" << std::endl;
    }

    //print horizontal divider for the bottom of the board
    std::cout << "   ";
    for(int col=0; col< BOARD_SIZE; ++col)
    {
        std::cout << "-----";
    }
    std::cout << "-\n";

    //print Letters on the bottom of the board
    std::cout << "   ";
    for(int col=0; col< BOARD_SIZE; ++col)
    {
        std::cout << "  " << (char)(col + 97) << "  ";
    }
    std::cout << "\n\n";
}


void Board::changeFigure(Position position, Figure* figure)
{
    board[position.getY()][position.getX()].clearFigure();
    board[position.getY()][position.getX()].setFigure(figure);
}


void Board::initializeFigures()
{
    // Pawns
    for(int col=0; col< BOARD_SIZE; ++col)
    {
        Position blackPawn(col,6);
        board[blackPawn.getY()][blackPawn.getX()].setFigure(new Pawn(Black, blackPawn));

        Position whitePawn(col,1);
        board[whitePawn.getY()][blackPawn.getX()].setFigure(new Pawn(White, whitePawn));
    }


    // Rooks
    Position whiteLeftRook(0,0);
    board[whiteLeftRook.getY()][whiteLeftRook.getX()].setFigure(new Rook(White, whiteLeftRook));

    Position whiteRightRook (7,0);
    board[whiteRightRook.getY()][whiteRightRook.getX()].setFigure(new Rook(White, whiteRightRook));

    Position blackLeftRook (0,7);
    board[blackLeftRook.getY()][blackLeftRook.getX()].setFigure(new Rook(Black, blackLeftRook));

    Position blackRightRook (7,7);
    board[blackRightRook.getY()][blackRightRook.getX()].setFigure(new Rook(Black, blackRightRook));


    // Knights
    Position whiteLeftKnight (1,0);
    board[whiteLeftKnight.getY()][whiteLeftKnight.getX()].setFigure(new Knight(White, whiteLeftKnight));

    Position whiteRightKnight (6,0);
    board[whiteRightKnight.getY()][whiteRightKnight.getX()].setFigure(new Knight(White, whiteRightKnight));

    Position blackLeftKnight (1,7);
    board[blackLeftKnight.getY()][blackLeftKnight.getX()].setFigure(new Knight(Black, blackLeftKnight));

    Position blackRightKnight (6,7);
    board[blackRightKnight.getY()][blackRightKnight.getX()].setFigure(new Knight(Black, blackRightKnight));


    // Bishops
    Position whiteLeftBishop (2,0);
    board[whiteLeftBishop.getY()][whiteLeftBishop.getX()].setFigure(new Bishop(White, whiteLeftBishop));

    Position whiteRightBishop (5,0);
    board[whiteRightBishop.getY()][whiteRightBishop.getX()].setFigure(new Bishop(White, whiteRightBishop));

    Position blackLeftBishop (2,7);
    board[blackLeftBishop.getY()][blackLeftBishop.getX()].setFigure(new Bishop(Black, blackLeftBishop));

    Position blackRightBishop (5,7);
    board[blackRightBishop.getY()][blackRightBishop.getX()].setFigure(new Bishop(Black, blackRightBishop));


    // Kings
    Position whiteKing (4,0);
    board[whiteKing.getY()][whiteKing.getX()].setFigure(new King(White, whiteKing));

    Position blackKing (4,7);
    board[blackKing.getY()][blackKing.getX()].setFigure(new King(Black, blackKing));


    // Queens
    Position whiteQueen (3,0);
    board[whiteQueen.getY()][whiteQueen.getX()].setFigure(new Queen(White, whiteQueen));

    Position blackQueen (3,7);
    board[blackQueen.getY()][blackQueen.getX()].setFigure(new Queen(Black, blackQueen));
}


bool Board::moveFigure(Position currentPosition, Position newPosition)
{
    bool isMoveCompleted = false;

    Figure* figure = board[currentPosition.getY()][currentPosition.getX()].getFigure();

    
    if(figure != nullptr && figure->isValidMove(newPosition, figure) && isWithinBoard(newPosition))
    {
        figure->print();
        figure->setPosition(newPosition);
        board[newPosition.getY()][newPosition.getX()].setFigure(figure);
        board[currentPosition.getY()][currentPosition.getX()].clearFigure();

        isMoveCompleted = true;
    }

    return isMoveCompleted;
}


Figure* Board::getFigure(Position figurePosition)
{
    return board[figurePosition.getY()][figurePosition.getX()].getFigure();
}


bool Board::isWithinBoard(Position position)
{
    if((0 <= position.getX() && position.getX() <= 7) && (0 <= position.getY() && position.getY() <= 7))
    {
        return true;
    }
    return false;
}
