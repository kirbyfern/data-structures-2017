//
//  BankAccountList.hpp
//  CS2ASS2PART2
//
//  Created by Kirby James on 9/24/17.
//  Copyright © 2017 oc. All rights reserved.
//
#pragma once
#ifndef BankAccountList_h
#define BankAccountList_h
#include "BankAccount.hpp"

class BankAccountList
{
private:
    const static int MAX = 30;
    BankAccount List[MAX];
    int list_state, num_elements;
public:
    // Default Constructor
    BankAccountList();
    // Explicit Constructor
    BankAccountList(int elements, int state) {
        num_elements = elements;
        list_state = state;
    }
    void addAccount(const BankAccount &BA);
    bool deleteAccount(const string &actNum);
    bool depositMoney(const string &actNum, double money);
    void makeEmpty();
    bool updateAccount();
    bool withDrawMoney(const string &actNum, double money);
    void sort(int flag);
    void setAccountAt(BankAccount &BA, unsigned int index);
    void setLastName(const string &lname, const string & actNum);
    
    //Non-mutator Functions. These do not mutate the state of BankAccountList
    bool findAccount(const string &actNum, int & i) const;
    bool getAccountAt(BankAccount &BA, unsigned int & index) const;
    double getBalance(const string &actNum) const;
    static int getCapacity();
    const string getFirstName(const string &actNum) const;
    const string getFullName(const string &actNum) const;
    void getHighestBalanceAccount(BankAccount &BA) const;
    static void getInstance(BankAccountList &BAL);
    static void getInstance(BankAccountList &BAL, ifstream &in);
    const string getLastName(const string &actNum) const;
    int getLengthOfLongestFirstName() const;
    int getLengthOfLongestLastName() const;
    int getListState() const;
    double getMeanOfAllDeposits() const;
    int getNumberOfElements() const;
    void getSmallestBalanceAccount(BankAccount & BA) const;
    bool isEmpty() const;
    bool isFull() const;
    const string listDescription() const;
    unsigned int numberOfDepositsAboveMean() const;
    unsigned int numberOfDepositsAtOrBelowMean() const;
    void print(ostream & out) const;
    void printListAsReport() const;
    void printStatistics(ostream & out) const;
    double Standard_Deviation_Deposits() const;
    double sumAllDeposits() const;
    const string toString() const;
    void writeToNewInputFile(ostream &out) const;
};

#include <stdio.h>

#endif /* BankAccountList_hpp */


