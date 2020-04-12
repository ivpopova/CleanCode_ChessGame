#include <cstring>
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Board.h"

extern Board board; 

Pawn::Pawn(Color color, Position position)
{
    this->type = "P";
    this->color = color;
    this->position = position;
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
            board.changeFigure(position, piece);
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
            board.changeFigure(position, piece);
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
            board.changeFigure(position, piece);
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
            board.changeFigure(position, piece);
            return piece;
        }
        std::cout << "Invalid choice, choose again (Q - Queen, R - Rook, N - Knight, B - Bishop)";
    }
    return piece;
}


bool Pawn::isValidMove(Position moveToPosition, Figure* figure)
{
    bool isValid = false;

    int allowableMove1 = 1;
    int allowableMove2 = 2;
    //if black on turn, the movement is downwards on board
    if(color == Color::Black)
    {
        allowableMove1 = -1;
        allowableMove2 = -2;
    }

    Position moveToPosTemp(position.y + allowableMove1, position.x);

    if(moveToPosition.y == (position.y + allowableMove1) && moveToPosition.x == position.x && board.getFigure(moveToPosition) == nullptr)
    {
        //pawn promotion
        if(moveToPosition.y == 7 || moveToPosition.y == 0)
        {
            figure = promote(moveToPosition);
        }
        isValid = true;
        doubleJumpAvailable = false;
    }
    else if(doubleJumpAvailable == true && moveToPosition.y == (position.y + allowableMove2) && moveToPosition.x == position.x
            && board.getFigure(moveToPosition) == nullptr && board.getFigure(moveToPosTemp) == nullptr)
    {
        isValid = true;
        doubleJumpAvailable = false;
    }
    else if(moveToPosition.y == position.y + allowableMove1 && (moveToPosition.x == position.x - 1 || moveToPosition.x == position.x + 1))
    {
        //check if there is a piece of the opposite color
        if(board.getFigure(moveToPosition) != nullptr && (board.getFigure(moveToPosition)->getColor() != this->color))
        {
            if(moveToPosition.y == 7 || moveToPosition.y == 0)
            {
                figure = promote(moveToPosition);
                figure->print();
            }
            isValid = true;
            doubleJumpAvailable = false;
        }
    }

    if(isValid && (board.getFigure(moveToPosition) != nullptr) && (board.getFigure(moveToPosition)->getType() == "K"))
    {
        std::cout << ((this->color == Color::White) ? "White's " : "Black's ") << "king is checked!";
    }

    return isValid;
}

