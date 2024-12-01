#include "Player.h"

Player::Player(GameMechs *thisGMRef, int initialX, int initialY)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // Initialize playerPos
    playerPos = new objPosArrayList(initialX, initialY, 3);
}

Player::Player(GameMechs *thisGMRef, int initialX, int initialY, int initialSize)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // Initialize playerPos
    playerPos = new objPosArrayList(initialX, initialY, initialSize);

    // for (int i = 0; i < playerPos->getSize(); i++) // Initialize with one element
    // {
    //     objPos initialPos(initialX, initialY, 'O');
    //     playerPos->getElement(i).setObjPos(initialPos);
    // }
}

Player::~Player()
{
    // Clean up playerPos
    delete playerPos;
}

objPosArrayList* Player::getPlayerPos() const
{
    return playerPos;
}

wchar_t Player::getHeadSymbol()
{
    return playerPos->getHeadElement().getSymbol();
}

bool Player::checkFoodConsumption()
{
    objPos head = playerPos->getHeadElement();
    objPos food = mainGameMechsRef->getFoodPos();

    return food.getX() == head.getX() && food.getY() == head.getY();
}

bool Player::checkSelfCollision()
{
    if (myDir == STOP)
        return false;
    
    objPos head = playerPos->getHeadElement();

    for (int i = 1; i < playerPos->getSize(); i++)
    {
        if (head.getX() == playerPos->getElement(i).getX() && head.getY() == playerPos->getElement(i).getY())
            return true;
    }

    return false;
}

int Player::updateSpeed(char mode, int delay)
{
    switch (mode)
    {
    case 's':
        delay *= 2;
        break;
    case 'f':
        delay /= 2;
        break;
    default:
        break;
    }
    return delay;
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic
    char input = mainGameMechsRef->getInput();

    switch (input)
    {
    case 'w':
        if (myDir != DOWN)
            myDir = UP;
        break;

    case 'a':
        if (myDir != RIGHT)
            myDir = LEFT;
        break;

    case 's':
        if (myDir != UP)
            myDir = DOWN;
        break;

    case 'd':
        if (myDir != LEFT)
            myDir = RIGHT;
        break;

    default:
        break;
    }
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    int xPos = playerPos->getHeadElement().getX();
    int yPos = playerPos->getHeadElement().getY();

    // Head Symbol
    wchar_t headSymbol; // Change type to wchar_t
    headSymbol = 'o';

    switch (myDir)
    {
    case STOP:
        return ;
    case UP:
        xPos -= 1;
        headSymbol = 'O';
        break;

    case RIGHT:
        yPos += 1;
        headSymbol = 'O';
        break;

    case DOWN:
        xPos += 1;
        headSymbol = 'O';
        break;

    case LEFT:
        yPos -= 1;
        headSymbol = 'O';
        break;

    default:
        break;
    }

    // Border wraparound
    if (xPos < 1)
    {
        xPos = mainGameMechsRef->getBoardSizeX() - 2;
    }
    else if (xPos >= mainGameMechsRef->getBoardSizeX() - 1)
    {
        xPos = 1;
    }

    if (yPos < 1)
    {
        yPos = mainGameMechsRef->getBoardSizeY() - 2;
    }
    else if (yPos >= mainGameMechsRef->getBoardSizeY() - 1)
    {
        yPos = 1;
    }

    objPos newHead;
    newHead.setObjPos(xPos, yPos, headSymbol);

    playerPos->insertHead(newHead);

    if (checkFoodConsumption())
    {
        mainGameMechsRef->generateFood(playerPos);
        mainGameMechsRef->incrementScore();
    }

    else
        playerPos->removeTail();
}
// More methods to be added