//
//  FractionList.hpp
//  Class: (Data Structures)
//  Professor: Dr. Singhal
//  Assignment#: 3
//  Operating Systems Used: MacOS(Xcode)
//  Last successful run: 9/25/17
//  Created by Kirby James on 9/25/17.
//  Copyright © 2017 oc. All rights reserved.
//

#pragma once
#ifndef FRACTIONLIST_HPP
#define FRACTIONLIST_HPP
#include "Fraction.hpp"
using namespace std;

class FractionList
{
private:
    bool isSorted;
    const static size_t MAX = 30;
    Fraction List[MAX];
    size_t num_elements;
    
public:
    FractionList();
    
    void addFraction(const Fraction& F);
    void getInstance(FractionList& FL);
    const Fraction getLargest();
    size_t getNumberOfElements();
    const Fraction getSmallest();
    bool getSortState();
    const Fraction getSumOfFractions();
    bool isEmpty();
    bool isFull();
    const Fraction& operator[](size_t index);
    void sort();
    const string toString();
    
    friend ostream&    operator <<(ostream    & out, const FractionList &    FL);
    friend istream&    operator >>(istream    & in, FractionList & FL);
};
#include <stdio.h>
#endif

