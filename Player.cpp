#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos = {mainGameMechsRef->getBoardSizeX() / 2, mainGameMechsRef->getBoardSizeY() / 2, '*'};
}


Player::~Player()
{
    // delete any heap members here
}

objPos Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPos;
}

int Player::getX() 
{
    return playerPos.getX();
}

int Player::getY() 
{
    return playerPos.getY();
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic
    char input = mainGameMechsRef->getInput();

    switch (myDir)
    {
        case STOP:
            if (input = 'w')
            {
                myDir = UP;
            }
            else if (input = 'a')
            {
                myDir = LEFT;
            }
            else if (input = 's')
            {
                myDir = DOWN;
            }
            else if (input = 'd')
            {
                myDir = RIGHT;
            }

        case UP:
            if (input == 'w')
            {
                myDir = UP;
            }
            else if (input == 'a')
            {
                myDir = LEFT;
            } 
            else if (input == 's')
            {
                myDir = UP;
            }
            else if (input == 'd')
            {
                myDir = RIGHT;
            }

            break;

        case DOWN:
            if (input == 'w')
            {
                myDir = DOWN;
            }
            else if (input == 'a')
            {
                myDir = LEFT;
            } else if (input == 's')
            {
                myDir = DOWN;
            }
            else if (input == 'd')
            {
                myDir = RIGHT;
            }
            break;

        case LEFT:
            if (input == 'w')
            {
                myDir = UP;
            }
            else if (input == 'a')
            {
                myDir = LEFT;
            } 
            else if (input == 's')
            {
                myDir = DOWN;
            }
            else if (input == 'd')
            {
                myDir = LEFT;
            }
            break;

        case RIGHT:
            if (input == 'w')
            {
                myDir = UP;
            }
            else if (input == 'a')
            {

                myDir = RIGHT;
            } 
            else if (input == 's')
            {
                myDir = DOWN;
            }
            else if (input == 'd')
            {

                myDir = RIGHT;
            }
            break;

        default:
            break;
    }
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    int xPos = playerPos.getX();
    int yPos = playerPos.getY();

    switch (myDir)
    {
    case UP:
        playerPos.setObjPos(playerPos.getX(), playerPos.getY() - 1, playerPos.getSymbol());        
        break;

    case RIGHT:
        playerPos.setObjPos(playerPos.getX() + 1, playerPos.getY(), playerPos.getSymbol());
        break;

    case DOWN:
        playerPos.setObjPos(playerPos.getX(), playerPos.getY() + 1, playerPos.getSymbol());
        break;

    case LEFT:
        playerPos.setObjPos(playerPos.getX() - 1, playerPos.getY(), playerPos.getSymbol());
        break;
    
    default:
        break;
    }
}

// More methods to be added