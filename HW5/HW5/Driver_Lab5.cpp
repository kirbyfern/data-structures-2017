//
//  main.cpp
//  Class: (Data Structures)
//  Professor: Dr. Singhal
//  Assignment#: 5
//  Operating Systems Used: MacOS(Xcode)
//  Last successful run: 10/25/17
//  Created by Kirby James on 10/21/17.
//  Copyright © 2017 oc. All rights reserved.
//

#include "Stack.hpp"
#include "TokenizerParser.hpp"
#include "ReversePolishNotation.hpp"
#include "PostFixEval.hpp"

//// Function Prototype
//
//// Decimal Binary
//void convertDecimalToHexUsingStack();
//void convertDecimalToBinaryUsingStack();
//void convertBinaryToDecimalUsingStack();
//
//// Octal
//void convertBinaryToOctalUsingStack();
//
//void convertBinaryToOctalUsingStack()
//{
//    long Bin;
//    cout << "Enter a series of binaries(0's and 1's) to convert to octal: ";
//    cin >> Bin;
//    long copy = Bin;
//    Stack Stk;
//    ItemType itm;
//
//    int Result = 0;
//    long rem, dec = 0, quot = 0, base = 1;
//    while (Bin != 0) {
//        rem = Bin % 10;
//        dec = rem * base;
//        if (!Stk.isFull()) {
//            itm.Long = dec;
//            Stk.push(itm);
//        }
//        else
//        {
//            cout << "Stack is full." << endl;
//            return;
//        }
//        base = base * 2;
//        Bin = Bin / 10;
//    }
//
//    while (!Stk.isEmpty()) {
//        Result += Stk.top().Long;
//        Stk.pop();
//    }
//    cout << "Binary " << copy << " is " << Result << " on decimal form." << endl;
//}
//
//void ConvertBinaryToDecimalUsingStack()
//{
//    long Bin;
//    cout << "Enter a series of binaries(0's and 1's) to convert to decimal: ";
//    cin >> Bin;
//    long copy = Bin;
//    Stack Stk;
//    ItemType itm;
//
//    int Result = 0;
//    long rem, dec = 0, base = 1;
//    while (Bin != 0) {
//        rem = Bin % 10;
//        dec = rem * base;
//        if (!Stk.isFull()) {
//            itm.Long = dec;
//            Stk.push(itm);
//        }
//        else
//        {
//            cout << "Stack is full." << endl;
//            return;
//        }
//        base = base * 2;
//        Bin = Bin / 10;
//    }
//
//    while (!Stk.isEmpty()) {
//        Result += Stk.top().Long;
//        Stk.pop();
//    }
//    cout << "Binary " << copy << " is " << Result << " on decimal form." << endl;
//}
//
//void convertDecimalToBinaryUsingStack()
//{
//    cout << "Enter decimal numbers to convert to binary: ";
//    int DecNum;
//    cin >> DecNum;
//    if (DecNum < 0)
//    {
//        cout << DecNum << " is not a positive integer." << endl;
//    }
//    else
//    {
//        int copy = DecNum;
//        Stack stk;
//        ItemType itm;
//
//        while (DecNum != 0)
//        {
//            int mod = DecNum % 2;
//            itm.uint = mod;
//
//            if (!stk.isFull())
//            {
//                stk.push(itm);
//            }
//            else
//            {
//                cout << "Stack is full." << endl;
//                return;
//            }
//
//            DecNum = DecNum / 2;
//        }//end of first while loop
//
//        cout << "The binary form of " << copy << " is: ";
//
//        while (!stk.isEmpty())
//        {
//            int temp = stk.top().uint;
//            stk.pop();
//
//            cout << temp;
//        }
//        cout << endl;
//    }//end of else
//}//end of function
//
//void convertDecimalToHexUsingStack()
//{
//    cout << "Enter decimal numbers to convert to HEX: ";
//    long DecNum;
//    cin >> DecNum;
//    if (DecNum<10)
//    {
//        cout << "The hexadecimal of " << DecNum << " is " << DecNum << endl;
//    }
//    else
//    {
//        long copy = DecNum;
//        Stack stk;
//        ItemType itm;
//
//        while (DecNum != 0)
//        {
//            long mod = DecNum % 16;
//            itm.Long = mod;
//
//            if (!stk.isFull())
//            {
//                stk.push(itm);
//            }
//            else
//            {
//                cout << "Stack is full." << endl;
//                return;
//            }
//
//            DecNum = DecNum / 16;
//        }//end of first while loop
//
//        cout << "The hex form of " << copy << " is: ";
//
//        while (!stk.isEmpty())
//        {
//            long temp = stk.top().Long;
//            stk.pop();
//
//            if (temp<10)
//            {
//                cout << temp;
//            }
//            else
//            {
//                cout << (static_cast<char>(temp + 55));
//            }
//        }
//        cout << endl;
//    }//end of else
//}//end of function

//int main() {
//    bool done = false;
//
//    while (!done)
//    {
////        convertDecimalToHexUsingStack();
////        convertDecimalToBinaryUsingStack();
//        ConvertBinaryToDecimalUsingStack();
//        cout << "More conversions? Enter 0 to continue or 1 to stop: ";
//        cin >> done;
//    }
//    system("pause");
//    return 0;
//    /*
//     Output
//     The hex form of 57005 is: DEAD
//     More conversions? Enter 0 to continue or 1 to stop: 0
//     Enter decimal number to convert to HEX: 48879
//     The hex form of 48879 is: BEEF
//     More conversions? Enter 0 to continue or 1 to stop: 0
//     Enter decimal number to convert to HEX: 4078
//     The hex form of 4078 is: FEE
//     More conversions? Enter 0 to continue or 1 to stop: 0
//     Enter decimal number to convert to HEX: 48813
//     The hex form of 48813 is: BEAD
//     More conversions? Enter 0 to continue or 1 to stop: 0
//     Enter decimal number to convert to HEX: 9
//     The hexadecimal of 9 is 9
//     More conversions? Enter 0 to continue or 1 to stop: 0
//     Enter decimal number to convert to HEX: 8
//     The hexadecimal of 8 is 8
//     More conversions? Enter 0 to continue or 1 to stop: 0
//     Enter decimal number to convert to HEX: 88
//     The hex form of 88 is: 58
//     More conversions? Enter 0 to continue or 1 to stop: 0
//     Enter decimal number to convert to HEX: 0
//     The hexadecimal of 0 is 0
//     More conversions? Enter 0 to continue or 1 to stop: 0
//     Enter decimal number to convert to HEX: 123
//     The hex form of 123 is: 7B
//     More conversions? Enter 0 to continue or 1 to stop:
//     */
//}

int main() {
    ofstream fout;
    ifstream fin;
    string oFileName;
    string exp;
    bool done;
    char choice;
    
    done = false;
    
    cout << "Please input the name of the output file: " << endl;
    getline(cin, oFileName);
    cout << endl << "The file name entered is: " << endl;
    cout << oFileName << endl << endl;
    fout.open(oFileName);
    if (!fout.is_open()){
        cout << "Failed to open file. Exiting program." << endl;
        exit(0);
    }
    
    do {
        cout << "Please enter the infix expression, which must be parenthetically balanced and" << endl;
        cout << "must be enclosed in square brackets.The parsing algorithm only works if more" << endl;
        cout << "than one space is left between the characters in the inputted expression." << endl;
        cout << "The evaluated value for a numeric expression will only be a floating point value." << endl;
        cout << "(After inputting an infix expression press enter twice)" << endl;
        cout << ">> " << flush;
        getline(cin, exp);
        cin.clear();
        cin.ignore();
        cin.sync();
        
        PostFixEval P1(exp);
        
        int option;
        cout << "Main Menu:" << endl;
        cout << "Press 1 to print the results to both screen and data file" << endl;
        cout << "Press 2 to print the results to data file only:" << endl;
        cout << "Press 3 to print the results to screen only:" << endl;
        cout << ">> " << flush;
        cin >> option;
        cin.clear();
        cin.ignore();
        cin.sync();
        
        switch (option)
        {
            case 1:
                P1.print(fout);
                P1.print(cout);
                break;
                
            case 2:
                P1.print(fout);
                break;
                
            case 3:
                P1.print(cout);
                break;
                
            default:
                cout << "Invalid Input";
                break;
        }
        
        cout << "More data? Enter y to continue or n to stop: " << flush;
        cin >> choice;
        cin.ignore();
        cout << endl;
        if (tolower(choice) == 'n') {
            exit(0);
        }
        else {
            while (tolower(choice) != 'y' && tolower(choice) != 'n') {
                cout << "More data? Enter y to continue or n to stop: " << flush;
                cin >> choice;
                cin.ignore();
                cout << endl;
            }
        }
    } while (!done);
    
    cin.get();
    return 0;
}

