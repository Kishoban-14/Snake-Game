#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"

using namespace std;

#define DELAY_CONST 100000

// Global Objects
Player* playerPtr = nullptr;
GameMechs* gameMech = nullptr;

// Global Variables
int x;
int y;
int symb;
char input;

int HEIGHT;
int WIDTH;

bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(exitFlag == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    // Allocating Heap Memory
    gameMech = new GameMechs();
    playerPtr = new Player(gameMech);


    // Initialising Global Variables
    HEIGHT = gameMech->getBoardSizeX();
    WIDTH = gameMech->getBoardSizeY();

    exitFlag = false;
}

void GetInput(void)
{
    if (MacUILib_hasChar())
        input = MacUILib_getChar();
}

void RunLogic(void)
{
    
}

void DrawScreen(void)
{
    x = playerPtr->getX();
    y = playerPtr->getY();

    MacUILib_clearScreen();

    printf("SPEED SETTINGS:\nVery Slow: Press [1]%10sSlow: Press [2]%10sMedium: Press [3]%10sFast: Press [4]%10sVery Fast: Press [5]\n"," "," "," "," ");

    int i, j;
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {   
            if (i == 0 || i >= HEIGHT - 1)
            {
                printf("#");
            }
            else if (i == x && j == y)
            {
                printf("%c", symb);
            }
            else
            {
                if (j == 0 || j >= WIDTH - 1)
                {
                    printf("#");
                }
                else
                {
                    printf(" ");
                }   
            }
        }
        printf("\n");
    }
}



void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    delete playerPtr;
    delete gameMech;

    MacUILib_uninit();
}
