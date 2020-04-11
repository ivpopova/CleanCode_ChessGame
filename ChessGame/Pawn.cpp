#include <cstring>
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Board.h"

extern Board board; 

Pawn::Pawn(Color color, Position pos)
{
    this->type = "P";
    this->color = color;
    this->position = pos;
    this->doubleJumpAvailable = true;
}


Pawn::~Pawn()
{ }

Figure* Pawn::promote(Position position)
{
    std::string input;
    Figure* piece = nullptr;
    std::cout << "Choose with witch piece to replace this pawn (Q - Queen, R - Rook, N - Knight, B - Bishop)";
    while(std::cin >> input)
    {
        if(input == "Q" || input == "q")
        {
            if(color == Color::White)
            {
                piece = new Queen(Color::White, position);
            }
            else
            {
                piece = new Queen(Color::Black, position);
            }
            board.changePiece(position, piece);
            return piece;
        }
        if(input == "R"|| input == "r")
        {
            if(color == Color::White)
            {
                piece = new Rook(Color::White, position);
            }
            else
            {
                piece = new Rook(Color::Black, position);
            }
            board.changePiece(position, piece);
            return piece;
        }
        if(input == "N" || input == "n")
        {
            if(color == Color::White)
            {
                 piece = new Knight(Color::White, position);
            }
            else
            {
                 piece = new Knight(Color::Black, position);
            }
            board.changePiece(position, piece);
            return piece;
        }
        if(input == "B" || input == "b")
        {
            if(color == Color::White)
            {
                piece = new Bishop(Color::White, position);
            }
            else
            {
                 piece = new Bishop(Color::Black, position);
            }
            board.changePiece(position, piece);
            return piece;
        }
        std::cout << "Invalid choice, choose again (Q - Queen, R - Rook, N - Knight, B - Bishop)";
    }
    return piece;
}


bool Pawn::validateMove(Position moveToPos, Figure* piece)
{
    bool validMove = false;

    int allowableMove1 = 1;
    int allowableMove2 = 2;
    //if black on turn, the movement is downwards on board
    if(color == Color::Black)
    {
        allowableMove1 = -1;
        allowableMove2 = -2;
    }

    Position moveToPosTemp(position.ypos + allowableMove1, position.xpos);

    if(moveToPos.ypos == (position.ypos + allowableMove1) && moveToPos.xpos == position.xpos && board.getPiece(moveToPos) == nullptr)
    {
        //pawn promotion
        if(moveToPos.ypos == 7 || moveToPos.ypos == 0)
        {
            piece = promote(moveToPos);
        }
        validMove = true;
        doubleJumpAvailable = false;
    }
    else if(doubleJumpAvailable == true && moveToPos.ypos == (position.ypos + allowableMove2) && moveToPos.xpos == position.xpos
            && board.getPiece(moveToPos) == nullptr && board.getPiece(moveToPosTemp) == nullptr)
    {
        validMove = true;
        doubleJumpAvailable = false;
    }
    else if(moveToPos.ypos == position.ypos + allowableMove1 && (moveToPos.xpos == position.xpos - 1 || moveToPos.xpos == position.xpos + 1))
    {
        //check if there is a piece of the opposite color
        if(board.getPiece(moveToPos) != nullptr && (board.getPiece(moveToPos)->getColor() != this->color))
        {
            if(moveToPos.ypos == 7 || moveToPos.ypos == 0)
            {
                piece = promote(moveToPos);
                piece->print();
            }
            validMove = true;
            doubleJumpAvailable = false;
        }
    }

    if(validMove && (board.getPiece(moveToPos) != nullptr) && (board.getPiece(moveToPos)->getType() == "K"))
    {
        std::cout << ((this->color == Color::White) ? "White's " : "Black's ") << "king is checked!";
    }

    return validMove;
}

