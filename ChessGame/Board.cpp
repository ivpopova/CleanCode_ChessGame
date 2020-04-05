#include"Board.h"

void Board::changeTurn() {
    if (nextTurn == Colors::BLACK) {
		nextTurn = Colors::WHITE;
	}
	else {
		nextTurn = Colors::BLACK;
	}

}

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
			case KING: (currentColor == Colors::WHITE) ? cout << " K " : cout << " k ";
				break;
			case QUEEN: (currentColor == Colors::WHITE) ? cout << " Q " : cout << " q ";
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
	int oldPositionX, newPositionX, oldPositionY, newPositionY;
	bool isValidMove = false;

	while (!isValidMove)
	{
		(nextTurn == Colors::WHITE) ? cout << "White's turn" << endl : cout << "Black's turn" << endl;
		cout << "Type in your move as a single four character string. Use x-coordinates first in each pair." << endl;
		cin >> inputMove;

		oldPositionX = inputMove[0] - '0';
		oldPositionY = inputMove[1] - '0';
		newPositionX = inputMove[2] - '0';
		newPositionY = inputMove[3] - '0';

		if (getSquare(oldPositionX, oldPositionY)->getColor() == nextTurn){

			if (makeMove(oldPositionX, oldPositionY, newPositionX, newPositionY) == false){
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

	if (getSquare(newPositionX, newPositionY)->getFigure() == Figures::KING) {
		if (getSquare(oldPositionX, oldPositionY)->getColor() == Colors::WHITE)
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

	changeTurn();
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

	for (int i = 0; i < BOARD_SIZE; i++){
		currentBoard[i][1].setFigureAndColor(PAWN, WHITE);
		currentBoard[i][6].setFigureAndColor(PAWN, BLACK);

	}
	for (int i = 2; i < 6; i++){

		for (int j = 0; j < BOARD_SIZE; j++) {
			currentBoard[j][i].setFigureAndColor(EMPTY, NONE);
		}
	}
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			currentBoard[i][j].setX(i);
			currentBoard[i][j].setY(j);
		}
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
	if (abs(thatSpace->getX() - thisKing->getX()) == 1) {

		if (abs(thatSpace->getY() - thisKing->getY()) == 1){

			thatSpace->setSpace(thisKing);
			thisKing->setEmpty();

			return true;
		}
		else {

			return false;
		}
	}
	else {

		return false;
	}
}
bool Board::moveQueen(Square* thisQueen, Square* thatSpace) { //there might be problems with numbers of brackets
													   //off board inputs should be handled elsewhere (before this)
													   //squares with same color should be handled elsewhere (before this)

	int queenPositionX = thisQueen->getX();
	int queenPositionY = thisQueen->getY();
	int newPositionX = thatSpace->getX();
	int newPositionY = thatSpace->getY();
	cout << "this";
	int yIncrement;
	int xIncrement;

	bool isValid = false;
	if (queenPositionX != newPositionX || queenPositionY != newPositionY){

		if (queenPositionX == newPositionX){

			yIncrement = (newPositionY - queenPositionY) / (abs(newPositionY - queenPositionY));

			for (int i = queenPositionY + yIncrement; i != newPositionY; i += yIncrement){

				if (currentBoard[newPositionX][i].getColor() != NONE) {
					return false;
				}
			}
		}
		else
			if (queenPositionY == newPositionY){

				xIncrement = (newPositionX - queenPositionX) / (abs(newPositionX - queenPositionX));

				for (int i = queenPositionX + xIncrement; i != newPositionX; i += xIncrement){
					if (currentBoard[i][newPositionY].getColor() != NONE) {
						return false;
					}
						
				}
			}
			else {
				if (abs(queenPositionX - newPositionX) == abs(queenPositionY - newPositionY)) {
					xIncrement = (newPositionX - queenPositionX) / (abs(newPositionX - queenPositionX));
					yIncrement = (newPositionY - queenPositionY) / (abs(newPositionY - queenPositionY));

					for (int i = 1; i < abs(queenPositionX - newPositionX); i++) {
						std::cout << "It got here somehow";
						if (currentBoard[queenPositionX + xIncrement * i][queenPositionY + yIncrement * i].getColor() != NONE) {
							return false;
						}
					}
				}
				else {
					return false;
				}
			}
	}



	if (isValid == false){
		thatSpace->setSpace(thisQueen);
		thisQueen->setEmpty();
		return true;
	}
	else{
		return false;
	}
}

bool Board::moveBishop(Square* thisBishop, Square* thatSpace) { //there might be problems with number of brackets
	int bishopPositionX = thisBishop->getX();
	int bishopPositionY = thisBishop->getY();
	int newPositionX = thatSpace->getX();
	int newPositionY = thatSpace->getY();

	bool isValid = false;
	Square* s;
	if (abs(bishopPositionX - newPositionX) == abs(bishopPositionY - newPositionY))
	{
		int xIncrement = (newPositionX - bishopPositionX) / (abs(newPositionX - bishopPositionX));
		int yIncrement = (newPositionY - bishopPositionY) / (abs(newPositionY - bishopPositionY));

		for (int i = 1; i < abs(bishopPositionX - newPositionX); i++)
		{
			std::cout << "It got here somehow";
			if (currentBoard[bishopPositionX + xIncrement * i][bishopPositionY + yIncrement * i].getColor() != NONE)
				return false;

		}
	}
	else
		return false;

	if (isValid == false)
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
	int knightPositionX = thisKnight->getX();
	int knightPositionY = thisKnight->getY();
	int newPositionX = thatSpace->getX();
	int newPositionY = thatSpace->getY();

	if ((abs(knightPositionX - newPositionX) == 2 && abs(knightPositionY - newPositionY) == 1) || (abs(knightPositionX - newPositionX) == 1 && abs(knightPositionY - newPositionY) == 2)){
		thatSpace->setSpace(thisKnight);
		thisKnight->setEmpty();
		return true;
	}
	else{
		return false;
	}
}

bool Board::moveRook(Square* thisRook, Square* thatSpace)
{
	//off board inputs should be handled elsewhere (before this)
	//squares with same color should be handled elsewhere (before this)
	int rookPositionX = thisRook->getX();
	int rookPositionY = thisRook->getY();
	int newPositionX = thatSpace->getX();
	int newPositionY = thatSpace->getY();
	bool isValid = false;
	if (rookPositionX != newPositionX || rookPositionY != newPositionY)
	{

		if (rookPositionX == newPositionX)
		{
			int yIncrement = (newPositionY - rookPositionY) / (abs(newPositionY - rookPositionY));
			for (int i = rookPositionY + yIncrement; i != newPositionY; i += yIncrement)
			{

				if (currentBoard[newPositionX][i].getColor() != NONE)
					return false;

			}
		}
		else
			if (rookPositionY == newPositionY)
			{

				int xIncrement = (newPositionX - rookPositionX) / (abs(newPositionX - rookPositionX));
				for (int i = rookPositionX + xIncrement; i != newPositionX; i += xIncrement)
				{
					if (currentBoard[i][newPositionY].getColor() != NONE)
						return false;
				}
			}
			else
				return false;
	}
	if (isValid == false)
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
    // off board inputs should be handled elsewhere (before this)
    // squares with same color should be handled elsewhere (before this)
 
    int pawnPositionX = thisPawn->getX();
    int pawnPositionY = thisPawn->getY();
    int newPositionX = thatSpace->getX();
    int newPositionY = thatSpace->getY();
 
    if (thisPawn->getColor() == WHITE)
    {
        // Move to an empty square
        if (pawnPositionX == newPositionX &&
              (newPositionY == pawnPositionY + 1 || (pawnPositionY == 1 && newPositionY == pawnPositionY + 2)) &&
                thatSpace->getColor() == NONE)
        {
            thatSpace->setSpace(thisPawn);
            thisPawn->setEmpty();
            return true;
        }
        // Move to capture a black figure
        else if ((pawnPositionX + 1 == newPositionX || pawnPositionX - 1 == newPositionY) &&
                            pawnPositionY + 1 == newPositionY && thatSpace->getColor() == BLACK)
        {
            thatSpace->setSpace(thisPawn);
            thisPawn->setEmpty();
            return true;
        }
        // Otherwise the move is invalid
        else
        {
            return false;
        }
    }
    else if (thisPawn->getColor() == BLACK)
    {
        // Move to an empty square
        if (pawnPositionX == newPositionX &&
              (newPositionY == pawnPositionY - 1 || (pawnPositionY == 6 && newPositionY == pawnPositionY - 2)) &&
                thatSpace->getColor() == NONE)
        {
            thatSpace->setSpace(thisPawn);
            thisPawn->setEmpty();
            return true;
        }
        // Move to capture a white figure
        else if ((pawnPositionX + 1 == newPositionX || pawnPositionX - 1 == newPositionX) &&
                          pawnPositionY - 1 == newPositionY && thatSpace->getColor() == WHITE)
        {
            thatSpace->setSpace(thisPawn);
            thisPawn->setEmpty();
            return true;
        }
        // Otherwise the move is invalid
        else
        {
            return false;
        }
 
    }
 
    // Invalid move
    else
    {
        return false;
    }
}

bool Board::makeMove(int oldPositionX, int oldPositionY, int newPositionX, int newPositionY) {
	//Checking for turns will be done previous to this
	using namespace std;
	if (oldPositionX < 0 || oldPositionX>7 || oldPositionY < 0 || oldPositionY>7 || newPositionX < 0 || newPositionX>7 || newPositionY < 0 || newPositionY>8)
	{
		std::cout << "One of your inputs was our of bounds" << std::endl;
		return false;
	}
	Square* src = getSquare(oldPositionX, oldPositionY);
	Square* dest = getSquare(newPositionX, newPositionY);

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

