#pragma once
#include "Board.h"

class Game
{
private:
    std::string input1, input2; //user input
    Color colorOnTurn;
    bool isMoveSuccessful;
    Position currentPosition;
    Position nextPosition;

    void displayIntro() const;
    void displayInstructions() const;
    void toLowerCaseInput(std::string* str);
    bool isValidInput();
    void changeTurn();

public:
    Game();
    virtual ~Game();

    void startNewGame();
};
