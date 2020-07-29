//Codi Uhouse - CSCI385 - Stable Matching Implementation File

#include "stablelist.h"
#include <iostream>

struct MenPtr
{
    std::string name;
    MenPtr* nextMan;
};


MenList::MenList()
{
    length = 0;
    topMan = NULL;
}


MenList::~MenList()
{
    MenPtr* temp;
    MenPtr* currentPtr = topMan;

    while(currentPtr != NULL)
    {
        temp = currentPtr;
        currentPtr = currentPtr->nextMan;
        delete temp;
    }
}


MenList::MenList(const MenList& otherstack)
{
    Copy(otherstack);
}


MenList& MenList::operator=(const MenList& otherstack)
{
    if(topMan->name != otherstack.topMan->name)
    {
        Copy(otherstack);
    }
}


void MenList::Copy(const MenList& otherstack)
{
    MenPtr* fromListPtrMan;
    MenPtr* toListPtrMan;
    length = otherstack.length;

    if(otherstack.topMan == NULL)
    {
        topMan = NULL;

        return;
    }

    fromListPtrMan = otherstack.topMan;
    topMan = new MenPtr;
    topMan->name = fromListPtrMan->name;

    toListPtrMan = topMan;
    fromListPtrMan = fromListPtrMan->nextMan;

    while(fromListPtrMan != NULL)
    {
        toListPtrMan->nextMan = new MenPtr;
        toListPtrMan = toListPtrMan->nextMan;
        toListPtrMan->name = fromListPtrMan->name;
        fromListPtrMan = fromListPtrMan->nextMan;
    }

    toListPtrMan->nextMan = NULL;
}


void MenList::PushMan(std::string n)
{
    MenPtr* newManPtr = new MenPtr;

    if(n != " " && n != "")
    {  
        newManPtr->name = n;
        newManPtr->nextMan = topMan;

        topMan = newManPtr;

        length++;
    }
}


void MenList::PopMan()
{
    MenPtr* temp;

    if(!IsEmpty())
    {
        temp = topMan;
        topMan = topMan->nextMan;
        temp->nextMan = NULL;

        length --;
    }
}


std::string MenList::Peek()
{
    if(!IsEmpty())
    {
        return topMan->name;
    }
    else
    {
        return "";
    }
}


int MenList::GetLength() const
{
    return length;
}


bool MenList::IsEmpty() const
{
    return (topMan == NULL);
}


bool MenList::IsFull() const
{
    return false;
}


void MenList::Display()
{
    MenPtr* temp;

    if(topMan != NULL)
    {
        temp = topMan;
        while(temp != NULL)
        {
            std::cout << temp->name << " ";
            temp = temp->nextMan;
        }
    }
}

