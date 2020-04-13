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

void Board::print()
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
    board[position.y][position.x].clearFigure();
    board[position.y][position.x].setFigure(figure);
}


void Board::initializeFigures()
{
    // Pawns
    for(int col=0; col< BOARD_SIZE; ++col)
    {
        Position blackPawnPos = {col,6};
        board[blackPawnPos.y][blackPawnPos.x].setFigure(new Pawn(Black, blackPawnPos));

        Position whitePawnPos = {col,1};
        board[whitePawnPos.y][blackPawnPos.x].setFigure(new Pawn(White, whitePawnPos));
    }


    // Rooks
    Position whiteRookPos = {0,0};
    board[whiteRookPos.y][whiteRookPos.x].setFigure(new Rook(White, whiteRookPos));

    Position whiteRookPos2 = {7,0};
    board[whiteRookPos2.y][whiteRookPos2.x].setFigure(new Rook(White, whiteRookPos2));

    Position blackRookPos = {0,7};
    board[blackRookPos.y][blackRookPos.x].setFigure(new Rook(Black, blackRookPos));

    Position blackRookPos2 = {7,7};
    board[blackRookPos2.y][blackRookPos2.x].setFigure(new Rook(Black, blackRookPos2));


    // Knights
    Position whiteKnightPos = {1,0};
    board[whiteKnightPos.y][whiteKnightPos.x].setFigure(new Knight(White, whiteKnightPos));

    Position whiteKnightPos2 = {6,0};
    board[whiteKnightPos2.y][whiteKnightPos2.x].setFigure(new Knight(White, whiteKnightPos2));

    Position blackKnightPos = {1,7};
    board[blackKnightPos.y][blackKnightPos.x].setFigure(new Knight(Black, blackKnightPos));

    Position blackKnightPos2 = {6,7};
    board[blackKnightPos2.y][blackKnightPos2.x].setFigure(new Knight(Black, blackKnightPos2));


    // Bishops
    Position whiteBishopPos = {2,0};
    board[whiteBishopPos.y][whiteBishopPos.x].setFigure(new Bishop(White, whiteBishopPos));

    Position whiteBishopPos2 = {5,0};
    board[whiteBishopPos2.y][whiteBishopPos2.x].setFigure(new Bishop(White, whiteBishopPos2));

    Position blackBishopPos = {2,7};
    board[blackBishopPos.y][blackBishopPos.x].setFigure(new Bishop(Black, blackBishopPos));

    Position blackBishopPos2 = {5,7};
    board[blackBishopPos2.y][blackBishopPos2.x].setFigure(new Bishop(Black, blackBishopPos2));


    // Kings
    Position whiteKingPos = {4,0};
    board[whiteKingPos.y][whiteKingPos.x].setFigure(new King(White, whiteKingPos));

    Position blackKingPos = {4,7};
    board[blackKingPos.y][blackKingPos.x].setFigure(new King(Black, blackKingPos));


    // Queens
    Position whiteQueenPos = {3,0};
    board[whiteQueenPos.y][whiteQueenPos.x].setFigure(new Queen(White, whiteQueenPos));

    Position blackQueenPos = {3,7};
    board[blackQueenPos.y][blackQueenPos.x].setFigure(new Queen(Black, blackQueenPos));
}


bool Board::moveFigure(Position currentPosition, Position newPosition)
{
    bool isMoveCompleted = false;

    Figure* figure = board[currentPosition.y][currentPosition.x].getFigure();

    //check weather we can make this move - is there a piece, is it possible this piece to make this move, is it within the board
    if(figure != nullptr && figure->isValidMove(newPosition, figure) && isWithinBoard(newPosition))
    {
        figure->print();
        figure->setPosition(newPosition);
        board[newPosition.y][newPosition.x].setFigure(figure);
        board[currentPosition.y][currentPosition.x].clearFigure();

        isMoveCompleted = true;
    }

    return isMoveCompleted;
}


Figure* Board::getFigure(Position figurePosition)
{
    return board[figurePosition.y][figurePosition.x].getFigure();
}


bool Board::isWithinBoard(Position position)
{
    if((0 <= position.x && position.x <= 7) && (0 <= position.y && position.y <= 7))
    {
        return true;
    }
    return false;
}
