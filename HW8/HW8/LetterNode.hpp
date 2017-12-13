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


#pragma once
#ifndef LetterNode_hpp
#define LetterNode_hpp
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

class LetterNode {
public:
    size_t frequency;
    char letter;
    LetterNode * Next;
    
    LetterNode(char ch, size_t frq, LetterNode * ptr);
    const string toString();
};

#endif /* LetterNode_hpp */
