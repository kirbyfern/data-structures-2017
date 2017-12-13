//
//  BankAccount.cpp
//  CS2ASS2FINAL
//
//  Created by Kirby James Fernandez on 9/18/17.
//  Dr. Singhal
//  Data Structures
//  Copyright © 2017 oc. All rights reserved.
//

#include "BankAccount.hpp"

BankAccount::BankAccount()
{
    cout << "In default constructor: " << endl;
    ActNum = "Account number not set";
    FirstName = "First name not set";
    LastName = "Last name not set";
    balance = 0;
    
}

// Member Initialization List
BankAccount::BankAccount(const string & actN, const string & fname, const string lname, double bal):ActNum(actN), FirstName(fname), LastName(lname), balance(bal)
{
    if(bal < 0)
    {
        cout << "Balance cannot be negative" << endl;
        bal = 0;
    }
}
// toString function
const string BankAccount::toString() const{
    string sBalance = "$" + to_string(BankAccount::getBalance());
    return sBalance.substr(0, sBalance.find(".", 0)) + ".00";
}

// Set AccountNumber
void BankAccount::setAccountNumber(const string &actN)
{
    ActNum = actN;
}
// Set LastName
void BankAccount::setLastName(const string &lname)
{
    LastName = lname;
}
// Get AccountNumber
string BankAccount::getAccountNumber() const
{
    return ActNum;
}
// Get Balance
double BankAccount::getBalance() const
{
    return balance;
}
// Get FirstName
const string BankAccount::getFirstName() const
{
    return FirstName;
}
// Get LastName
const string BankAccount::getLastName() const
{
    return LastName;
}
// Get FullName
const string BankAccount::getFullName() const
{
    return FirstName + ' ' + LastName;
}
// Gets an unfilled BankAccount object BA passed by reference and is filled by this function
void BankAccount::getInstance(BankAccount &BA)
{
    string actN, lname, fname;
    double bal;
    
    cout << "Enter Account Number: " << flush;
    cin >> actN;
    cout << "Enter Last Name: " << flush;
    cin >> lname;
    cout << "Enter First Name: " << flush;
    cin >> fname;
    cout << "Enter Opening Balance: " << flush;
    cin >> bal;
    
    BA = BankAccount(actN, fname, lname, bal);
    
}
// The static function getInstance above gets an unfilled BankAccount object filled by this function from the input file bonded to ifstream object in
void BankAccount::getInstance(BankAccount &BA, ifstream &in)
{
    string actN, lname, fname;
    double bal;
    
    in >> actN;
    in >> lname;
    in >> fname;
    in >> bal;
    
    BA = BankAccount(actN, fname, lname, bal);
}
// Deposit Money
void BankAccount::deposit(double money)
{
    if (money > 0) {
        balance += money;
    }
    else {
        cout << "Invalid amount, please try again." << endl;
    }
}
// Withdraw Money
void BankAccount::withdraw(double money)
{
    if (money > 0 && money <= balance) {
        balance -= money;
    }
    else if (money > balance) {
        cout << "Insufficient funds, please try again." << endl;
    }
    else {
        cout << "Invalid amount, please try again." << endl;
    }
}





