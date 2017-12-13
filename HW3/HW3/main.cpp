//
//  main.cpp
//  Class: (Data Structures)
//  Professor: Dr. Singhal
//  Assignment#: 3
//  Operating Systems Used: MacOS(Xcode)
//  Last successful run: 10/25/17
//  Created by Kirby James on 10/21/17.
//  Copyright © 2017 oc. All rights reserved.
//

#include "Fraction.hpp"
#include "FractionList.hpp"

// function prototype in main
void testIndexOperatorOverload(FractionList &FL);

// not sure on this
void testIndexOperatorOverload(FractionList &FL)
{
    size_t index;
    cout << "Enter index number of list to retrieve" << endl;
    cin >> index;
    if (index < FL.getNumberOfElements()) {
        cout << "It is working" << endl;
        cout << FL[index];
    } else {
        cout << "Out of bound array index";
    }
    system("pause");
}

void testCode9()
{
    Fraction F1(-8, -16);
    Fraction F2(6, -12);
    Fraction F3(9, -12);
    Fraction F4(5, 6);
    Fraction F5(-11, 17);
    FractionList FL;
    FL.addFraction(F1);
    FL.addFraction(F2);
    FL.addFraction(F3);
    FL.addFraction(F4);
    FL.addFraction(F5);
    cout << "The Fraction List is: " << endl << FL.toString() << endl;
    cout << "The largest fraction is: " << FL.getLargest() << endl;
    cout << "The very first    fraction in the array is: " << FL[0] << endl;
    cout << "The very last fraction in the array is: "
    << FL[FL.getNumberOfElements() - 1] << endl;
    cout << "The sum of all Fractions is: "
    << FL.getSumOfFractions() << endl;
    cout << boolalpha;
    cout << "It is " << FL.getSortState() << " that Fraction List is sorted."
    << endl;
    FL.sort();
    cout << "It is " << FL.getSortState() << " that Fraction List is sorted."
    << endl;
    FL.sort();
}

void testCode8()
{
    FractionList FL;
    cout << "Enter full path to file from which to read the fractions: ";
    cin.sync();//Use    ignore    on    Mac
    string inputFile;
    getline(cin, inputFile);
    ifstream in(inputFile);
    if (!in.is_open()){
        cout << "Failed to open input file. Exiting program." << endl;
        exit(0);
    }
    in >> FL;
    cout << "Enter full path to file to which to output the Fractions: ";
    cin.sync();//Use    ignore    on    Mac
    string outFile;
    getline(cin, outFile);
    ofstream out(outFile);
    if (!out.is_open()){
        cout << "Failed to create output file. Exiting program." << endl;
        exit(0);
    }
    cout << "The fraction list outputted to console:" << endl;
    cout << FL << endl;
    cout << "Now writing fraction list to an output    file." << endl;
    out << FL << endl;
    in.close();
    out.close();
}

void testCode7()
{
    Fraction F1(-8, -16);
    Fraction F2(6, -12);
    Fraction F3(9, -12);
    Fraction F4(5, 6);
    Fraction F5(-11, 17);
    FractionList FL;
    FL.addFraction(F1);
    FL.addFraction(F2);
    FL.addFraction(F3);
    FL.addFraction(F4);
    FL.addFraction(F5);
    cout << "The Fraction List is: " << endl << FL.toString() << endl;
    
    //Add    Source    code    of    previous    table    plus    below
    FL.sort();
    cout << "After ascending order sort, the FractionList is: " <<
    endl << FL.toString() << endl;
    cout << boolalpha;
    cout << "It is " << FL.isEmpty() << " that list is empty()" << endl;
    cout << "It is " << FL.isFull() << " that list is full()" << endl;
    cout << "The list has " << FL.getNumberOfElements()
    << " fractions." << endl;
}

void testCode6()
{
    Fraction F(-8, -16);
    cout << "Fraction is: " << F << endl;
    cout << "The numerator is: " << F.getTop() << endl;
    cout << "The denominator is: " << F.getBottom() << endl;
    cout << "The double    value is: " << F.toDouble() << endl;
}

void testCode5()
{
    Fraction F1(-8, -16);
    Fraction F2(6, -12);
    cout << "F1 = " << F1 << endl;
    cout << ++F1 << endl;
    cout << F1++ << endl;
    cout << F1 << endl;
    cout << "F2 = " << F2 << endl;
    cout << --F2 << endl;
    cout << F2-- << endl;
    cout << F2 << endl;
    
}

void testCode4()
{
    Fraction F1;
    Fraction F2;
    Fraction F3;
    cin >> F1 >> F3;//Tests    cascaded    input
    cout << F1 << endl << F3 << endl;//Tests    cascaded    output
    cout << "Enter full path to file from which to read the fraction: ";
    cin.sync();//Use    ignore    on    Mac
    string inputFile;
    getline(cin, inputFile);
    ifstream in(inputFile);
    
    if (!in.is_open()){
        cout << "Failed to open input file. Exiting program." << endl;
        exit(0);
    }
    in >> F2;//Tests    input    from    file
    cout << "Enter full path to file to    which to output the Fraction: ";
    cin.sync();//Use    ignore    on    Mac
    string outFile;
    getline(cin, outFile);
    ofstream out(outFile);
    if (!out.is_open()){
        cout << "Failed    to create output file. Exiting program." <<
        endl;
        exit(0);
    }
    cout << "The fraction read from file is: " << F2 << endl;
    cout << "Now wrting to file." << endl;
    out << F2;//Tests    output    to    file
    in.close();
    out.close();
}

void testCode3()
{
    Fraction F1(1, 3);
    Fraction F2(2, 6);
    Fraction F3(5, 5);
    cout << boolalpha;
    cout << "F1 = " << F1.toString() << endl;
    cout << "F2 = " << F2.toString() << endl;
    cout << "F3 = " << F3.toString() << endl;
    cout << "F1 == F2 is : " << (F1 == F2) << endl;
    cout << "F1 != F2 is : " << (F1 != F2) << endl;
    cout << "F1 != F3 is : " << (F1 != F3) << endl;
    cout << "F1 == F3 is : " << (F1 == F3) << endl;
    cout << "F3 == 1 is : " << (F3 == 1) << endl;
    cout << "1 == F3 is : " << (1 == F3) << endl;
    cout << "F3 == 2 is : " << (F3 == 2) << endl;
    cout << "2 == F3 is : " << (2 == F3) << endl;
    cout << "F1 == F1 is : " << (F1 == F1) << endl;
    cout << "(F1+1) == (1+F1) is : " << ((F1 + 1) == (1 + F1)) << endl;
    cout << "(F1*F2) == (F1*F2) is : " << ((F1*F2) == (F1*F2)) << endl;
    cout << "(F1/F2) == (F1/F2) is : " << ((F1 / F2) == (F1 / F2)) << endl;
    cout << "(F1-F2) == (F1-F2) is : " << ((F1 - F2) == (F1 - F2)) << endl;
    cout << "(F1+1) == (F1+2) is : " << ((F1 + 1) == (F1 + 2)) << endl;
    cout << "(F1*F2) == (F1*F3) is : " << ((F1*F2) == (F1*F3)) << endl;
    cout << "(F1/F2) == (F1/F3) is : " << ((F1 / F2) == (F1 / F3)) << endl;
    cout << "(F1-F2) == (F1-F3) is : " << ((F1 - F2) == (F1 - F3)) << endl;
}

void testCode2() {
    Fraction F2(6, -12);
    Fraction F3(-9, 12);
    cout << "F2 = " << F2.toString() << endl;
    cout << "F3 = " << F3.toString() << endl;
    cout << "F2 + F3 = " << (F2 + F3).toString() << endl;
    cout << "F2 - F3 = " << (F2 - F3).toString() << endl;
    cout << "F2 * F3 = " << (F2 * F3).toString() << endl;
    cout << "F2 / F3 = " << (F2 / F3).toString() << endl;
    cout << "F2 + 2 = " << (F2 + 2).toString() << endl;
    cout << "2 + F2 = " << (2 + F2).toString() << endl;
    cout << "F2 - 2 = " << (F2 - 2).toString() << endl;
    cout << "2 - F2 = " << (2 - F2).toString() << endl;
    cout << "F2 * 2 = " << (F2 * 2).toString() << endl;
    cout << "2 * F2 = " << (2 * F2).toString() << endl;
    cout << "F2 / 2 = " << (F2 / 2).toString() << endl;
    cout << "2 / F2 = " << (2 / F2).toString() << endl;
}

void testCode1()
{
    Fraction F1(9, 0);
    Fraction F2(-6, -12);
    cout << F2.toString() << endl;
    Fraction F3(9, -12);
    cout << F3.toString() << endl;
    Fraction F4(8, 16);
    cout << F4.toString() << endl;
    Fraction F5(5, 16);
    cout << F5.toString() << endl;
    Fraction F6(-5);
    cout << F6.toString() << endl;
    Fraction F7(5, -1);
    cout << F7.toString() << endl;
}

int main()
{
    //testCode1();
    //testCode2();
    //testCode3();
    //testCode4();
    //testCode5();
    //testCode6();
    //testCode7();
    //testCode8();
    //testCode9();
    
    int option;
    FractionList FL;
    Fraction F;
    string inputFile;
    ifstream in;
    string outFile;
    ofstream out;
    
    // For Case 7 - 9
    Fraction F1;
    Fraction F2;
    
    do {
        cout << "Main Menu:" << endl;
        cout << "1. Create Fraction List from input file data entry." << endl;
        cout << "2. Create Fraction List from keyboard data entry." << endl;
        cout << "3. Print the Fraction List to console using operator >> and toString both." << endl;
        cout << "4. Print the Fraction List to output file using operator >> and toString both." << endl;
        cout << "5. Sort FractionList to console only using operator >> only." << endl;
        cout << "6. Print sum of all Fractions in the list, the largest fraction in the list, sort state(sorted or not) to console only." << endl;
        cout << "7. Demonstrate Arithmetical Operations." << endl;
        /*[Asks user to enter two fractions from keyboard, and demonstrateproper    functioning    of    *, / , -, and + operators.Also    shows    that following    operations
         also    work :
         2 + Fraction
         Fraction + 2
         2 - Fraction
         Fraction    ñ 2
         2 * Fraction
         Fraction * 2
         2 / Fraction
         Fraction / 2
         ]*/
        cout << "8. Demonstrate pre and post fix increment and decrement operators." << endl;
        /*[This    menu    asks    user    to
         enter    two    fractions    from    keyboard.Output    shows    the    successful    completions    of    ++F, F++, --F1,
         and    F1óoperations    where    F    and    F1    are    user    entered    Fractions.*/
        cout << "9. Demonstrates the operation of overloaded operator []." << endl;
        /*[Menu    asks    user    the    index    at    which
         Fraction    of    interest    may    be    in    the    array.If    index    is    in - bound, it    is    outputted    to    console.
         Otherwise    a    message    from    exception    handler    is    displayed].*/
        cout << "10. Exit." << endl;
        cout << ">> ";
        cin >> option;
        
        switch (option)
        {
            case 1:
                cout << "Enter full path to file from which to read the fractions: ";
                cin.clear();
                cin.ignore(10, '\n');
                cin.sync();
                getline(cin, inputFile);
                in.open(inputFile);
                if (!in.is_open()){
                    cout << "Failed to open input file. Exiting program." << endl;
                    exit(0);
                }
                in >> FL;
                in.close();
                break;
            case 2:
                cin >> FL;
                break;
            case 3:
                cout << FL;
                break;
            case 4:
                cout << "Enter full path to file to which to output the Fraction: ";
                cin.clear();
                cin.ignore(10, '\n');
                cin.sync();
                getline(cin, outFile);
                out.open(outFile);
                if (!out.is_open()){
                    cout << "Failed    to create output file. Exiting program." <<
                    endl;
                    exit(0);
                }
                cout << "Now wrting to file." << endl;
                out << FL;
                out.close();
                break;
            case 5:
                FL.sort();
                cout << "After ascending order sort, the FractionList is: " <<
                endl << FL.toString() << endl;
                break;
            case 6:
                cout << "The sum of all Fractions is: "
                << FL.getSumOfFractions() << endl;
                cout << "The largest fraction is: " << FL.getLargest() << endl;
                cout << boolalpha;
                cout << "It is " << FL.getSortState() << " that Fraction List is sorted."
                << endl;
                break;
            case 7:
                // I am not sure what to do here sir so I hardcoded it
                cin >> F1 >> F2;
                cout << "F1 = " << F1.toString() << endl;
                cout << "F2 = " << F2.toString() << endl;
                cout << "F1 + F2 = " << (F1 + F2).toString() << endl;
                cout << "F1 - F2 = " << (F1 - F2).toString() << endl;
                cout << "F1 * F2 = " << (F1 * F2).toString() << endl;
                cout << "F1 / F2 = " << (F2 / F2).toString() << endl;
                cout << "F1 + 2 = " << (F2 + 2).toString() << endl;
                cout << "2 + F2 = " << (2 + F2).toString() << endl;
                cout << "F1 - 2 = " << (F2 - 2).toString() << endl;
                cout << "2 - F2 = " << (2 - F2).toString() << endl;
                cout << "F1 * 2 = " << (F2 * 2).toString() << endl;
                cout << "2 * F2 = " << (2 * F2).toString() << endl;
                cout << "F1 / 2 = " << (F2 / 2).toString() << endl;
                cout << "2 / F2 = " << (2 / F2).toString() << endl;
                break;
            case 8:
                // I do not know what to do here sir so I hardcoded this part
                cin >> F1 >> F2;
                cout << "F1 = " << F1 << endl;
                cout << ++F1 << endl;
                cout << F1++ << endl;
                cout << F1 << endl;
                cout << "F2 = " << F2 << endl;
                cout << --F2 << endl;
                cout << F2-- << endl;
                cout << F2 << endl;
                break;
            case 9:
                testIndexOperatorOverload(FL);
                break;
            case 10:
                cout << "Thank you have a nice day!" << endl;
                exit(0);
                break;
            default:
                cout << "Invalid input.";
                break;
        }
        
    } while (option != 10);
    return 0;
}

