#ifndef FOOD_H
#define FOOD_H

#include "objPos.h"

using namespace std;

class Food
{   
    private:
        objPos foodPos;
        bool isFoodGenerated;
    public:
        Food();
        ~Food();
        void generateFood(objPos blockOff, int boardWidth, int boardHeight);
        objPos getFoodPos() const;
        void resetFood();
        bool isfoodGenerated() const;
};

#endif
