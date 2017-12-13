//====================================================
//  main.cpp                                        //
//  Class: (Data Structures)                        //
//  Professor: Dr. Singhal                          //
//  Assignment#: 8                                  //
//  Operating Systems Used: MacOS(Xcode)            //
//  Last successful run: 11/13/17                   //
//  Created by Kirby Jame on 11/12/17.              //
//  Copyright © 2017 oc. All rights reserved.       //
//====================================================


#include "LetterNode.hpp"

LetterNode::LetterNode(char ch, size_t frq, LetterNode* ptr) : letter(ch), frequency(frq), Next(ptr)
{
    
}

const string LetterNode::toString()
{
    string s = "Letter ";
    s += this->letter; // s = s + this->letter;
    s += " occured "; // s = s + " occured ";
    s += to_string(this->frequency) + " times. \n"; // s = s + to_string(this->frequency) + " times. \n";
    
    return s;
}

