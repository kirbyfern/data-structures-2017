//====================================================
//  Added.cpp                                       //
//  Class: (Data Structures)                        //
//  Professor: Dr. Singhal                          //
//  Assignment#: 10                                 //
//  Operating Systems Used: MacOS(Xcode)            //
//  Last successful run: 11/22/17                   //
//  Created by: Kirby James on 11/19/17.            //
//  Due Date: 12/11/17                              //
//  Copyright � 2017 oc. All rights reserved.      //
//====================================================

#include "Added.hpp"

using namespace Added;

// this evaluates each character
string Added::getToken(string &Line)
{
    string Token;
    // if it's an empty line initialize token empty and just return it as empty
    if (Line == "")
    {
        Token = "";
        return Token;
    }
    
    // check first character and remove non-alpha first characters
    // if line is an empty line return an empty token
    while (!isalpha(Line[0]))
    {
        Line.erase(0, 1);
        
        if (Line == "")
        {
            return Token;
        }
    }
    
    // if not a blank line add the first character to token
    // remove first character to refresh
    while (isalpha(Line[0]) && Line != "")
    {
        Token = Token + Line[0];
        Line.erase(0, 1);
    }
    
    return Token;
}

// function ConvertToLower returns all lower case
string Added::ConvertToLower(string Str)
{
    for (auto & dummy : Str) dummy = tolower(dummy);
    
    return Str;
}




