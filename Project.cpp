#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include <conio.h>

using namespace std;

#define DELAY_CONST 100000

// Global Objects
Player *playerPtr = nullptr;
GameMechs *gameMech = nullptr;

// Global Variables
int x;
int y;
int symb;
char input;

// Iterator Variables
int i;
int j;

int HEIGHT;
int WIDTH;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

int main(void)
{

    Initialize();

    while (gameMech->getExitFlagStatus() == false)
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
    gameMech = new GameMechs(); // Game Mechanics Object
    playerPtr = new Player(gameMech);   // Player Object

    // Initialising Global Variables
    HEIGHT = gameMech->getBoardSizeX(); // Get Board Height
    WIDTH = gameMech->getBoardSizeY();   // Get Board Width
    symb = playerPtr->getSymbol();     // Get Player Symbol

}

void GetInput(void)
{
    if (MacUILib_hasChar())
        gameMech->setInput(_getch()); // Get Input
    else
        gameMech->clearInput(); // Clear input if no input is given
}

void RunLogic(void)
{
    input = gameMech->getInput();

    if (input == 32)
        gameMech->setExitTrue();


    playerPtr->updatePlayerDir();      // Update player direction
    playerPtr->movePlayer();    // Move player based on direction
}

void DrawScreen(void)
{
    x = playerPtr->getX(); 
    y = playerPtr->getY();

    MacUILib_clearScreen();

    printf("SPEED SETTINGS:\nVery Slow: Press [1]%10sSlow: Press [2]%10sMedium: Press [3]%10sFast: Press [4]%10sVery Fast: Press [5]\n", " ", " ", " ", " ");

    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1)
            {
                printf("#");
            }
            else if (i == x && j == y)
            {
                printf("%c", playerPtr->getSymbol());
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    printf("Input Character: %c\n", input);
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}

void CleanUp(void)
{
    MacUILib_clearScreen();


    // Display Win/Lose Message
    if (gameMech->getLoseFlagStatus()) 
        printf("You Win!\n");
    else
        printf("You Lose!\n");
    
    // De-allocate Heap Memory
    delete playerPtr;
    delete gameMech;

    MacUILib_uninit();
}
