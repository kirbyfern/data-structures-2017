#include "BankAccountList.hpp"
#include "BankAccount.hpp"

int main() {
    int option;
    bool optionSelected = false;
    BankAccountList BAL;
    BankAccount BA;
    
    ifstream in;
    ofstream out;
    string iFileName, oFileName;
    
    string actNum;
    double money = 0;
    
    
    do {
        cout << "[1] Add new accounts using keyboard." << endl;
        cout << "[2] Add new accounts using a data file(Limit = 30 accounts)." << endl;
        cout << "[3] Update an account." << endl;
        cout << "[4] Close/delete an account." << endl;
        cout << "[5] Write current account list to an output file in append mode." << endl;
        cout << "[6] Print current account list to console." << endl;
        cout << "[7] Withdraw Money from an account." << endl;
        cout << "[8] Make Deposit to an account." << endl;
        cout << "[9] Balance inquiry." << endl;
        cout << "[10] Search account and show details(console only)." << endl;
        cout << "[11] Print current list description to console only." << endl;
        cout << "[12] Print list sorted by account number to console." << endl;
        cout << "[13] Print list sorted by last name to console." << endl;
        cout << "[14] Print list sorted by balance to console." << endl;
        cout << "[15] Print statistics to console." << endl;
        cout << "[16] Print report in table form to a report file." << endl;
        cout << "[17] Print list to an output file readable as new input file." << endl;
        cout << "[18] Exit." << endl;
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
                    BAL.getInstance(BAL);
                    break;
                case 2:
                    cout << "Please enter input filename: ";
                    cin >> iFileName;
                    
                    in.open(iFileName);
                    if (in.is_open()) {
                        BAL.getInstance(BAL, in);
                    }
                    break;
                case 3:
                    BAL.updateAccount();
                    break;
                case 4:
                    cout << "Enter Bank Account Number: ";
                    cin >> actNum;
                    BAL.deleteAccount(actNum);
                    break;
                case 5:
                    cout << "Please enter output file name: ";
                    cin >> oFileName;
                    out.open(oFileName.c_str());
                    
                    if (out) {
                        BAL.print(out);
                    }
                    out.close();
                    break;
                case 6:
                    BAL.print(cout);
                    break;
                case 7:
                    cout << "Enter Bank Account Number: ";
                    cin >> actNum;
                    BAL.withDrawMoney(actNum, money);
                    break;
                case 8:
                    cout << "Enter Bank Account Number: ";
                    cin >> actNum;
                    BAL.depositMoney(actNum, money);
                    break;
                case 9:
                    cout << "Enter Bank Account Number: ";
                    cin >> actNum;
                    BAL.getBalance(actNum);
                    break;
                case 10:
                    cout << "Enter Bank Account Number: ";
                    cin >> actNum;
                    cout << "FullName: " << BAL.getFullName(actNum) << endl;
                    BAL.getBalance(actNum);
                    break;
                case 11:
                    cout << BAL.listDescription() << endl;
                    break;
                case 12:
                    BAL.sort(1);
                    break;
                case 13:
                    BAL.sort(2);
                    break;
                case 14:
                    BAL.sort(3);
                    break;
                case 15:
                    BAL.printStatistics(cout);
                    break;
                case 16:
                    BAL.printListAsReport();
                    break;
                case 17:
                    cout << "Please enter output filename for new input file: ";
                    cin >> oFileName;
                    
                    out.open(oFileName);
                    if (out.is_open()) {
                        BAL.writeToNewInputFile(out);
                    }
                    out.close();
                    break;
                case 18:
                    exit(0);
                    break;
                default:
                    cout << "Invalid input!";
                    break;
            }
        }
    } while (option != 18);
    return 0;
}

