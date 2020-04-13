#pragma once
#include "Board.h"

class Game
{
private:
    std::string input1, input2; //user input
    Color colorOnTurn;
    bool isMoveSuccessful;
    Position currentPosition;
    Position newPosition;

    void displayIntro();
    void displayInstructions();
    void toLowerCaseInput(std::string* str);
    bool isValidInput();

public:
    Game();
    virtual ~Game();

    void startNewGame();
};
