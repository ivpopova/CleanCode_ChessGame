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
    this->isDoubleJumpAvailable = true;
}


Pawn::~Pawn()
{ }

Figure* Pawn::promote(Position position)
{
    std::string input;
    Figure* figure = nullptr;
    std::cout << "Choose with witch piece to replace this pawn (Q - Queen, R - Rook, N - Knight, B - Bishop)";
    while(std::cin >> input)
    {
        if(input == "Q" || input == "q")
        {
            if(color == Color::White)
            {
                figure = new Queen(Color::White, position);
            }
            else
            {
                figure = new Queen(Color::Black, position);
            }
            board.changeFigure(position, figure);
            return figure;
        }
        if(input == "R"|| input == "r")
        {
            if(color == Color::White)
            {
                figure = new Rook(Color::White, position);
            }
            else
            {
                figure = new Rook(Color::Black, position);
            }
            board.changeFigure(position, figure);
            return figure;
        }
        if(input == "N" || input == "n")
        {
            if(color == Color::White)
            {
                 figure = new Knight(Color::White, position);
            }
            else
            {
                 figure = new Knight(Color::Black, position);
            }
            board.changeFigure(position, figure);
            return figure;
        }
        if(input == "B" || input == "b")
        {
            if(color == Color::White)
            {
                figure = new Bishop(Color::White, position);
            }
            else
            {
                 figure = new Bishop(Color::Black, position);
            }
            board.changeFigure(position, figure);
            return figure;
        }
        std::cout << "Invalid choice, choose again (Q - Queen, R - Rook, N - Knight, B - Bishop)";
    }
    return figure;
}


bool Pawn::isValidMove(Position newPosition, Figure* figure)
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

    if(newPosition.y == (position.y + allowableMove1) && newPosition.x == position.x && board.getFigure(newPosition) == nullptr)
    {
        //pawn promotion
        if(newPosition.y == 7 || newPosition.y == 0)
        {
            figure = promote(newPosition);
        }
        isValid = true;
        isDoubleJumpAvailable = false;
    }
    else if(isDoubleJumpAvailable == true && newPosition.y == (position.y + allowableMove2) && newPosition.x == position.x
            && board.getFigure(newPosition) == nullptr && board.getFigure(moveToPosTemp) == nullptr)
    {
        isValid = true;
        isDoubleJumpAvailable = false;
    }
    else if(newPosition.y == position.y + allowableMove1 && (newPosition.x == position.x - 1 || newPosition.x == position.x + 1))
    {
        //check if there is a piece of the opposite color
        if(board.getFigure(newPosition) != nullptr && (board.getFigure(newPosition)->getColor() != this->color))
        {
            if(newPosition.y == 7 || newPosition.y == 0)
            {
                figure = promote(newPosition);
                figure->print();
            }
            isValid = true;
            isDoubleJumpAvailable = false;
        }
    }

    if(isValid && (board.getFigure(newPosition) != nullptr) && (board.getFigure(newPosition)->getType() == "K"))
    {
        std::cout << ((this->color == Color::White) ? "White's " : "Black's ") << "king is checked!";
    }

    return isValid;
}

