//
//  Fraction.hpp
//  Class: (Data Structures)
//  Professor: Dr. Singhal
//  Assignment#: 3
//  Operating Systems Used: MacOS(Xcode)
//  Last successful run: 9/25/17
//  Created by Kirby James on 9/25/17.
//  Copyright © 2017 oc. All rights reserved.
//

#pragma once
#ifndef FRACTION_HPP
#define FRACTION_HPP
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;

class Fraction
{
private:
    long denominator;
    long numerator;
public:
    Fraction(long Top = 0, long    Bottom = 1);
    
    Fraction operator--();
    Fraction operator++();
    Fraction operator--(int maker);
    Fraction operator++(int maker);
    long getTop() const;
    long getBottom() const;
    void normalize();
    double toDouble() const;
    long gcd(long a, long b);
    const string toString() const;
    
    friend const Fraction operator +(const Fraction & num1, const Fraction & num2);
    friend const Fraction operator -(const Fraction & num1, const Fraction & num2);
    friend const Fraction operator *(const Fraction & num1, const Fraction & num2);
    friend const Fraction operator /(const Fraction & num1, const Fraction & num2);
    friend bool operator ==(const Fraction & num1, const Fraction & num2);
    friend bool operator !=(const Fraction & num1, const Fraction & num2);
    friend ostream &operator<< (ostream    & output, const    Fraction & num);
    friend istream &operator>> (istream    & input, Fraction & num);
    
};
#include <stdio.h>
#endif

