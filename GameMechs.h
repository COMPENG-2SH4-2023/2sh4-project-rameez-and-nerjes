#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib> //provides srand() and rand ()
#include <time.h> //can be replaced y <ctime>
                  //provides time()

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;


class GameMechs
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    private:
        char input;
        bool exitFlag;
        bool loseFlag;
        int score;
        bool LoseFlag;

        objPos foodPos;
        
        int boardSizeX;
        int boardSizeY;

    public:
        GameMechs();
        GameMechs(int boardX, int boardY);
        
        bool getExitFlagStatus();
        void setExitTrue();
        bool getLoseFlagStatus();
        void setLoseFlag();

        int getScore();
        void incrementScore();

        char getInput();
        void setInput(char this_input);
        void clearInput();

        int getBoardSizeX();
        int getBoardSizeY();

        void generateFood(objPosArrayList *playerPosList);
        //objPos blockOff //I need to upgrade this somehow, look at the segments in the list maybe
        void getFoodPos(objPos &returnPos);
      

};

#endif