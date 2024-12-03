#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{

    listSize = 3;
    aList = new objPos[ARRAY_MAX_CAP];

    for (int i = 0; i < listSize; i++)
    {
        aList[i] = objPos();
    }
}

objPosArrayList::objPosArrayList(int size)
{
    listSize = size;
    aList = new objPos[ARRAY_MAX_CAP];

    for (int i = 0; i < listSize; i++)
    {
        aList[i] = objPos();
    }
}

objPosArrayList::objPosArrayList(int x, int y, int size)
{
    listSize = size;

    aList = new objPos[ARRAY_MAX_CAP];

    for (int i = 0; i < listSize; i++)
    {
        aList[i] = objPos(x, y + i, ' ');
    }
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

int objPosArrayList::getSize() const
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if (listSize >= arrayCapacity)
    {
        arrayCapacity = arrayCapacity * 2;
    }

    for (int i = listSize; i > 0; i--)
    {
        aList[i] = aList[i - 1];
    }

    aList[0] = thisPos;
    listSize++;
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if (listSize >= arrayCapacity)
    {
        arrayCapacity = arrayCapacity * 2;
    }
    
    aList[listSize++] = thisPos;
}

void objPosArrayList::removeHead()
{
    for (int i = 1; i < listSize; i++)
    {
        aList[i - 1] = aList[i];
    }

    listSize--;
}

void objPosArrayList::removeTail()
{
    listSize--;
}

objPos objPosArrayList::getHeadElement() const
{
    return aList[0];
}

objPos objPosArrayList::getTailElement() const
{
    return aList[listSize - 1];
}

objPos objPosArrayList::getElement(int index) const
{
    return aList[index];
}

