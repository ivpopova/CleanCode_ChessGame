#pragma once
#include "Board.h"
#include "Figure.h"
#include <cstring>

class Game
{
private:
    std::string input1, input2; //user input
    Color colorOnTurn;
    bool moveSucceed;
    Position moveFrom;
    Position moveTo;

    void displayIntro();
    void displayInstructions();
    void toLowerCaseInput(std::string* str);
    bool isValidInput();

public:
    Game();
    virtual ~Game();

    void startNewGame();
};
