//====================================================
//  WordList.cpp                                    //
//  Class: (Data Structures)                        //
//  Professor: Dr. Singhal & Author                 //
//  Assignment#: 10                                 //
//  Operating Systems Used: MacOS(Xcode)            //
//  Last successful run: 11/22/17                   //
//  Created by: Kirby James on 11/19/17.            //
//  Due Date: 12/11/17                              //
//  Copyright � 2017 oc. All rights reserved.      //
//====================================================

#include "WordList.hpp"

// Default Constructor
WordList::WordList()
{
    
}

// Explicit Constructor with initialization list
WordList::WordList(string W, SinglyLinkedList<int> L) : Word(W), LineNumList(L)
{
    
}

// Accessor getList
const SinglyLinkedList<int> WordList::getList() const
{
    return LineNumList;
}

// Accessor getWord
string WordList::getWord() const
{
    return Word;
}

// Mutator setWord
void WordList::setWord(string W)
{
    Word = W;
}

// Mutator setList
void WordList::setList(SinglyLinkedList<int> L)
{
    LineNumList = L;
}

// bool operator < returns true or false
bool operator < (const WordList & LW, const WordList & RW)
{
    return (LW.Word < RW.Word);
}

// bool operator > returns true or false
bool operator > (const WordList & LW, const WordList & RW)
{
    return (LW.Word > RW.Word);
}

// bool operator == returns true or false
bool operator == (const WordList & LW, const WordList & RW)
{
    return (LW.Word == RW.Word);
}

// istream operator
istream & operator >> (istream & in, WordList & WL)
{
    string word;
    in >> word;
    WL.setWord(word);
    
    WL.LineNumList.destroy();
    int numLine = 0;
    while (in >> numLine)
    {
        WL.LineNumList.addRear(numLine);
    }
    
    return in;
}

// ostream operator <<
ostream & operator << (ostream & out, const WordList & WL)
{
    out << WL.Word << " ";
    WL.getList().printForward(out);
    
    return out;
}

// Deconstructor
WordList::~WordList()
{
    
}

