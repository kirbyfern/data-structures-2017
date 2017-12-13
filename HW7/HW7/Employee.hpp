//====================================================
//  Employee.hpp                                    //
//  Class: (Data Structures)                        //
//  Professor: Dr. Singhal                          //
//  Assignment#: 6                                  //
//  Operating Systems Used: MacOS(Xcode)            //
//  Last successful run: 11/1/17                    //
//  Created by Kirby James on 11/1/17.              //
//  Copyright © 2017 oc. All rights reserved.       //
//====================================================

#pragma once
#ifndef Employee_hpp
#define Employee_hpp

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

class Employee {
private:
    string firstName;
    string * lastName;
    int hourWorked;
    double PayRate;
    double Salary;
public:
    // Default Constructor
    Employee();
    // Explicit Constructor
    Employee(string fName, string  lName, int hWorked, double pRate);
    
    // Copy Constructor
    Employee(const Employee & Other);
    
    // assignment operator
    const Employee & operator = (const Employee & Other);
    
    // causes no mutation in the object and returns a const object
    const string toString() const;
    
    // virtual Deconstructor
    virtual ~Employee();
};
#include <stdio.h>

#endif /* Employee_hpp */
