#include "Queen.h"
#include "Board.h"

extern Board board; 

Queen::Queen(Color color, Position position): Figure(), Bishop(color, position), Rook(color, position) {
    setTypeFigure("Q");
    setColor(color);
    setPosition(position);
}

Queen::~Queen() {
}

bool Queen::isValidMove(Position newPosition, Figure* figure) {

    if (Bishop::isValidMove(newPosition, figure) || Rook::isValidMove(newPosition, figure)) {
       
        return true;
    }

    return false;
}

