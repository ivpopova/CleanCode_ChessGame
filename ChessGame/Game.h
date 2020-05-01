#pragma once
#include "Board.h"

class Game {

public:
    Game();
    virtual ~Game();

    void startNewGame();
    
private:
    std::string input1, input2; //user input
    Color colorOnTurn; 
    Position currentPosition;
    Position nextPosition;

    bool isMoveSuccessful;
    void displayIntro() const;
    void displayInstructions() const;
    void toLowerCaseInput(std::string* str);
    bool isValidInput();
    void changeTurn();
};
