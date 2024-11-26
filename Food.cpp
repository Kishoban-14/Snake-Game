#include "Food.h"
#include <ctime>
#include <iostream>


Food::Food() : isFoodGenerated(false)
{
    foodPos.pos = new Pos{0,0};
    foodPos.symbol = '!';
}
Food::~Food()
{
    delete foodPos.pos;
}

void Food::generateFood(objPos blockOff, int boardWidth, int boardHeight)
 {
    if(!isFoodGenerated)
    {
        int randX;
        int randY;
        srand(static_cast<unsigned int>(time(0)));
        randX = rand() % (boardWidth - 2); //Kishoban- Random X within bounds(excluding edges) (Attempt at fixing issue of food object being placed out of bounds)
        randY = rand() % (boardHeight - 2);//Kishoban- Random Y within bounds(excluding edges)
        while (randX == blockOff.pos->x && randY == blockOff.pos->y)
        {
            randX = rand() % (boardWidth - 2) + 1;
            randY = rand() % (boardHeight - 2) + 1;
        }
        
        foodPos.pos->x = randX;
        foodPos.pos->y = randY;
        foodPos.symbol = '!';
        isFoodGenerated = true;
    }
}
objPos Food::getFoodPos() const
{
    return foodPos;
}

void Food::resetFood()
{
    isFoodGenerated = false;
}


bool Food::isfoodGenerated() const
{
    return isFoodGenerated;
}