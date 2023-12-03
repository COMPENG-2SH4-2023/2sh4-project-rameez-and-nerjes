#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    objPos tempPos;
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX() /2,mainGameMechsRef->getBoardSizeY() /2,'*');
    playerPosList = new objPosArrayList();
    playerPosList->insertHead(tempPos);

    //for debugging purpose insert another 4 segments
    //playerPosList->insertHead(tempPos);
   // playerPosList->insertHead(tempPos);
    //playerPosList->insertHead(tempPos);
    //playerPosList->insertHead(tempPos);
  
    
}



Player::~Player()
{
    // delete any heap members here
    //We can leave it empty for now until iteration 3
    delete playerPosList;
}

objPosArrayList* Player::getPlayerPos()
{
    // return the reference to the playerPos arrray list
    return playerPosList;
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic 
    //hint for getting input
        //def not challing maculibgetchar
        //coordinate with team member whosd desiginning gamemecahnism class
        //there will be a method is gamemecahnism class that collectively checks input and store the most recent input. ypu just need to figure out 
        //how to get it//How it lies within the gamemechanis * inside your private member

        char input = mainGameMechsRef->getInput();
        switch(input)
        {                      
            case 'w':
                if(myDir == LEFT || myDir == RIGHT || myDir  == STOP)
                {
                    myDir =  UP;
                  
                   
                }
                break;
            // Add more key processing here
            case 'd':
                if(myDir == UP || myDir ==  DOWN|| myDir  == STOP)
                {
                    myDir = RIGHT; 
                }
                break;
            // Add more key processing here    
            case 'a':
                if(myDir ==  UP || myDir == DOWN ||  myDir  == STOP)
                {
                    myDir = LEFT;
                  
                }
                break;
            // Add more key processing here    
            case 's':
                if(myDir== LEFT  || myDir== RIGHT ||  myDir  == STOP)
                {
                    myDir=  DOWN;
                }
                break;
        }
   
       
 
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic

    objPos currHead; //holding the pos info of the current head
    playerPosList->getHeadElement(currHead);
   switch(myDir)
        {                      
            case UP:
                 currHead.y--;
                if( currHead.y == 0)
                {
                    currHead.y= mainGameMechsRef->getBoardSizeY()-1;
                }
                break;
            case RIGHT:
                currHead.x++;
                if(currHead.x == mainGameMechsRef->getBoardSizeX())
                {
                    currHead.x= 1;
                }
                break;
            case LEFT:
               currHead.x--;
                if(currHead.x == 0)
                {
                    currHead.x= mainGameMechsRef->getBoardSizeX()-1;
                }
               break;
            case DOWN:
                  currHead.y++;
                if(  currHead.y==  mainGameMechsRef->getBoardSizeY())
                {
                      currHead.y= 1;
                }
                break;
            default:
                break;
        }

        //new current head should be inserted to the head of the list,
        playerPosList->insertHead(currHead);
        // then, remove tail
        playerPosList->removeTail();

  
}

bool Player::checkFoodConsumption()
{
    

    objPos currHead; //holding the pos info of the current head
    playerPosList->getHeadElement(currHead);
    objPos foodPoss;
    mainGameMechsRef->getFoodPos(foodPoss);
    return (foodPoss.isPosEqual(&currHead)); 
  
}

void Player::incresePlayerLength()
{
    objPos currHead;
    playerPosList->getHeadElement(currHead);
    playerPosList->insertHead(currHead);
}

bool Player::checkSelfCollision()
{
    objPos currHead;
    objPos tempBody;
    playerPosList->getHeadElement(currHead);
    //something weird is happening here why
    for(int j = 2; j < playerPosList->getSize(); j++)
            {
            playerPosList->getElement(tempBody, j);
            if(tempBody.isPosEqual(&currHead))
            {
                mainGameMechsRef->setLoseFlag();
                mainGameMechsRef->setExitTrue();

             
            }
            }
}

        
 


