#include"Board.h"

void Board::printBoard() {

	cout << " y: ";
	for (int  column = 0; column < BOARD_SIZE; column++) {
		cout << column << " ";
	}
	cout << endl << "x:" << endl;

	for (int row = 0; row < BOARD_SIZE; row++)
	{
		cout << " " << row << "   ";
		for (int column = 0; column < BOARD_SIZE; column++)
		{
			Figures currentFigure = currentBoard[row][column].getFigure();
			Colors currentColor = currentBoard[row][column].getColor();

			switch (currentFigure)
			{
			case KING: (currentColor == WHITE) ? cout << " K " : cout << " k ";
				break;
			case QUEEN: (currentColor == WHITE) ? cout << " Q " : cout << " q ";
				break;
			case BISHOP:(currentColor == WHITE) ? cout << " B " : cout << " b ";
				break;
			case KNIGHT:(currentColor == WHITE) ? cout << " H " : cout << " h ";
				break;
			case ROOK: (currentColor == WHITE) ? cout << " R " : cout << " r ";
				break;
			case PAWN: (currentColor == WHITE) ? cout << " P " : cout << " p ";
				break;
			case EMPTY: cout << "   ";
				break;
			default: cout << "XXX";
				break;
			}

		}
		cout << endl;
	}

}

Square* Board::getSquare(int positionX, int positionY){
		return &currentBoard[positionX][positionY];
}

void Board::setSquare(Square* newSquare, int positionX, int positionY){
	currentBoard[positionX][positionY] = *newSquare;
}

bool Board::makeNextMove() {

	string inputMove;
	int oldPositionX, newPositionX, oldPositionY, oldPositionY;
	bool isValidMove = false;

	while (!isValidMove)
	{
		(nextTurn == WHITE) ? cout << "White's turn" << endl : cout << "Black's turn" << endl;
		cout << "Type in your move as a single four character string. Use x-coordinates first in each pair." << endl;
		cin >> inputMove;

		oldPositionX = inputMove[0] - '0';
		oldPositionY = inputMove[1] - '0';
		newPositionX = inputMove[2] - '0';
		oldPositionY = inputMove[3] - '0';

		if (getSquare(oldPositionX, oldPositionY)->getColor() == nextTurn){

			if (makeMove(oldPositionX, oldPositionY, newPositionX, oldPositionY) == false){
				cout << "Invalid move, try again." << endl;
			}
			else {
				isValidMove = true;
			}		
		}
		else {
			cout << "That's not your piece. Try again." << endl;
		}
			
	}

	if (getSquare(newPositionX, oldPositionY)->getFigure() == KING) {
		if (getSquare(oldPositionX, oldPositionY)->getColor() == WHITE)
		{
			cout << "WHITE WINS" << endl;
			return false;
		}
		else

		{
			cout << "BLACK WINS" << endl;
			return false;
		}
	}

	if (nextTurn == BLACK) {
		nextTurn = WHITE;
	}
	else {
		nextTurn = BLACK;
	}

	return true;

}

void Board::setBoard()
{
	currentBoard[0][0].setFigureAndColor(ROOK, WHITE);
	currentBoard[1][0].setFigureAndColor(KNIGHT, WHITE);
	currentBoard[2][0].setFigureAndColor(BISHOP, WHITE);
	currentBoard[3][0].setFigureAndColor(QUEEN, WHITE);
	currentBoard[4][0].setFigureAndColor(KING, WHITE);
	currentBoard[5][0].setFigureAndColor(BISHOP, WHITE);
	currentBoard[6][0].setFigureAndColor(KNIGHT, WHITE);
	currentBoard[7][0].setFigureAndColor(ROOK, WHITE);

	currentBoard[0][7].setFigureAndColor(ROOK, BLACK);
	currentBoard[1][7].setFigureAndColor(KNIGHT, BLACK);
	currentBoard[2][7].setFigureAndColor(BISHOP, BLACK);
	currentBoard[3][7].setFigureAndColor(QUEEN, BLACK);
	currentBoard[4][7].setFigureAndColor(KING, BLACK);
	currentBoard[5][7].setFigureAndColor(BISHOP, BLACK);
	currentBoard[6][7].setFigureAndColor(KNIGHT, BLACK);
	currentBoard[7][7].setFigureAndColor(ROOK, BLACK);

	for (int i = 0; i < 8; i++)
	{
		currentBoard[i][1].setFigureAndColor(PAWN, WHITE);
		currentBoard[i][6].setFigureAndColor(PAWN, BLACK);

	}
	for (int i = 2; i < 6; i++)
	{
		for (int j = 0; j < 8; j++)
			currentBoard[j][i].setFigureAndColor(EMPTY, NONE);

	}
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			currentBoard[i][j].setX(i);
			currentBoard[i][j].setY(j);
		}

}

bool Board::playGame()
{
	system("cls");
	printBoard();
	return makeNextMove();

}

bool Board::moveKing(Square* thisKing, Square* thatSpace) {
	//off board inputs should be handled elsewhere (before this)
	//squares with same color should be handled elsewhere (before this)
	if (abs(thatSpace->getX() - thisKing->getX()) == 1)
		if (abs(thatSpace->getY() - thisKing->getY()) == 1)
		{
			thatSpace->setSpace(thisKing);
			thisKing->setEmpty();
			return true;
		}
		else return false;
	else return false;
}
bool Board::moveQueen(Square* thisQueen, Square* thatSpace) { //there might be problems with numbers of brackets
													   //off board inputs should be handled elsewhere (before this)
													   //squares with same color should be handled elsewhere (before this)

	int queenX = thisQueen->getX();
	int queenY = thisQueen->getY();
	int thatX = thatSpace->getX();
	int thatY = thatSpace->getY();
	std::cout << "this";
	int yIncrement;
	int xIncrement;

	bool invalid = false;
	if (queenX != thatX || queenY != thatY)
	{

		if (queenX == thatX)
		{
			yIncrement = (thatY - queenY) / (abs(thatY - queenY));
			for (int i = queenY + yIncrement; i != thatY; i += yIncrement)
			{

				if (currentBoard[thatX][i].getColor() != NONE)
					return false;

			}
		}
		else
			if (queenY == thatY)
			{

				xIncrement = (thatX - queenX) / (abs(thatX - queenX));
				for (int i = queenX + xIncrement; i != thatX; i += xIncrement)
				{
					if (currentBoard[i][thatY].getColor() != NONE)
						return false;
				}
			}
			else
				if (abs(queenX - thatX) == abs(queenY - thatY))
				{
					xIncrement = (thatX - queenX) / (abs(thatX - queenX));
					yIncrement = (thatY - queenY) / (abs(thatY - queenY));

					for (int i = 1; i < abs(queenX - thatX); i++)
					{
						std::cout << "It got here somehow";
						if (currentBoard[queenX + xIncrement * i][queenY + yIncrement * i].getColor() != NONE)
							return false;

					}
				}
				else
					return false;
		//if()
	}



	if (invalid == false)
	{
		thatSpace->setSpace(thisQueen);
		thisQueen->setEmpty();
		return true;
	}
	else
	{
		return false;
	}
}

bool Board::moveBishop(Square* thisBishop, Square* thatSpace) { //there might be problems with number of brackets
	int bishopX = thisBishop->getX();
	int bishopY = thisBishop->getY();
	int thatX = thatSpace->getX();
	int thatY = thatSpace->getY();
	bool invalid = false;
	Square* s;
	if (abs(bishopX - thatX) == abs(bishopY - thatY))
	{
		int xIncrement = (thatX - bishopX) / (abs(thatX - bishopX));
		int yIncrement = (thatY - bishopY) / (abs(thatY - bishopY));

		for (int i = 1; i < abs(bishopX - thatX); i++)
		{
			std::cout << "It got here somehow";
			if (currentBoard[bishopX + xIncrement * i][bishopY + yIncrement * i].getColor() != NONE)
				return false;

		}
	}
	else
		return false;

	if (invalid == false)
	{
		thatSpace->setSpace(thisBishop);
		thisBishop->setEmpty();
		return true;
	}
	else
	{
		return false;
	}
}
bool Board::moveKnight(Square* thisKnight, Square* thatSpace)
{
	//off board inputs should be handled elsewhere (before this)
	//squares with same color should be handled elsewhere (before this)
	int knightX = thisKnight->getX();
	int knightY = thisKnight->getY();
	int thatX = thatSpace->getX();
	int thatY = thatSpace->getY();

	if ((abs(knightX - thatX) == 2 && abs(knightY - thatY) == 1) || (abs(knightX - thatX) == 1 && abs(knightY - thatY) == 2))
	{
		thatSpace->setSpace(thisKnight);
		thisKnight->setEmpty();
		return true;
	}
	else
	{
		return false;
	}
}

bool Board::moveRook(Square* thisRook, Square* thatSpace)
{
	//off board inputs should be handled elsewhere (before this)
	//squares with same color should be handled elsewhere (before this)
	int rookX = thisRook->getX();
	int rookY = thisRook->getY();
	int thatX = thatSpace->getX();
	int thatY = thatSpace->getY();
	bool invalid = false;
	if (rookX != thatX || rookY != thatY)
	{

		if (rookX == thatX)
		{
			int yIncrement = (thatY - rookY) / (abs(thatY - rookY));
			for (int i = rookY + yIncrement; i != thatY; i += yIncrement)
			{

				if (currentBoard[thatX][i].getColor() != NONE)
					return false;

			}
		}
		else
			if (rookY == thatY)
			{

				int xIncrement = (thatX - rookX) / (abs(thatX - rookX));
				for (int i = rookX + xIncrement; i != thatX; i += xIncrement)
				{
					if (currentBoard[i][thatY].getColor() != NONE)
						return false;
				}
			}
			else
				return false;
	}
	if (invalid == false)
	{
		thatSpace->setSpace(thisRook);
		thisRook->setEmpty();
		return true;
	}
	else
	{//Return some erorr or something. Probably return false;
		std::cout << "That is an invalid move for rook";
		return false;
	}
}

bool Board::movePawn(Square* thisPawn, Square* thatSpace) {
	//off board inputs should be handled elsewhere (before this)
	//squares with same color should be handled elsewhere (before this)
	using namespace std;
	bool invalid = false;
	int pawnX = thisPawn->getX();
	int pawnY = thisPawn->getY();
	int thatX = thatSpace->getX();
	int thatY = thatSpace->getY();


	if (thisPawn->getColor() == WHITE)
	{

		if (pawnX == thatX && thatY == pawnY + 1 && thatSpace->getColor() == NONE)
		{
			thatSpace->setSpace(thisPawn);
			thisPawn->setEmpty();
			return true;
		}
		else
			if ((pawnX + 1 == thatX || pawnX - 1 == thatX) && pawnY + 1 == thatY && thatSpace->getColor() == BLACK)
			{
				thatSpace->setSpace(thisPawn);
				thisPawn->setEmpty();
				return true;
			}
			else
				return false;
	}
	else
		if (thisPawn->getColor() == BLACK)
		{
			if (pawnX == thatX && thatY == pawnY - 1 && thatSpace->getColor() == NONE)
			{
				thatSpace->setSpace(thisPawn);
				thisPawn->setEmpty();
				return true;
			}
			else
				if ((pawnX + 1 == thatX || pawnX - 1 == thatX) && pawnY - 1 == thatY && thatSpace->getColor() == WHITE)
				{
					thatSpace->setSpace(thisPawn);
					thisPawn->setEmpty();
					return true;
				}
				else
					return false;
		}
		else
			return false;
}
bool Board::makeMove(int x1, int y1, int x2, int y2) {
	//Checking for turns will be done previous to this
	using namespace std;
	if (x1 < 0 || x1>7 || y1 < 0 || y1>7 || x2 < 0 || x2>7 || y2 < 0 || y2>8)
	{
		std::cout << "One of your inputs was our of bounds" << std::endl;
		return false;
	}
	Square* src = getSquare(x1, y1);
	Square* dest = getSquare(x2, y2);

	if (src->getColor() == dest->getColor() && dest->getColor() != NONE)
	{
		std::cout << "Invalid move: cannot land on your own piece" << std::endl;
		return false;
	}

	switch (src->getFigure())
	{
	case KING: return moveKing(src, dest);
		break;
	case QUEEN: return moveQueen(src, dest);
		break;
	case BISHOP: return moveBishop(src, dest);
		break;
	case KNIGHT: return moveKnight(src, dest);
		break;
	case ROOK: return moveRook(src, dest);
		break;
	case PAWN: return movePawn(src, dest);
		break;
	case EMPTY: std::cout << "You do not have a piece there" << std::endl;  return false;
		break;
	default: std::cerr << "Something went wrong in the switch statement in makeMove()" << std::endl;
		break;
	}
	return false;
}