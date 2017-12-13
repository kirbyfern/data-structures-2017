//====================================================
//  main.cpp                                        //
//  Class: (Data Structures)                        //
//  Professor: Dr. Singhal                          //
//  Assignment#: 8                                  //
//  Operating Systems Used: MacOS(Xcode)            //
//  Last successful run: 11/13/17                   //
//  Created by Kirby James on 11/12/17.             //
//  Copyright © 2017 oc. All rights reserved.       //
//====================================================

#include "LetterFrequencyList.hpp"
using namespace std;

LetterFrequencyList buildLinkedList();
void printLinkedList(LetterFrequencyList LFL);

int main()
{
    {
        LetterFrequencyList LFL = buildLinkedList();
        printLinkedList(LFL);
        //Make a copy
        LetterFrequencyList LFLCopy = LFL; // Confirms use of assignment operator
        //print copy
        cout << "Printing the copy of linked list printed earlier.\n";
        printLinkedList(LFLCopy);
    }
    cin.get();
    return 0;
}

LetterFrequencyList buildLinkedList()
{
    ifstream in;
    string fileName;
    char letter;
    int frequency = 0;
    LetterFrequencyList LFL;
    
    cout << "Please enter input filename: ";
    getline(cin, fileName);
    
    in.open(fileName);
    if (in.is_open())
    {
        while (in.good())
        {
            in >> letter;
            // Check if it is a letter or not
            if (isalpha(letter)) {
                LFL.insertInOrder(toupper(letter));
            }
        }
    }
    in.close();
    return LFL;
}

void printLinkedList(LetterFrequencyList LFL)
{
    cout << LFL.toString() << endl;
}

