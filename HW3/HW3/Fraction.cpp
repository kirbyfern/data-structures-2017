//
//  Fraction.cpp
//  Class: (Data Structures)
//  Professor: Dr. Singhal
//  Assignment#: 3
//  Operating Systems Used: MacOS(Xcode)
//  Last successful run: 9/25/17
//  Created by Kirby James on 9/25/17.
//  Copyright © 2017 oc. All rights reserved.
//

#include "Fraction.hpp"

// Member Initialization List and Check Validation
Fraction::Fraction(long Top, long Bottom) : numerator(Top), denominator(Bottom) {
    if (denominator == 0) {
        cout << "Denominator cannot be zero." << endl;
    }
    else if (numerator == 0) {
        numerator = 0;
        denominator = 1;
    }
    else {
        normalize();
    }
}

//Pre-decrements the fraction by one.
Fraction Fraction::operator--() {
    numerator -= denominator;
    return *this;
}

//Pre-increments the fraction by one.
Fraction Fraction::operator++() {
    numerator += denominator;
    return *this;
}

//Post-decrements    the    fraction    by    one after    the    current    action    on    the    object    is    finished.
Fraction Fraction::operator--(int maker) {
    Fraction temp(*this);
    --*this; // call the prefix operator
    return temp;
}

//Post-increments    the    fraction    by    one after    the    current    action    on    the    object    is    finished.
Fraction Fraction::operator++(int maker) {
    Fraction temp(*this);
    ++*this; // call the prefix operator
    return temp;
}

//Returns    the    numerator
long Fraction::getTop() const {
    return numerator;
}

//Returns    the    denominator
long Fraction::getBottom() const {
    return denominator;
}

/*Helper    function    that    is    called    to    normalize    a    Fraction.    For    example    if    during
 constructor    call    or    during    any    mathematical    operation    a    Fraction    becomes    of
 form    such    as - 10 / -20, then    that    must    be    normalized    to    1 / 2    and    numerator
 must    be    stored    as    1    and    denominator    as    2. This    function    should    call    gcd
 function.*/
void Fraction::normalize() {
    int sign = 1;
    if (numerator < 0) {
        sign *= -1;
        numerator *= -1;
    }
    if (denominator < 0) {
        sign *= -1;
        denominator *= -1;
    }
    
    long tmp = gcd(numerator, denominator);
    numerator = numerator / tmp*sign;
    denominator = denominator / tmp;
}

//Returns    the    double    form    of    a    Fraction.    For    example    Ω        would    be    returned    as    0.5
double Fraction::toDouble() const {
    double d = (static_cast<double> (numerator)) / denominator;
    return  d;
}

/*Helper    function    that    would    assist    in    getting    the    greatest    common
 denominator    of    a    Fraction.This    could    be    used    by    the    normalize    helper
 function.GCD    function    should    not    take    sign    of    a, and    b    into    account*/
long Fraction::gcd(long a, long b) {
    while (a != b) {
        if (a > b) {
            a -= b;
        }
        else {
            b -= a;
        }
    }
    return a;
}

//returns    a    string    version    of    this    Fraction
const string Fraction::toString() const {
    ostringstream os;
    if (denominator == 1) {
        os << numerator;
    }
    else {
        os << numerator << "/" << denominator;
    }
    return os.str();
}

//Overloaded    operator    +    adds    the    num1    Fraction    to    the    num2    Fraction    and    returns the    sum
const Fraction operator +(const Fraction & num1, const Fraction & num2) {
    Fraction tmp(num1.numerator*num2.denominator
                 + num2.numerator*num1.denominator,
                 num1.denominator*num2.denominator);
    return tmp;
}

//Overloaded operator    - subtracts    from    the    num1    Fraction    the    num2    Fraction    and    returns the    difference
const Fraction operator -(const Fraction & num1, const Fraction & num2) {
    Fraction tmp(num1.numerator*num2.denominator
                 - num2.numerator*num1.denominator,
                 num1.denominator*num2.denominator);
    return tmp;
}

// Overloaded    operator    *    multiplies    the    num1    Fraction    with    the    num2    Fraction    and    returns the    product.
const Fraction operator *(const Fraction & num1, const Fraction & num2) {
    Fraction tmp(num1.numerator*num2.numerator,
                 num1.denominator*num2.denominator);
    return tmp;
}

/*Overloaded    operator    /    divides    the    num1    Fraction    with    the    num2    Fraction    and
 return    the    result.You    must    check    to    see    that    num2    is    a    non - zero    Fraction    in
 order    to    avoid    division    by    zero*/
const Fraction operator /(const Fraction & num1, const Fraction & num2) {
    Fraction tmp(num1.numerator*num2.denominator,
                 num1.denominator*num2.numerator);
    return tmp;
}

// Overloaded    operator    ==    tests    if    the    num1    and    num2    Fractions    are    same    or    not.Returns true    if    they    are    same    otherwise    returns    false.
bool operator ==(const Fraction & num1, const Fraction & num2) {
    return (num1.numerator == num2.numerator) && (num1.denominator == num2.denominator);
}

//Overloaded    operator    !=    tests    if    the    num1    and    num2    Fractions    are    different    or not.Returns    true    if    they    are    different    otherwise    returns    true.
bool operator !=(const Fraction & num1, const Fraction & num2) {
    return (num1.numerator != num2.numerator) || (num1.denominator != num2.denominator);
}

//Overloaded    insertion    operator prints    the    Fraction    either    to    the    standard    output    or    to    a    file.
ostream &operator<< (ostream & output, const Fraction & num) {
    output << num.toString();
    return output;
}

//Overloaded    extraction    operator    reads    the    data    for    a    Fraction    object    from    a    file    or    from    the    standard    input.
istream &operator>> (istream & input, Fraction & num) {
    if (&input == &cin)
    {
        long top, bottom;
        cout << "Enter the numerator: ";
        cin >> top;
        cout << "Enter the denominator: ";
        cin >> bottom;
        num = Fraction(top, bottom);
    }
    else
    {
        long top, bottom;
        input >> top >> bottom;
        num = Fraction(top, bottom);
    }
    
    return input;
}

