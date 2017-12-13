//====================================================
//  main.cpp                                        //
//  Class: (Data Structures)                        //
//  Professor: Dr. Singhal                          //
//  Assignment#: 7                                  //
//  Operating Systems Used: MacOS(Xcode)            //
//  Last successful run: 11/1/17                    //
//  Created by Kirby James on 11/1/17.              //
//  Copyright © 2017 oc. All rights reserved.       //
//====================================================

//====================================================
//  Description: This program use a stack by applying
//  the rule of three and deep copies and pointer
//  memory allocation.
//====================================================


#include "Stack.hpp"
#include <iostream>
using namespace std;
Stack FillEmptyStackWithIntegersAndReturnIt();
void PopAndPrintStack(Stack Stk);
int main()
{
    {
        cout << "Creating a new Stack.\n";
        Stack IntStack = FillEmptyStackWithIntegersAndReturnIt();
        cout << "Making a copy of original stack.\n";
        Stack CopyOfIntStack;
        CopyOfIntStack = IntStack;
        cout << "Topping and Popping the original Stack:\n";
        PopAndPrintStack(IntStack);
        cout << "Topping and Popping the copy stack.\n";
        PopAndPrintStack(CopyOfIntStack);
    }
    
    cin.get();
    return 0;
}
//----------------------------------------------------------------
void PopAndPrintStack(Stack Stk)
{
    cout << "Now printing the integers pushed on the stack." << endl;
    while (!Stk.isEmpty())
    {
        cout << Stk.top().Integer << " ";
        Stk.pop();
    }
    cout << endl;
}
//-----------------------------------------------------------------
Stack FillEmptyStackWithIntegersAndReturnIt()
{
    Stack Stk;
    cout << "We will push some integers on the stack now.\n";
    bool done = false;
    int val = int();
    while (!done)
    {
        cout << "Please enter an integer to be pushed on stack : ";
        cin >> val;
        ItemType item;
        item.Integer = val;
        Stk.push(item);
        cout << "The number of items on stack :" << Stk.getNumItems() << endl;
        cout << "The capacity of stack array is: " << Stk.getArrayCapacity() << endl;
        cout << "More data? Enter 0 to continue and 1 to exit: ";
        cin >> done;
    }
    return Stk;
}
