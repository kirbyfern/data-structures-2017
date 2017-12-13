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
#ifndef STACK_H
#define STACK_H

template <typename T>
class StackInterface
{
public:
    virtual void push(T item) = 0;
    virtual void pop() = 0;
    virtual T top() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    StackInterface() {}
    virtual ~StackInterface(){}
};

#endif

