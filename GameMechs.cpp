#include "GameMechs.h"
#include <ctime>
#include "Food.h"
#include <iostream>
// ###########################################################################################
//      Object Completed by Ratish - Used for debugging Player class
// ###########################################################################################


// Method completed by Ratish - Used for debugging Player class
GameMechs::GameMechs()
    : boardSizeX(15), boardSizeY(30), input(0), score(0), exitFlag(false), loseFlag(false)
{
    food = new Food();
}

// Method completed by Ratish - Used for debugging Player class
GameMechs::GameMechs(int boardX, int boardY)
    : boardSizeX(boardX), boardSizeY(boardY), input(0), score(0), exitFlag(false), loseFlag(false)
{
    food = new Food();
}

// do you need a destructor? 
GameMechs::~GameMechs()
{
    delete food;
     // NO, because there are no heap memory allocations in this class
}

bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}
    

char GameMechs::getInput() const
{
    return input;
}

int GameMechs::getScore() const
{
    return score;
}

void GameMechs::incrementScore()
{
    score+=1;
}

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

// Method completed by Ratish - Used for debugging Player class
void GameMechs::clearInput()
{
    input = 0;
}

// More methods should be added here

void GameMechs::generateFood(objPos blockOff)
{
    if(!food->isfoodGenerated())
    {
        food->generateFood(blockOff, boardSizeX, boardSizeY);
    }
}

 objPos GameMechs::getFoodPos() const
{
    return food->getFoodPos();
}
void GameMechs::resetFood()
{
    food->resetFood();
}
 
