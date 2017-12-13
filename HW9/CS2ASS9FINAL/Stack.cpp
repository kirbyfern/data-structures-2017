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

#ifndef STACK_CPP
#define STACK_CPP
#include "Stack.hpp"

//------------------------------- Default Constructor
template <typename T>
Stack<T>::Stack() : top_position (-1),items(new T[MAX]),numItems(0),arrayCapacity(MAX)
{
    cout << "From Stack default constructor." << endl << endl;
}

//------------------------------- Copy Constructor
template <typename T>
Stack<T>::Stack(const Stack & st) {
    if (this == & st)
    {
        cout << "Self copy is prohibited. Exiting." << endl;
        exit(1);
    }
    copy(st);
    
    cout << "From Stack Copy Constructor." << endl;
}

//----------------------------------- Is Empty
template <typename T>
bool Stack<T>::isEmpty() const
{
    return (top_position == -1);
}

//------------------------------------ Is Full
template <typename T>
bool Stack<T>::isFull() const
{
    return (top_position == arrayCapacity - 1);
}

//----------------------------------- Top
template <typename T>
T Stack<T>::top() const
{
    if (isEmpty())
    {
        throw "Stack is empty";
    }
    else
    {
        return items[top_position];
    }
}

//------------------------------------ Pop
template <typename T>
void Stack<T>::pop()
{
    if (isEmpty())
    {
        cerr << "The stack is empty.\n";
        return;
    }
    else
    {
        top_position--;
        numItems--;
    }
}

//------------------------------------------ Push
template <typename T>
void Stack<T>::push(T newItem)
{
    if (arrayCapacity > this->numItems)
    {
        top_position++;
        items[top_position] = newItem;
        numItems++;
    }
    else {
        size_t len = arrayCapacity + GROWBY;
        T * Temp;
        
        Temp = new T[len];
        
        for (size_t index = 0; index < this->numItems; index++)
        {
            Temp[index] = items[index];
        }
        
        delete[] items;
        items = Temp;
        Temp = nullptr;
        arrayCapacity = len;
        
        top_position++;
        items[top_position] = newItem;
        this->numItems = this->numItems + 1;
    }
    
}

//------------------------------------------ Copy
template <typename T>
void Stack<T>::copy(const Stack<T> & Stk) {
    this->items = new T[Stk.arrayCapacity];
    
    for (size_t i = 0; i < Stk.arrayCapacity; i++)
    {
        this->items[i] = Stk.items[i];
    }
    this->arrayCapacity = Stk.arrayCapacity;
    this->numItems = Stk.numItems;
    this->top_position = Stk.top_position;
}

//------------------------------------------ Assignment Operator
template <typename T>
const Stack<T> & Stack<T>::operator = (const Stack<T> & Stk) {
    if (this != &Stk)
    {
        delete[] items;
        copy(Stk);
    }
    
    cout << "From Stack Assignment operator." << endl;
    return *this;
}

//------------------------------------------ Get Array Capacity
template <typename T>
size_t Stack<T>::getArrayCapacity() const {
    return arrayCapacity;
}

//------------------------------------------ Get Num Items
template <typename T>
size_t Stack<T>::getNumItems() const {
    return numItems;
}

//---------------------------------- Deconstructor
template <typename T>
Stack<T>::~Stack()
{
    delete [] items;
    cout << "From Stack Destructor." << endl;
}

#endif

