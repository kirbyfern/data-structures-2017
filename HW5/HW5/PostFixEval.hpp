//
//  PostFixEval.hpp
//  Class: (Data Structures)
//  Professor: Dr. Singhal
//  Assignment#: 5
//  Operating Systems Used: MacOS(Xcode)
//  Last successful run: 10/25/17
//  Created by Kirby James on 10/21/17.
//  Copyright © 2017 oc. All rights reserved.
//

#pragma once
#ifndef PostFixEval_HPP
#define PostFixEval_HPP

#include "Stack.hpp"
#include "TokenizerParser.hpp"
#include "ReversePolishNotation.hpp"
#include "ItemType.hpp"

class PostFixEval
{
private:
    string expression;
    bool hasValidValue; // optional
    bool isValidExp;    // optional
    bool numeric;
    string source;      // optional
    double value;
protected:
    double evaluate();
    bool isNumeric();
public:
    // Default and Explicit Constructor
    PostFixEval(string exp = "");
    
    // Public Member Functions
    void findValue();
    void print(ostream & out = cout) const;
    bool isOperator(char c, char wstr); // undetailed
    // Destructor
    ~PostFixEval();
};

#include <stdio.h>

#endif /* PostFixEval_hpp */

