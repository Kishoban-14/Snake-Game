#include "Player.h"

Player::Player(GameMechs *thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // Initialize playerPos
    playerPos = new objPosArrayList(3);

    // Initialize player position to mimic snake body
    int initialX = mainGameMechsRef->getBoardSizeX() / 2;
    int initialY = mainGameMechsRef->getBoardSizeY() / 2;

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

    switch (myDir)
    {
    case UP:
        xPos -= 1;
        break;

    case RIGHT:
        yPos += 1;
        break;

    case DOWN:
        xPos += 1;
        break;

    case LEFT:
        yPos -= 1;
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
    newHead.setObjPos(xPos, yPos, '*');

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