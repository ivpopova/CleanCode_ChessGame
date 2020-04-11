#include <iostream>
#include <cmath>
#include "Knight.h"
#include "Board.h"

extern Board board; //board is declared in the main and extern lets compiler know this

/**@summary Constructor
 * @color Color of the new piece
 * @pos Position of the new piece
 */
Knight::Knight(Color color, Position pos)
{
    this->type = "N";
    this->color = color;
    this->position = pos;
}

/**@summary Default Destructor
 */
Knight::~Knight()
{ }

/**@summary Validates a move by the piece logic of moving
 * @param moteToPos - Starting position of the piece
 * @return bool - Success or Failure
 */
bool Knight::validateMove(Position moveToPos, Figure* piece)
{
    bool validMove = false;

    //check if it's possible to move the knight to this square
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

    if(((abs(position.xpos - moveToPos.xpos) == 2) && (abs(position.ypos - moveToPos.ypos) == 1)) ||
       ((abs(position.xpos - moveToPos.xpos) == 1) && (abs(position.ypos  - moveToPos.ypos) == 2)))
    {
        validMove = true;
    }

    if(validMove && (board.getPiece(moveToPos) != nullptr) && (board.getPiece(moveToPos)->getType() == "K"))
    {
        std::cout << ((this->color == Color::White) ? "White's " : "Black's ") << "king is checked!";
    }
    return validMove;
}
