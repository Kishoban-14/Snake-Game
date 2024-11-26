#include "GameMechs.h"
#include <ctime>
#include "Food.h"
#include <iostream>
// ###########################################################################################
//      Object Completed by Ratish - Used for debugging Player class
// ###########################################################################################


// Method completed by Ratish - Used for debugging Player class
GameMechs::GameMechs()
    : boardSizeX(15), boardSizeY(30), input(0), score(0), exitFlag(false), loseFlag(true)
{
    foodPos = new objPos(1,1, '@');
}

// Method completed by Ratish - Used for debugging Player class
GameMechs::GameMechs(int boardX, int boardY)
    : boardSizeX(boardX), boardSizeY(boardY), input(0), score(0), exitFlag(false), loseFlag(true)
{
    foodPos = new objPos(1,1, '@');
}

// do you need a destructor? 
GameMechs::~GameMechs()
{
    delete foodPos;
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
    loseFlag = false;
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
void GameMechs::generateFood(objPosArrayList* playerPos)
{

    int xRange = getBoardSizeX();
    int yRange = getBoardSizeY();

    int x = foodPos->getObjPos().getY();
    int y = foodPos->getObjPos().getY(); 

    // int listSize = numberOfFood;
    int playerSize = playerPos->getSize();



    for (int i = 0; i < 1; i++)
    {
        int valid = 0;
        //Keep genearating item till valid item Generated
        while (!valid) {
            x = rand() % (xRange - 2) + 1;
            y = rand() % (yRange - 2) + 1;
            valid = 1;

            for (int j = 0; j < playerSize; j++)
                if (x == playerPos->getHeadElement().getX() && y == playerPos->getHeadElement().getY()) 
                    valid = 0;
        }
    }

    foodPos->setObjPos(x, y, '@');
}

objPos GameMechs::getFoodPos() const
{
    return foodPos->getObjPos();
}
            // for (int j = 0; j < i; j++) {
            //     for (int k = 0; k < playerSize; k++){
            //         if (list-i-x == list-j-x && list-i-y == list-j-y) {
            //             valid = 0;
            //             break;
            //         }
            //     }
            // }