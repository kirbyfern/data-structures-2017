//====================================================
//  Employee.cpp                                    //
//  Class: (Data Structures)                        //
//  Professor: Dr. Singhal                          //
//  Assignment#: 7                                  //
//  Operating Systems Used: MacOS(Xcode)            //
//  Last successful run: 11/1/17                    //
//  Created by Kirby James on 11/1/17.              //
//  Copyright © 2017 oc. All rights reserved.       //
//====================================================

#include "Employee.hpp"

// Default Constructor
Employee::Employee() : firstName("First name not set"), lastName(new string("Last name not set")), hourWorked(0), PayRate(0.0), Salary(0.0)
{
    cout << "From Employee constructor" << endl;
}

// Explicit Constructor
Employee::Employee(string fName, string  lName, int hWorked, double pRate) : firstName(fName), lastName(new string(lName)), hourWorked(hWorked), PayRate(pRate)
{
    if (hourWorked <= 40) {
      //  double Salary;
        Salary = hourWorked * PayRate;
    }
    else {
        Salary = 40 * PayRate + 1.5 * (hourWorked - 40) * PayRate;
        
    }
    cout << "From Employee Explicit constructor.\n";
}

// Copy Constructor
Employee::Employee(const Employee & Other) : firstName(Other.firstName), lastName(new string(*Other.lastName)), hourWorked(Other.hourWorked), PayRate(Other.PayRate), Salary(Other.Salary)
{
    if (this == &Other)
    {
        cout << "Self copy is prohibited. Exiting." << endl;
        exit(1);
    }
    cout << "From Employee Copy Constructor" << endl;
}

const Employee & Employee::operator = (const Employee & Other)
{
    if (this == & Other)
        return *this;
    // neglect using leak_counter from example file
    this->firstName = Other.firstName;
    delete this->lastName;
    this->lastName = new string(*Other.lastName);
    this->hourWorked = Other.hourWorked;
    this->PayRate = Other.PayRate;
    this->Salary = Other.Salary;
    return *this;
}

const string Employee::toString() const
{
    ostringstream os;
    
    os << fixed << showpoint << setprecision(2);
    os << "\nEmployee Information:\n";
    os << "Name: " << firstName << " " << (*lastName) << endl;
    os << "Hours worked: " << hourWorked << endl;
    os << "Pay Rate: " << PayRate << endl;
    os << "Salary: $" << Salary << endl;

    return os.str();
}

Employee::~Employee() {
    delete lastName;
    cout << "\nde-allocated the memory allocated by employee destructor." << endl;
}


