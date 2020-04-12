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
    for(int row = 7; row >= 0; row--)
    {
        std::cout << "   ";
        for(int col=0; col<8; ++col)
        {
            std::cout << "-----";
        }
        std::cout << "-\n";

        //print vertical row divider and chess piece
        std::cout << row + 1 << "  ";
        for(int col=0; col<8; ++col)
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
    for(int col=0; col<8; ++col)
    {
        std::cout << "-----";
    }
    std::cout << "-\n";

    //print Letters on the bottom of the board
    std::cout << "   ";
    for(int col=0; col<8; ++col)
    {
        std::cout << "  " << (char)(col + 97) << "  ";
    }
    std::cout << "\n\n";
}


void Board::changeFigure(Position position, Figure* figure)
{
    board[position.ypos][position.xpos].clear();
    board[position.ypos][position.xpos].setFigure(figure);
    return;
}


void Board::initializeFigures()
{
    // Pawns
    for(int col=0; col<8; ++col)
    {
        Position blackPawnPos = {col,6};
        board[blackPawnPos.ypos][blackPawnPos.xpos].setFigure(new Pawn(Black, blackPawnPos));

        Position whitePawnPos = {col,1};
        board[whitePawnPos.ypos][blackPawnPos.xpos].setFigure(new Pawn(White, whitePawnPos));
    }


    // Rooks
    Position whiteRookPos = {0,0};
    board[whiteRookPos.ypos][whiteRookPos.xpos].setFigure(new Rook(White, whiteRookPos));

    Position whiteRookPos2 = {7,0};
    board[whiteRookPos2.ypos][whiteRookPos2.xpos].setFigure(new Rook(White, whiteRookPos2));

    Position blackRookPos = {0,7};
    board[blackRookPos.ypos][blackRookPos.xpos].setFigure(new Rook(Black, blackRookPos));

    Position blackRookPos2 = {7,7};
    board[blackRookPos2.ypos][blackRookPos2.xpos].setFigure(new Rook(Black, blackRookPos2));


    // Knights
    Position whiteKnightPos = {1,0};
    board[whiteKnightPos.ypos][whiteKnightPos.xpos].setFigure(new Knight(White, whiteKnightPos));

    Position whiteKnightPos2 = {6,0};
    board[whiteKnightPos2.ypos][whiteKnightPos2.xpos].setFigure(new Knight(White, whiteKnightPos2));

    Position blackKnightPos = {1,7};
    board[blackKnightPos.ypos][blackKnightPos.xpos].setFigure(new Knight(Black, blackKnightPos));

    Position blackKnightPos2 = {6,7};
    board[blackKnightPos2.ypos][blackKnightPos2.xpos].setFigure(new Knight(Black, blackKnightPos2));


    // Bishops
    Position whiteBishopPos = {2,0};
    board[whiteBishopPos.ypos][whiteBishopPos.xpos].setFigure(new Bishop(White, whiteBishopPos));

    Position whiteBishopPos2 = {5,0};
    board[whiteBishopPos2.ypos][whiteBishopPos2.xpos].setFigure(new Bishop(White, whiteBishopPos2));

    Position blackBishopPos = {2,7};
    board[blackBishopPos.ypos][blackBishopPos.xpos].setFigure(new Bishop(Black, blackBishopPos));

    Position blackBishopPos2 = {5,7};
    board[blackBishopPos2.ypos][blackBishopPos2.xpos].setFigure(new Bishop(Black, blackBishopPos2));


    // Kings
    Position whiteKingPos = {4,0};
    board[whiteKingPos.ypos][whiteKingPos.xpos].setFigure(new King(White, whiteKingPos));

    Position blackKingPos = {4,7};
    board[blackKingPos.ypos][blackKingPos.xpos].setFigure(new King(Black, blackKingPos));


    // Queens
    Position whiteQueenPos = {3,0};
    board[whiteQueenPos.ypos][whiteQueenPos.xpos].setFigure(new Queen(White, whiteQueenPos));

    Position blackQueenPos = {3,7};
    board[blackQueenPos.ypos][blackQueenPos.xpos].setFigure(new Queen(Black, blackQueenPos));
}


bool Board::moveFigure(Position fromPosition, Position toPosition)
{
    bool moveCompleted = false;

    Figure* piece = board[fromPosition.ypos][fromPosition.xpos].getFigure();

    //check weather we can make this move - is there a piece, is it possible this piece to make this move, is it within the board
    if(piece != nullptr && piece->isValidMove(toPosition, piece) && isWithinBoard(toPosition))
    {
        piece->print();
        piece->setPosition(toPosition);
        board[toPosition.ypos][toPosition.xpos].setFigure(piece);
        board[fromPosition.ypos][fromPosition.xpos].clear();

        moveCompleted = true;
    }

    return moveCompleted;
}


Figure* Board::getFigure(Position figurePosition)
{
    return board[figurePosition.ypos][figurePosition.xpos].getFigure();
}


bool Board::isWithinBoard(Position position)
{
    if((0 <= position.xpos && position.xpos <= 7) && (0 <= position.ypos && position.ypos <= 7))
    {
        return true;
    }
    return false;
}
