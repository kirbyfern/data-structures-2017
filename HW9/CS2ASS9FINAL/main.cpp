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

#include "Stack.hpp"
#include "BankAccount.hpp"

using namespace std;
void testInt();
void testBankAccount();
void testChar();
void testString();

int main()
{
     testInt();
     testBankAccount();
     testChar();
     testString();
    
    cin.get();
    return 0;
}

void testInt()
{
    Stack<int> intStack;
    
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);
    intStack.push(4);
    intStack.push(5);
    cout << "Now printing the integers in the Stack.\n";
    
    while (!intStack.isEmpty())
    {
        cout << intStack.top() << "  ";
        intStack.pop();
    }
    
    cout << endl;
}

void testBankAccount()
{
    Stack<BankAccount> baStack;
    
    BankAccount BA1("1234", "Kirby", "James", 300.40);
    BankAccount BA2("4567", "Donald", "Trump", 49.21);
    BankAccount BA3("8912", "Bill", "Gates", 4210.20);
    BankAccount BA4("4321", "Elon", "Musk", 555.55);
    BankAccount BA5("2244", "Mark", "Zuckerberg", 999.99);
    
    baStack.push(BA1);
    baStack.push(BA2);
    baStack.push(BA3);
    baStack.push(BA4);
    baStack.push(BA5);
    
    cout << "Now printing the BankAccount in the Stack.\n";
    
    while (!baStack.isEmpty())
    {
        cout << baStack.top().toString() << endl;
        baStack.pop();
    }
    
}

void testChar()
{
    Stack<char> chStack;
    
    chStack.push('A');
    chStack.push('B');
    chStack.push('C');
    chStack.push('D');
    chStack.push('F');
    
    cout << "Now printing the characters in the Stack.\n";
    
    while (!chStack.isEmpty())
    {
        cout << chStack.top() << "  ";
        chStack.pop();
    }
    
    cout << endl;
}

void testString()
{
    Stack<string> stringStack;
    
    stringStack.push("Hello");
    stringStack.push("I am");
    stringStack.push("a string");
    stringStack.push("please");
    stringStack.push("I am not what you think");
    
    cout << "Now printing the strings in the Stack.\n";
    
    while (!stringStack.isEmpty())
    {
        cout << stringStack.top() << "  ";
        stringStack.pop();
    }
    
    cout << endl;
}
