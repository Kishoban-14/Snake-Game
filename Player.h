#ifndef PLAYER_H
#define PLAYER_H

#include <wchar.h>
#include <locale.h>
#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"


class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    
    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state

        Player(GameMechs* thisGMRef, int initialX, int initialY);
        Player(GameMechs* thisGMRef, int initialX, int initialY, int initialSize);
        ~Player();

        objPosArrayList* getPlayerPos() const; // Upgrade this in iteration 3. 
        wchar_t getHeadSymbol();
        int updateSpeed(char mode, int delay);      
        void updatePlayerDir();
        void movePlayer();

        // More methods to be added here
        bool checkFoodConsumption();
        bool checkSelfCollision();


    private:
        objPosArrayList* playerPos; // Upgrade this in iteration 3.       
        enum Dir myDir;

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
};

#endif