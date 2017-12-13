//
//  Fraction.hpp
//  Class: (Data Structures)
//  Professor: Dr. Singhal
//  Assignment#: 3
//  Operating Systems Used: MacOS(Xcode)
//  Last successful run: 9/25/17
//  Created by Kirby James on 9/25/17.
//  Copyright © 2017 oc. All rights reserved.
//

#include "FractionList.hpp"

FractionList::FractionList() :isSorted(false), num_elements(0)
{ }

// add fraction and check if it is full or not
void FractionList::addFraction(const Fraction& F) {
    if (isFull()) {
        cout << "List is already full." << endl;
    }
    else {
        List[num_elements] = F;
        num_elements++;
        isSorted = false;
    }
}

// Accessors
void FractionList::getInstance(FractionList& FL) {
    Fraction temp;
    FL.addFraction(temp);
}

const Fraction FractionList::getLargest() {
    double largest = 0.0;
    Fraction F;
    for (int x = 0; x < num_elements; x++)
    {
        if (List[x].toDouble() >= largest) {
            largest = List[x].toDouble();
            F = List[x];
        }
    }
    return F;
}

size_t FractionList::getNumberOfElements() {
    return num_elements;
}

const Fraction FractionList::getSmallest() {
    double smallest = 0.0;
    Fraction F;
    
    for (int x = 0; x < num_elements; x++)
    {
        if (List[x].toDouble() <= smallest) {
            smallest = List[x].toDouble();
            F = List[x];
        }
    }
    return F;
}

bool FractionList::getSortState(){
    if (isSorted == true) {
        return true;
    }
    else {
        return false;
    }
}

const Fraction FractionList::getSumOfFractions() {
    Fraction sum = List[0];
    for (size_t x = 1; x < num_elements; x++)
    {
        sum = sum + List[x];
    }
    return sum;
}

// Check if it is empty or not
bool FractionList::isEmpty() {
    if (num_elements == 0) {
        return true;
    }
    else {
        return false;
    }
}

// Check if it is full or not
bool FractionList::isFull() {
    if (num_elements == MAX) {
        return true;
    }
    else {
        return false;
    }
}

const Fraction& FractionList::operator[](size_t index) {
    if (index < num_elements)
    {
        return List[index];
    }
    else {
        cout << "Out of bound array index.";
        // If i did not add return NULL Xcode gives an error message
        // Returning reference to local temporary object
        return NULL;
    }
}

// sort in ascending
void FractionList::sort() {
    for (size_t x = 0; x < num_elements; x++)
    {
        for (size_t y = 0; y < num_elements - x - 1; y++)
        {
            if (List[y].toDouble() > List[y + 1].toDouble())
            {
                Fraction temp;
                temp = List[y];
                List[y] = List[y + 1];
                List[y + 1] = temp;
            }
        }
    }
    isSorted = true;
}

// to string
const string FractionList::toString() {
    string fractions = "";
    
    for (size_t x = 0; x < num_elements; x++)
    {
        fractions += List[x].toString() + "\n";
    }
    
    return fractions;
}

ostream& operator <<(ostream & out, const FractionList & FL) {
    for (size_t x = 0; x < FL.num_elements; x++)
    {
        out << FL.List[x].toString() + "\n";
    }
    
    return out;
}

istream& operator >>(istream & in, FractionList & FL) {
    if (&in == &cin)
    {
        bool done = false;
        
        while (!done && FL.num_elements < FractionList::MAX)
        {
            Fraction temp;
            cin >> temp;
            FL.addFraction(temp);
            cout << "More data? Enter 0 to continue or 1 to stop: ";
            cin >> done;
        }
    }
    else
    {
        while (in.peek() != EOF && FL.num_elements < FractionList::MAX)
        {
            Fraction temp;
            in >> temp;
            FL.addFraction(temp);
        }
    }
    
    return in;
}

