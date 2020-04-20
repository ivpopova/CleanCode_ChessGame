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
    setTypeFigure("P");
    setColor(color);
    setPosition(position);
    this->isDoubleJumpAvailable = true;
}


Pawn::~Pawn()
{ }

Figure* Pawn::promote(Position position)
{
    std::string input;
    Figure* figure = nullptr;
    std::cout << "Choose with which piece to replace this pawn (Q - Queen, R - Rook, N - Knight, B - Bishop)";
    while(std::cin >> input)
    {
        if(input == "Q" || input == "q")
        {
            if(getColor() == Color::White)
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
            if(getColor() == Color::White)
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
            if(getColor() == Color::White)
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
            if(getColor() == Color::White)
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


bool Pawn::isValidMove(Position position, Figure* figure)
{
    bool isValid = false;

    int allowableMove1 = 1;
    int allowableMove2 = 2;

    //if black on turn, the movement is downwards on board
    if(getColor() == Color::Black)
    {
        allowableMove1 = -1;
        allowableMove2 = -2;
    }

    Position newPositionTemp(getCurrentPosition().getY() + allowableMove1, getCurrentPosition().getX());

    if(position.getY() == (getCurrentPosition().getY() + allowableMove1) && position.getX() == getCurrentPosition().getX() && board.getFigure(position) == nullptr)
    {
        //pawn promotion
        if(position.getY() == 7 || position.getY() == 0)
        {
            figure = promote(position);
        }

        isValid = true;
        isDoubleJumpAvailable = false;
    }
    else if(isDoubleJumpAvailable == true && position.getY() == (getCurrentPosition().getY() + allowableMove2) && position.getX() == getCurrentPosition().getX()
            && board.getFigure(position) == nullptr && board.getFigure(newPositionTemp) == nullptr)
    {
        isValid = true;
        isDoubleJumpAvailable = false;
    }
    else if(position.getY() == getCurrentPosition().getY() + allowableMove1 && (position.getX() == getCurrentPosition().getX() - 1 || position.getX() == getCurrentPosition().getX() + 1))
    {
        //check if there is a piece of the opposite color
        if(board.getFigure(position) != nullptr && (board.getFigure(position)->getColor() != this->getColor()))
        {
            if(position.getY() == 7 || position.getY() == 0)
            {
                figure = promote(position);
                figure->print();
            }

            isValid = true;
            isDoubleJumpAvailable = false;
        }
    }

    if(isValid && (board.getFigure(position) != nullptr) && (board.getFigure(position)->getTypeFigure() == "K"))
    {
        std::cout << ((this->getColor() == Color::White) ? "White's " : "Black's ") << "king is checked!";
    }


    return isValid;
}

