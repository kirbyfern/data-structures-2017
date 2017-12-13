//
//  PostFixEval.cpp
//  Class: (Data Structures)
//  Professor: Dr. Singhal
//  Assignment#: 5
//  Operating Systems Used: MacOS(Xcode)
//  Last successful run: 10/25/17
//  Created by Kirby James on 10/21/17.
//  Copyright © 2017 oc. All rights reserved.
//

#include "PostFixEval.hpp"

PostFixEval::PostFixEval(string exp) : expression(exp), value(0.0), numeric(false)
{
    string output, postfixExpression;
    numeric = isNumeric();
    
    output = " ";
    source = " ";
    
    ReversePolishNotation RPN(expression, output);
    RPN.convert();
    source = RPN.getOutput();
    findValue();
}

// returns true if expression is numeric or false if not
bool PostFixEval::isNumeric()
{
    size_t counter;
    string stringArr[MAX];
    bool notOk;
    counter = 0;
    notOk = false;
    
    TokenizerParser::getStringArray(stringArr, expression, MAX, counter);
    
    // Loop will run at most once
    for (size_t i = 0; i < counter; i++)
    {
        if ((stringArr[i] >= "a" && stringArr[i] <= "z") || (stringArr[i] >= "A" && stringArr[i] <= "Z")) {
            return notOk;
        }
        else {
            notOk = true;
        }
    }
    return notOk;
}

double PostFixEval::evaluate()
{
    string stringArr[MAX], output;
    Stack stk;
    ItemType itm;
    double result;
    size_t counter;
    
    output = " ";
    counter = 0;
    result = 0.0;
    
    ReversePolishNotation RPN(expression, output);
    RPN.convert();
    
    // tokenized the expression inputted by the user by stripping the white spaces and return a set of array of strings
    TokenizerParser::getStringArray(stringArr, RPN.getOutput(), MAX, counter);
    
    // loop through each index from the set of array of strings
    for (size_t i = 0; i < counter; i++)
    {
        if (stringArr[i] == "+" || stringArr[i] == "-" || stringArr[i] == "*" || stringArr[i] == "/")
        {
            // POP first expression
            double frstPop = stk.top().Double;
            stk.pop();
            
            // POP second expression
            double scndPop = stk.top().Double;
            stk.pop();
            
            // if the expression is an operator pop from stack perform evaluation
            if (stringArr[i] == "+")
            {
                // <second POP> <operator> <first POP>
                result = scndPop + frstPop;
                itm.Double = result;
                stk.push(itm);
            }
            else if (stringArr[i] == "-")
            {
                // <second POP> <operator> <first POP>
                result = scndPop - frstPop;
                itm.Double = result;
                stk.push(itm);
            }
            else if (stringArr[i] == "*")
            {
                // <second POP> <operator> <first POP>
                result = scndPop * frstPop;
                itm.Double = result;
                stk.push(itm);
            }
            else if (stringArr[i] == "/")
            {
                // <second POP> <operator> <first POP>
                result = scndPop / frstPop;
                itm.Double = result;
                stk.push(itm);
            }
        }
        else
        {
            itm.Double = TokenizerParser::parseDouble(stringArr[i]);
            stk.push(itm);
        }
    }
    result = stk.top().Double;
    stk.pop();
    return result; // return the result to the function itself
}

void PostFixEval::findValue()
{
    if (numeric) {
        // sets the data member value equal to the value returned by the function evaluate.
        value = evaluate();
    }
}

void PostFixEval::print(ostream & out) const
{
    if (numeric) {
        out << "The postfix form of " << expression << " is: " << endl;
        out << source << endl;
        out << "Computed value of this postfix expression is: " << value << endl;
    }
    else {
        out << "The postfix form of " << expression << " is: " << endl;
        out << source << endl;
        out << "The infix expression you entered isn't pure numeric expression." << endl;
        out << "No computation of its value can be done." << endl;
    }
}

bool isOperator(char c, char wstr)
{
    return false;
}

PostFixEval::~PostFixEval()
{
    
}


