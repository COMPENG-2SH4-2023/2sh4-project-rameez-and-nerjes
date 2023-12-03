#include "objPosArrayList.h"

// Paste your CUTE Tested implementation here.
// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    aList = new objPos[ARRAY_MAX_CAP];
    listSize = 0; // no valid element in the list upon start up
    arrayCapacity = ARRAY_MAX_CAP; //array capacity should be maz
}

objPosArrayList::~objPosArrayList()
{
delete[] aList; // remember to use delete[] to call the 
                //destructos of all instances in the array
}               //Otherwise, only the first element will be properlt deleted, leading to leak

int objPosArrayList::getSize()
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{

    //Still need error check - what if listSize is a t capacity
    // -check if listSize is equal to arrayCapacity.If yes, at capacity, don't insert.
if(listSize != 0 && listSize != arrayCapacity)
{
for(int i = listSize; i > 0; i--)
{
    aList[i].setObjPos(aList[i-1]); //this will shuffle all the elements towards the tail
}
}

aList[0].setObjPos(thisPos);

listSize++;
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if(listSize != arrayCapacity)
    {
    aList[listSize++].setObjPos(thisPos);
    }
}

void objPosArrayList::removeHead()
{
    
    for(int i = 0; i < listSize; i++)
{
    aList[i].setObjPos(aList[i+1]); //this will shuffle all the elements towards the tail
}

listSize--;
    
}

void objPosArrayList::removeTail()
{
    listSize--;

}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[0]);
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
returnPos.setObjPos(aList[listSize-1]);
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    returnPos.setObjPos(aList[index]);
}
