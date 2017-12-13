//
//  BankAccount.hpp
//  CS2ASS2
//
//  Created by Kirby James on 9/13/17.
//  Dr. Singhal
//  Data Structures
//  Copyright � 2017 oc. All rights reserved.
//

#pragma once
#ifndef BankAccount_h
#define BankAccount_h
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <cmath>

using namespace std;

class BankAccount
{
private:
    string ActNum;
    string LastName;
    string FirstName;
    double balance;
public:
    // Default Constructor
    BankAccount();
    
    // Explicit Constructor
    BankAccount(const string & actN, const string & fname, const string lname, double bal);
    
    /*
     * ORDER OF MEMBER FUNCTIONS:
     * toString
     * Mutators
     * Accessors
     * Functions
     */
    
    const string toString() const;
    void setAccountNumber(const string &actN);
    void setLastName(const string &name);
    string getAccountNumber() const;
    double getBalance() const;
    const string getFirstName() const;
    const string getFullName() const;
    const string getLastName() const;
    static void getInstance(BankAccount &BA);
    static void getInstance(BankAccount &BA, ifstream &in);
    void deposit(double money);
    void withdraw(double money);
};

#include <stdio.h>

#endif /* BankAccount_h*/

