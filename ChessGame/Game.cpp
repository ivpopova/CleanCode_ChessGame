#include "Game.h"


extern Board board; 

 Game::Game() {
     colorOnTurn = Color::White;
     isMoveSuccessful = false;
 }


 Game::~Game() {
 }

 
void Game::displayInstructions() const {
    std::cout << "\n\tInstructions:\n"
              << "\tTo move chess pieces use standard chess notation.\n"
              << "\tIt consists of a letter(column), followed by a number(row).\n"
              << "\tIn piece's name letters w(white) and b(black) stand for color, followed by the piece's first char. NOTE: N = Knight\n"
              << "\tYou can enter 'quit' to exit the program or 'help' to receive these instructions again at any time\n";
}


void Game::displayIntro() const {
    std::cout << "\n\n\t\t\tCHESS GAME\n\n";
    displayInstructions();
    std::cout << "\n\n\tPress enter to start game\n";
    std::cin.ignore();
}


void Game::toLowerCaseInput(std::string* str) {

    for (int i=0; i<str->length(); ++i) {
        (*str)[i] = tolower((*str)[i]);
    }
}


Position convertChessNotation(std::string moveInputStr) {
    Position movePosition((int)moveInputStr[0] - 97, atoi(&moveInputStr[1]) - 1);

    return movePosition;
}

bool Game::isValidInput() {
    //check if input is right size
    if (input1.size() != 2 || input2.size() != 2) {
        std::cout << "Incorrect input size. Please check that the input is only a letter followed by number!\n";
        
        return false;
    }
    //check if from position is within the chess board
    else if (currentPosition.getCoordinateX() < 0 || currentPosition.getCoordinateX() > 7 || currentPosition.getCoordinateY() < 0 || currentPosition.getCoordinateY() > 7) {
        std::cout << "Source location out of the chess board\n";

        return false;
    }
    //check if to position is within the chess board
    else if (nextPosition.getCoordinateX() < 0 || nextPosition.getCoordinateX() > 7 || nextPosition.getCoordinateY() < 0 || nextPosition.getCoordinateY() > 7) {
        std::cout << "Destination location out of the chess board\n";

        return false;
    }
    else if (board.getFigureFromPosition(currentPosition) == nullptr) {
        std::cout << "There is no piece on this source location on the chess board\n";
        
        return false;
    }
    else {

        return true;
    }  
}

void Game::changeTurn() {
    colorOnTurn = (colorOnTurn == Color::White) ? Color::Black : Color::White;
}

void Game::startNewGame() {
    displayIntro();

    //main Game Loop
    while (input1 != "quit")
    {
        std::cout << "\n\n\n\n";
        board.print();

        do {
            if(colorOnTurn == Color::White) {
                std::cout << "\nWhite's turn\n";
            }
            else {
                std::cout << "\nBlack's turn\n";
            }

            do {
                std::cout << "Please enter where to move from: ";
                std::cin >> input1;
                toLowerCaseInput(&input1);

                //check if quit or help commands where entered
                if(input1 == "quit") {
                    return;
                }
                else if (input1 == "help") {

                    displayInstructions();
                }
                else {
                    //it must be a move
                    std::cout << "Please enter where to move to: ";
                    std::cin >> input2;
                    toLowerCaseInput(&input2);
                }

                currentPosition = convertChessNotation(input1);
                nextPosition = convertChessNotation(input2);
            }
            //validate the input; if invalid - new input
            while(!isValidInput());

            //check that the right colored piece is selected
            if(board.getFigureFromPosition(currentPosition)->getColor() != colorOnTurn) {
                std::cout << "Move Invalid: Wrong color piece selected\n";
                isMoveSuccessful = false;
            }
            else {
                //validate the specific chess piece rules
                isMoveSuccessful = board.moveFigure(currentPosition, nextPosition);
                if (isMoveSuccessful == false) {
                    std::cout << "Invalid move!\n";
                }
                else {
                    std::cout << "Move Completed!\n";
                }
            }
        }
        //if move failed, loop back without redrawing board
        while(isMoveSuccessful == false);
        changeTurn();
    }
}

