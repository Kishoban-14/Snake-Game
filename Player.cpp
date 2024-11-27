#include "Player.h"

Player::Player(GameMechs *thisGMRef, const int size)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    mainGameMechsRef->initScore(size);

    // Initialize playerPos
    playerPos = new objPosArrayList(size);

    int initialX = 5;
    int initialY = 5;

    for (int i = 0; i < playerPos->getSize(); i++) // Initialize with one element
    {
        objPos initialPos(initialX, initialY + i, '*');
        playerPos->getElement(i).setObjPos(initialPos);
    }
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
    char headSymbol;

    switch (myDir)
    {
    case UP:
        xPos -= 1;
        headSymbol = '^';
        break;

    case RIGHT:
        yPos += 1;
        headSymbol = '>';
        break;

    case DOWN:
        xPos += 1;
        headSymbol = 'v';
        break;

    case LEFT:
        yPos -= 1;
        headSymbol = '<';
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