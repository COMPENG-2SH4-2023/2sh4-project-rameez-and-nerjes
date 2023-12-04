#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"
#include "objPosArrayList.h"
#include <time.h>


using namespace std;

#define DELAY_CONST 100000

//declaring classes
GameMechs* myGM;
Player* myPlayer;
objPos tempPos;
objPos temp_food_pos;
objPosArrayList* PlayerBody;
objPos tempBody;



void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{
    
    Initialize();

     
    while(myGM->getExitFlagStatus() == false)  
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
    
    myGM = new GameMechs(30, 15);
    myPlayer = new Player(myGM);
   
    myGM ->generateFood(myPlayer->getPlayerPos());
    
   
}

void GetInput(void)
{
   myGM -> getInput();
   
   if(myGM -> getInput() == ' ')
   {
    myGM -> setExitTrue();
   }
  
}


void RunLogic(void)
{

    //This updates the player direction based on the keyboard key pressed
    myPlayer->updatePlayerDir();


    //This moves the player based on the updated direction
    myPlayer->movePlayer();
    
 


    //COllISION LOGIC 
    //This logic checks to see if the "food was consumed. If it has been consumed, the snake length will be increased, score increments,"
    //and a new food location is generated
     if(myPlayer->checkFoodConsumption())
{
    
    myPlayer->incresePlayerLength();
    myGM->incrementScore();
    myGM ->generateFood(myPlayer->getPlayerPos());
}
    
 
   
    
    //Suicide/self collision logic :(
    //this calls the self collision check. if true, game is ended
    myPlayer->checkSelfCollision();

    



}

void DrawScreen(void)
{

    
    MacUILib_clearScreen(); 
    bool drawn;
    objPosArrayList* PlayerBody = myPlayer->getPlayerPos();
    objPos tempBody;
    

    myGM ->getFoodPos(temp_food_pos);
  for(int y = 0; y <=myGM->getBoardSizeY(); y++)

    {

        //This is the logic for drawing the snake on the screen
        for(int x = 0; x <= myGM->getBoardSizeX(); x++)
        {
            drawn = false;
            //iterate through every element in the list
            for(int k = 0; k < PlayerBody->getSize(); k++)
            {
            PlayerBody->getElement(tempBody, k);
            if(tempBody.x == x && tempBody.y == y)
            {
                MacUILib_printf("%c", tempBody.symbol);
                drawn = true;
                break;
            }
            }
        
        if(drawn) continue;

        if (x == temp_food_pos.x && y == temp_food_pos.y)
        {
           
            MacUILib_printf("%c", temp_food_pos.symbol);
        }
        else if (y == myGM->getBoardSizeY() || y == 0)
        {
            
           MacUILib_printf("%c", '#');
        }
        else if(x == 0 && y > 0)
        {
            MacUILib_printf("%c", '#');
        }
        else if(x == myGM->getBoardSizeX())
        {
           MacUILib_printf("%c", '#');
           MacUILib_printf("\n");
        }
        else if(x > 0)
        {
            MacUILib_printf("%c", ' ');
        }
        
        }
        if(y == 0){
               MacUILib_printf("%c", '\n');
        }
       
    } 
  

    //This prints score on screen 
    MacUILib_printf("\nScore: %d",  myGM->getScore());

    



}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    //Remove Heap instances
    delete myGM;
    delete myPlayer;
    delete PlayerBody;

}
