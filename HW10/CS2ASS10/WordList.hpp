//====================================================
//  WordList.hpp                                    //
//  Class: (Data Structures)                        //
//  Professor: Dr. Singhal & Author                 //
//  Assignment#: 10                                 //
//  Operating Systems Used: MacOS(Xcode)            //
//  Last successful run: 11/22/17                   //
//  Created by: Kirby James on 11/19/17.            //
//  Due Date: 12/11/17                              //
//  Copyright � 2017 oc. All rights reserved.      //
//====================================================

#pragma once
#ifndef WORDLIST_HPP
#define WORDLIST_HPP

#include "iterator.h"
#include "linkedlistinterface.h"
#include "Added.hpp"
using namespace Added;

class WordList
{
private:
    /* --- Stores the word from text file --- */
    string Word;
    /* --- Stores the line numbers (as integers) on which the Word is found --- */
    SinglyLinkedList<int> LineNumList;
public:
    WordList();
    WordList(string wrd, SinglyLinkedList<int> LNL);
    
    /* -- NOTE: inline doesnt work on mac -- */
    
    /* --- MUTATORS AND ACCESSORS --- */
    void setList(SinglyLinkedList<int> L);
    void setWord(string W);
    const SinglyLinkedList<int> getList() const;
    string getWord() const;
    
    friend bool operator < (const WordList & LW, const WordList & RW);
    friend bool operator == (const WordList & LW, const WordList & RW);
    friend bool operator > (const WordList & LW, const WordList & RW);
    
    /* --- Reads data from the file or keyboard to fill the WordList object --- */
    friend istream & operator >> (istream & in, WordList & WL);
    /* --- Writes data to the file or to screen to print the WordList object ---*/
    friend ostream & operator << (ostream & out, const WordList & WL);
    /* VIRTUAL DESTRUCTOR */
    virtual ~WordList();
};

#include <stdio.h>

#endif /* WordList_hpp */

