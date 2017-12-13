//
//  main.cpp
//  CS2ASS2FINAL
//
//  Created by Kirby James Fernandez on 9/18/17.
//  Dr. Singhal
//  Data Structures
//  Copyright © 2017 oc. All rights reserved.
//

#include "BankAccount.hpp"

BankAccount BA;

//function with default argument    
void print(ostream & out = cout) {
    out << "Account Number: " << BA.getAccountNumber() << endl;
    out << "Last Name: " << BA.getLastName() << endl;
    out << "First Name: " << BA.getFirstName() << endl;
    out << "Balance: " << BA.toString() << endl;
}

int main()
{
    int option;
    bool optionSelected = false;
    string iFileName, oFileName;
    ifstream in;
    ofstream out;
    
    double money;
    
    do {
        cout << "1. Create an account from keyboard data entry" << endl;
        cout << "2. Create an account from input file data entry" << endl;
        cout << "3. Print account balance to console." << endl;
        cout << "4. Withdraw money" << endl;
        cout << "5. Deposit money" << endl;
        cout << "6. Print account details to console" << endl;
        cout << "7. Print account details to an output file." << endl;
        cout << "8. Print full name of account holder to console only." << endl;
        cout << "9. Print account number only of the account holder to console." << endl;
        cout << "10. Exit." << endl;
        cout << ">> ";
        cin >> option;
        
        if (option == 1 || option == 2) {
            optionSelected = true;
        }
        
        if (!optionSelected) {
            cout << "Option 1 or 2 must be performed first." << endl;
        }
        else {
            switch (option) {
                case 1:
                    BankAccount::getInstance(BA);
                    break;
                case 2:
                    cout << "Please enter input filename: ";
                    cin >> iFileName;
                    
                    in.open(iFileName);
                    if (in.is_open()) {
                        BankAccount::getInstance(BA, in);
                    }
                    else {
                        cout << "Error reading file!" << endl;
                    }
                    break;
                case 3:
                    cout << "Balance: " << BA.toString() << endl;
                    
                    break;
                case 4:
                    cout << "Enter amount to be withdrawn: " << flush;
                    cin >> money;
                    
                    BA.withdraw(money);
                    break;
                case 5:
                    cout << "Enter amount to be deposited: " << flush;
                    cin >> money;
                    
                    BA.deposit(money);
                    break;
                case 6:
                    print();
                    break;
                case 7:
                    cout << "Please enter output file name: ";
                    cin >> oFileName;
                    out.open(oFileName.c_str());
                    
                    if (out) {
                        print(out);
                    }
                    out.close();
                    break;
                case 8:
                    cout << "Full Name: " << BA.getFullName() << endl;
                    break;
                case 9:
                    cout << "Account Number: " << BA.getAccountNumber() << endl;
                    break;;
                case 10:
                    exit(0);
                    break;
                default:
                    cout << "Invalid Input!" << endl;
                    break;
            }
        }
    } while (option != 10);
    return 0;
}

int main1()
{
    ifstream in;
    double money;
    
    money = 0;
    
    BA.getAccountNumber();
    BA.getLastName();
    BA.getFirstName();
    BA.toString();
    BankAccount::getInstance(BA);
    BankAccount::getInstance(BA, in);
    BA.toString();
    BA.withdraw(money);
    BA.deposit(money);
    
    return 0;
}

