#include "GameMechs.h"
#include "MacUILib.h"
#include "time.h"

// think about where to seed the RNG
GameMechs::GameMechs()
{
    input = 0;
    score = 0;
    exitFlag = false;
    LoseFlag = false;
    boardSizeX = getBoardSizeX();
    boardSizeY= getBoardSizeY();
    


    foodPos.setObjPos(-1, -1, 'o'); //Initiali\e foodPOs outside of game board (so not to be displayd)


}

GameMechs::GameMechs(int boardX, int boardY)
{
input = 0;
    score = 0;
    exitFlag = false;
    LoseFlag = false;
    boardSizeX = boardX;
    boardSizeY=  boardY;
}

// do you need a destructor?



bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus()
{
    return LoseFlag;
}

char GameMechs::getInput()
{
     if(MacUILib_hasChar()!=0)
    {
        input = MacUILib_getChar();
    }
    return input;
}

int GameMechs::getScore()
{
return score;
}

void GameMechs::incrementScore()
{
    score++;
}

int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
 exitFlag = true;
}

void GameMechs::setLoseFlag()
{
 LoseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
 input = 0;
}

void  GameMechs::generateFood(objPosArrayList *playerPosList)
{
    //generate random x and y coord, and make sure they are not border or blockoff

    //check x and y against 0 and boardsize x/y

    //remember, in objPos class, you have an isPosEqual() methid. use this instead of comparing element by element
    //for your convience

    int count = 0;
    int check = 0;  
    objPos temp_food_pos;
    objPos tempBody;
    srand(time(NULL));
    getFoodPos(temp_food_pos);

    while(count < 1)
    { 

    check = 0;
    int xcoor = rand() % (boardSizeX - 1) + 1;
        int ycoor = rand() % (boardSizeY - 1) + 1;
      for(int k = 0; k < playerPosList->getSize(); k++)
            {
            playerPosList->getElement(tempBody, k);
            if(tempBody.x == xcoor && tempBody.y == ycoor)
            {
                check =1;

            }

             if(xcoor !=  tempBody.x && ycoor !=  tempBody.y && check ==0)
        {
             foodPos.setObjPos(xcoor,ycoor,'o');
            count++;
            
    }      
            
    }   
}
}




void  GameMechs::getFoodPos(objPos &returnPos)
{
    returnPos.setObjPos(foodPos.x, foodPos.y, 'o');
}
