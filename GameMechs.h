#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>
#include <conio.h>
#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"
#include "Player.h"
using namespace std;

class Player;
class GameMechs
{
    private:
        char input;
        bool exitFlag;
        bool loseFlag;
        int score;

        int boardSizeX;
        int boardSizeY;

        // objPos* foodPos;
        Food* foodPtr;

    public:
        GameMechs();
        GameMechs(int boardX, int boardY);
        ~GameMechs(); // is this one needed at all? Why or why not?
        
        bool getExitFlagStatus() const; 
        void setExitTrue();
        bool getLoseFlagStatus() const;
        void setLoseFlag();

        char getInput() const;
        void setInput(char this_input);
        void clearInput();

        int getBoardSizeX() const;
        int getBoardSizeY() const;
        
        int getScore() const;
        void incrementScore(int points);
        
        // More methods should be added here
        void generateFood(objPosArrayList* playerPos);
        objPos getFoodPos() const;
        void removeFood(int index);
        void checkFoodConsumption(Player* player);
};

#endif