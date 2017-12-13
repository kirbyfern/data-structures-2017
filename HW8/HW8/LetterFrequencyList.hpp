//====================================================
//  main.cpp                                        //
//  Class: (Data Structures)                        //
//  Professor: Dr. Singhal                          //
//  Assignment#: 8                                  //
//  Operating Systems Used: MacOS(Xcode)            //
//  Last successful run: 11/13/17                   //
//  Created by Kirby James  on 11/12/17.            //
//  Copyright © 2017 oc. All rights reserved.       //
//====================================================


#pragma once
#ifndef LetterFrequencyList_hpp
#define LetterFrequencyList_hpp
#include "LetterNode.hpp"

class LetterFrequencyList {
public:
    LetterNode * HeadPtr;
    // Constructor
    LetterFrequencyList();
    // Destructor
    ~LetterFrequencyList();
    bool contains(char ltr);
    void copy(const LetterFrequencyList &Other);
    void destroy();
    void insert(char ltr, size_t frq);
    void insertInOrder(char ltr);
    LetterFrequencyList(const LetterFrequencyList &Other);
    LetterFrequencyList &operator =(const LetterFrequencyList &Other);
    const string toString();
    
};

#endif /* LetterFrequencyList_hpp */
