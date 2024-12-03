#include "Food.h"
#include <stdlib.h>
#include <iostream>

using namespace std;


Food::Food(int totalFood = 5, int specialFoodCount = 2)
{
    foodBucket = new objPosArrayList();
    this->specialFoodCount = specialFoodCount;
}

Food:: ~Food()
{
    delete foodBucket;
}

void Food::generateFood(int boardSizeX, int boardSizeY, objPosArrayList* playerPos)
{
    int specialFoods = specialFoodCount;
    for (int i = 0; i < 5; ++i)
    {
        bool valid = false;
        int x,y;
        int playerSize = playerPos->getSize();

        while(!valid)
        {
            x = rand() % (boardSizeX - 2) + 1;
            y = rand() % (boardSizeY - 2) + 1;
            valid = true;
            for (int j = 0; j < playerSize; j++) 
            {
                if (x == playerPos->getElement(j).getX() && y == playerPos->getElement(j).getY())
                {
                    valid = false;
                    break;
                }
            }
        }
        char symbol = (rand() % 2 == 0) ? '@' : '$';
        foodBucket->insertTail(objPos(x, y, symbol));
        if (symbol == '$')
        {
            specialFoods--;
        }
    
    }

}

objPos Food:: getFoodPos(int index) const
{
    return foodBucket->getElement(index);
}

void Food::removeFood(int index)
{
    foodBucket->removeElement(index);
}

objPosArrayList* Food::getFoodBucket() const
{
    return foodBucket;
}