//====================================================
//  main.cpp                                        //
//  Class: CS2 (Data Structures)                    //
//  Professor: Dr. Singhal                          //
//  Assignment#: 9                                 //
//  Operating Systems Used: MacOS(Xcode)            //
//  Last successful run: 11/22/17                   //
//  Email: kirby_fernandez@elcamino.edu             //
//  Created by Kirby James Fernandez on 11/19/17.   //
//  Copyright © 2017 oc. All rights reserved.       //
//====================================================

#pragma once
#ifndef Stack_hpp
#define Stack_hpp

#include <stdio.h>
#include "StackInterface.hpp"
#include <iostream>
using namespace std;

template<typename T>
class Stack : public StackInterface<T>
{
private:
    const static int MAX = 1;
    const static int GROWBY = 1;
    int top_position;
    T * items;
    size_t numItems;
    size_t arrayCapacity;
public:
    void push(T item);
    void pop();
    T top() const;
    bool isEmpty() const;
    Stack();
    ~Stack();
    Stack(const Stack & st);
    const Stack & operator = (const Stack & Stk);
    size_t getArrayCapacity() const;
    size_t getNumItems() const;
protected:
    void copy(const Stack & Stk);
private:
    bool isFull() const;
};

#include "Stack.cpp"
#endif


