#pragma once
#include"Square.h"
#include <iostream>
#include <string>
using namespace std;

const int BOARD_SIZE = 8;

class Board
{
	Square currentBoard[BOARD_SIZE][BOARD_SIZE];
	Colors nextTurn = WHITE;

	bool moveKing(Square* thisKing, Square* thatSpace);
	bool moveQueen(Square* thisQueen, Square* thatSpace);
	bool moveBishop(Square* thisBishop, Square* thatSpace);
	bool moveKnight(Square* thisKnight, Square* thatSpace);
	bool moveRook(Square* thisRook, Square* thatSpace);
	bool movePawn(Square* thisPawn, Square* thatSpace);
	bool makeMove(int oldPositionX, int oldPositionY, int newPositionX, int newPositionY);
	void printBoard();

public:
	Square* getSquare(int positionX, int positionY);
	void setSquare(Square* newSquare, int positionX, int positionY);
	bool makeNextMove();

	void setBoard();
	bool playGame();
};
