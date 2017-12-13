//====================================================
//  main.cpp                                        //
//  Class: (Data Structures)                        //
//  Professor: Dr. Singhal                          //
//  Assignment#: 6                                  //
//  Operating Systems Used: MacOS(Xcode)            //
//  Last successful run: 10/25/17                   //
//  Created by Kirby James on 10/27/17.             //
//  Copyright © 2017 oc. All rights reserved.       //
//====================================================

//====================================================
//  Description: This program use a stack and queue
//  class designed to store character data type and
//  determine whether the inputted string is a word
//  palindrome or not
//
//
//  A palindrome is a sequence of characters,
//  usually a sentence, which “reads”
//  the same forward or backwards,
//  disregarding punctuations, spaces,
//  digits, and with no distinction between
//  upper – and lower – case letters. For
//  example “Race car”, and “A man, a plan,
//  a canal : Panama!” are both palindromes.
//====================================================


#include "Stack.hpp"
#include "ArrayQueue.hpp"
#include "ReversePolishNotation.hpp"
#include "TokenizerParser.hpp"

// Function Prototype
void palindrome();
void ConvertHexToDecimal();

void ConvertHexToDecimal()
{
    cout << "Enter a hex number to convert to decimal: ";
    string Hex;
    cin >> Hex;
    //drill parse through HEX and convert all letters to
    //upper case
    string copy = Hex;
    ArrayQueue Que;
    ItemType itm;
    
    for (size_t i = 0; i < Hex.length(); i++)
    {
        char ch = Hex[i];
        itm.Character = ch;
        //Enqueue itm
        if (!Que.isFull())
        {
            Que.enqueue(itm);
        }
        else
        {
            cout << "Queue is full. Exiting." << endl;
            exit(0);
        }
    }
    
    int Result = 0;
    
    for (size_t i = 0; i < Hex.length(); i++)
    {
        ItemType I;
        I = Que.dequeue();
        char ch = I.Character;
        int num = 0;
        
        if (ch<= '9')
        {
            // This snippet will convert character to its ASCII Value from 0 - 9
            num = static_cast<int>(ch) - 48;
        }
        else
        {
            // This snippet will convert character to its ASCII Value
            num = static_cast<int>(ch) - 55;
        }
        Result += num;
        
        if (i<Hex.length() -1)
        {
            Result *= 16;
        }
    }//loop
    cout << "Hex " << copy << " is " << Result << " on decimal scale." << endl;
}

void palindrome() {
    Stack Stk;
    ArrayQueue Que;
    string testStrings;
    int numString;
    
    // Prompt how many strings to be tested
    // strings meaning how many test cases
    cout << "\nHow many strings are to be tested?: " << flush;
    cin >> numString;
    cin.clear();
    cin.ignore();
    cin.sync();
    
    int counter = 1;
    do {
        // Prompt the user a series of test strings to be tested
        cout << "\nPlease enter a series of characters, pressing 'Enter/Return' after each one: " << endl;
        cout << ">> ";
        getline(cin, testStrings);
        
        int length;
        length = testStrings.size();
        
        for (size_t i = 0; i < length; i++)
        {
            ItemType itm;
            char ch;
            
            // if character is a letter in the current index then enqueue it otherwise not
            if (isalpha(testStrings[i]))
            {
                ch = testStrings[i];
                itm.Character = tolower(ch);
                // Enqueue Item to the Queue
                Que.enqueue(itm);
                // Push Item to the Stack
                Stk.push(itm);
            }
        }
        
        bool isPalindrome = true;
        while (isPalindrome && !Que.isEmpty() && !Stk.isEmpty())
        {
            ItemType I, S;
            I = Que.dequeue();
            S = Stk.top();
            char chQue = I.Character;
            char chStk = S.Character;
            
            // Compare each character if its similar or not
            if (chQue != chStk)
            {
                isPalindrome = false;
            }
            else
            {
                Stk.pop();
            }
        }
        
        // If it is a Palindrome output "Is a palindrome" otherwise "Is NOT a palindrome"
        if(!isPalindrome)
        {
            cout << endl;
            cout << "\t" << testStrings << endl;
            cout << "\t" << "** Is NOT a palindrome **" <<endl;
            // After checking if it's a palindrome or not empty the Queue and Stack for the next one
            while (!Que.isEmpty() && !Stk.isEmpty())
            {
                Que.dequeue();
                Stk.pop();
            }
        }
        else
        {
            cout << endl;
            cout << "\t" << testStrings << endl;
            cout << "\t" << "** Is a palindrome. **" << endl;
        }
        
        counter++;
    } while (counter <= numString);
}

int main() {
    bool done = false;
    while (!done) {
        ConvertHexToDecimal();
        cout << "More conversions? enter 0 to continue 1 to stop";
        cin >> done;
    }
    
    return 0;
}

int mainPalindrome() {
    // Declaration
    string testStrings, name, subject, section, semester, title;
    
    // Initialization of Variables
    title = "Palindrome Testing Program";
    name = " ";
    subject = "Computer Science 2";
    section = "Section 0140";
    semester = "Fall 2017";
    
    // Prompt user information
    cout << "Please enter your full name: " << flush;
    getline(cin, name);
    cout << endl;
    cout << "============== STUDENT INFO ==============" << endl;
    cout << "\tName: " << name << endl;
    cout << "\tSubject: " << subject << endl;
    cout << "\tSection: " << section << endl;
    cout << "\tSemester: " << semester << endl;
    cout << "\tTitle: " << title << endl;
    cout << "==========================================" << endl;
    
    palindrome();
    
    return 0;
}
