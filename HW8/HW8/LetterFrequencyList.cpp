//====================================================
//  main.cpp                                        //
//  Class: (Data Structures)                        //
//  Professor: Dr. Singhal                          //
//  Assignment#: 8                                  //
//  Operating Systems Used: MacOS(Xcode)            //
//  Last successful run: 11/13/17                   //
//  Created by Kirby James on 11/12/17.             //
//  Copyright © 2017 oc. All rights reserved.       //
//====================================================

#include "LetterFrequencyList.hpp"

//------------------------------------------------------------------ Default Constructor
LetterFrequencyList::LetterFrequencyList() : HeadPtr(new LetterNode('-', 0, nullptr))
{
    
}

//------------------------------------------------------------------ Copy Constructor
LetterFrequencyList::LetterFrequencyList(const LetterFrequencyList& Other)
{
    if (this == &Other)
    {
        cout << "Self copying not allowed. Exiting program.\n";
        exit(0);
    }
    copy(Other);
}

//------------------------------------------------------------------ Contains
bool LetterFrequencyList::contains(char ltr) // optional
{
    LetterNode *Current = HeadPtr->Next;
    
    while (Current != nullptr)
    {
        if (Current->letter == ltr)
        {
            return true;
        }
        Current = Current->Next;
    }
    return false;
}

//------------------------------------------------------------------ Copy Function
void LetterFrequencyList::copy(const LetterFrequencyList& Other)
{
    LetterNode *Current = Other.HeadPtr->Next;
    LetterNode *Iterator = HeadPtr = new LetterNode('-', 0, nullptr);
    while (Current != nullptr)
    {
        // create a copy of node pointed to by Current, and link up
        Iterator->Next = new LetterNode(Current->letter, Current->frequency, nullptr);
        
        // update pointers
        Current = Current->Next;
        Iterator = Iterator->Next;
    }
}

//----------------------------------------------------------------- Destroy
void LetterFrequencyList::destroy()
{
    LetterNode* Current = HeadPtr;
    while (Current != nullptr)
    {
        LetterNode *save = Current;
        Current = Current->Next;
        delete save;
    }
}

//----------------------------------------------------------------- Insert 
void LetterFrequencyList::insert(char ltr, size_t frq)
{
    LetterNode *Current = HeadPtr;
    LetterNode *Previous = nullptr;
    
    if (HeadPtr->Next != nullptr) // if list is not empty
    {
        while (Current != nullptr)
        {
            if (Current->letter >= ltr)
            {
                break;
            }
            else
            {
                Previous = Current;
                Current = Current->Next;
            }
        }
        LetterNode *NewNode = new LetterNode(ltr, frq, nullptr);
        
        NewNode->Next = Current;
        Previous->Next = NewNode;
    }
    else
    {
        HeadPtr->Next = new LetterNode(ltr, frq, nullptr);
    }
}

////----------------------------------------------------------------- Insert ORIGINAL
//void LetterFrequencyList::insert(char ltr, size_t frq)
//{
//    LetterNode *Current = HeadPtr;
//    bool added = false;
//
//    while (Current != nullptr)
//    {
//        if (Current->letter == ltr && !added)
//        {
//            Current->frequency++;
//            added = true;
//        }
//        else if (Current->letter != ltr && Current->Next == nullptr && !added)
//        {
//            insertInOrder(ltr);
//            added = true;
//        }
//        else
//        {
//            Current = Current->Next;
//        }
//    }
//}

//----------------------------------------------------------------- insertInOrder
void LetterFrequencyList::insertInOrder(char ltr)
{
    LetterNode *Current = HeadPtr->Next;
    
    if (contains(ltr))
    {
        while (Current != nullptr) {
            if (ltr == Current->letter) {
                Current->frequency++;
                break;
            }
            Current = Current->Next;
        }
    }
    else
    {
        insert(ltr, 1);
    }
}


////----------------------------------------------------------------- insertInOrder ORIGINAL
//void LetterFrequencyList::insertInOrder(char ltr)
//{
//    LetterNode *Current;
//    LetterNode *NewNode = new LetterNode(ltr, 1, nullptr);
//    if (HeadPtr == nullptr || (HeadPtr)->letter >= NewNode->letter)
//    {
//        NewNode->Next = HeadPtr;
//        HeadPtr = NewNode;
//    }
//    else
//    {
//        // Locate the node before the point of insertion
//        Current = HeadPtr;
//        while (Current->Next != nullptr &&
//               Current->Next->letter < NewNode->letter)
//        {
//            Current = Current->Next;
//        }
//        NewNode->Next = Current->Next;
//        Current->Next = NewNode;
//    }
//}

//------------------------------------------------------------------ Assignment Operator
LetterFrequencyList& LetterFrequencyList::operator = (const LetterFrequencyList& Other) {
    if (this != &Other)
    {
        destroy();
        copy(Other);
    }
    
    return *this;
}

//----------------------------------------------------------------- toString
const string LetterFrequencyList::toString()
{
    if (!(HeadPtr == nullptr))
    {
        string text = "";
        
        LetterNode * Iterator = HeadPtr->Next;
        
        while (Iterator != nullptr)
        {
            text += (Iterator->toString());
            Iterator = Iterator->Next;
        }
        return (text + '\n');
    }
    else
    {
        throw "No linked list exists.";
    }
}

LetterFrequencyList::~LetterFrequencyList()
{
    destroy();
}

