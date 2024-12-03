#ifndef FOOD_H
#define FOOD_H

#include <cstdlib>
#include <time.h>
#include <conio.h>
#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;
class Food
{
    private:
        objPosArrayList* foodBucket;
        int specialFoodCount;
        int xRange;
        int yRange;
    public:

       Food(int totalFood, int specialFoodCount);
       ~Food();
       void generateFood(int boardSizeX, int boardSizeY, objPosArrayList* playerPos);
       objPos getFoodPos(int index) const;
       objPosArrayList* getFoodBucket() const;
       void removeFood(int index);
};


#endif