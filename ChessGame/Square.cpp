#include "Square.h"
#include "Figure.h"

Square::Square()
{
    chessPiece = nullptr;
}

Square::~Square()
{ }

Figure* Square::getPiece()
{
    return chessPiece;
}


void Square::setPiece(Figure* piece)
{
    this->chessPiece = piece;
}


void Square::clear()
{
    this->chessPiece = nullptr;
}

void Square::print()
{
    chessPiece->print();
}
