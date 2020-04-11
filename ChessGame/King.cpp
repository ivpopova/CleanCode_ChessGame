#include <iostream>
#include "Figure.h"
#include "King.h"
#include "Board.h"

extern Board board; //board is declared in the main and extern lets compiler know this

/**@summary Constructor
 * @color Color of the new piece
 * @pos Position of the new piece
 */
King::King(Color color, Position pos)
{
    this->type = "K";
    this->color = color;
    this->position = pos;
}

/**@summary Default Destructor
 */
King::~King()
{ }

/**@summary Validates a move by the piece logic of moving
 * @param moteToPos - Starting position of the piece
 * @return bool - Success or Failure
 */
bool King::validateMove(Position moveToPos, Figure* piece)
{
 bool validMove = false;

    //check if it's possible to move the king to this square
    if((board.getPiece(moveToPos) == nullptr) ||
       (board.getPiece(moveToPos) != nullptr && (board.getPiece(moveToPos)->getColor() != this->color)))
    {
        validMove = true;
    }
    else
    {
        validMove = false;
        return validMove;
    }

    //(x-1,y+1), (x,y+1), (x+1,y+1),
    if(moveToPos.ypos == (position.ypos + 1) && moveToPos.xpos == (position.xpos - 1))
    {
        validMove = true;
    }
    else if(moveToPos.ypos == (position.ypos + 1) && moveToPos.xpos == position.xpos)
    {
        validMove = true;
    }
    else if(moveToPos.ypos == (position.ypos + 1) && moveToPos.xpos == (position.xpos + 1))
    {
        validMove = true;
    }
    //(x-1,y), (x+1,y),
    else if(moveToPos.ypos == position.ypos && moveToPos.xpos == (position.xpos - 1))
    {
        validMove = true;
    }
    else if(moveToPos.ypos == position.ypos && moveToPos.xpos == (position.xpos + 1))
    {
        validMove = true;
    }
    //(x-1,y-1), (x,y-1), (x+1,y-1),
    else if(moveToPos.ypos == (position.ypos - 1) && moveToPos.xpos == (position.xpos - 1))
    {
        validMove = true;
    }
    else if(moveToPos.ypos == (position.ypos - 1) && moveToPos.xpos == position.xpos)
    {
        validMove = true;
    }
    else if(moveToPos.ypos == (position.ypos - 1) && moveToPos.xpos == (position.xpos + 1))
    {
        validMove = true;
    }
    else
    {
        validMove = false;
    }

    if(validMove && (board.getPiece(moveToPos) != nullptr) && (board.getPiece(moveToPos)->getType() == "K"))
    {
        std::cout << ((this->color == Color::White) ? "White's " : "Black's ") << "king is checked!";
    }

    return validMove;
}
