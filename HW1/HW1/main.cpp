//============================================================================
// Name        : Data Structures
// Author      : Kirby James
// Professor   : Dr. Singhal
//============================================================================
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Emp {
    string	firstName, lastName, jobType;
    char classCode;
    int jobCode, empID, yearsService, eduCode;
    double basePay, salary;
};

int main()
{
    cout << fixed << showpoint << setprecision(2);
    Emp Emp1;
    double firstBase = 800.00,
    secondBase = 1000.00,
    thirdBase = 1500.00,
    noBase = 0.00;
    
    cout << "Please enter your first name: " << flush;
    getline(cin, Emp1.firstName);
    cout << "Please enter your last name: " << flush;
    cin >> Emp1.lastName;
    cout << "Please enter your current employee code ( S/O/M ): " << flush;
    cin >> Emp1.classCode;

    if (Emp1.classCode == 'S') {
        Emp1.basePay = firstBase;
        Emp1.jobType = "Factory Worker";
    } else if (Emp1.classCode == 'O') {
        Emp1.basePay = secondBase;
        Emp1.jobType = "Office Worker";
    } else if (Emp1.classCode == 'M') {
        Emp1.basePay = thirdBase;
        Emp1.jobType = "Management";
    } else if (Emp1.classCode != 'S' || Emp1.classCode != 'O' || Emp1.classCode != 'M') {
        Emp1.basePay = noBase;
        cout << Emp1.basePay << "Salary not calculated." << endl;
    }
    
    cout << "Please enter your current employee id number: " << flush;
    cin >> Emp1.empID;
    cout << "Please enter your current classification code ( 1/2/3 ): " << flush;
    cin >> Emp1.jobCode;
    
    if (Emp1.jobCode == 1) {
        Emp1.basePay = (Emp1.basePay * 0.05) + Emp1.basePay;
    } else if (Emp1.jobCode == 2) {
        Emp1.basePay = (Emp1.basePay * 0.1) + Emp1.basePay;
    } else if (Emp1.jobCode == 3) {
        Emp1.basePay = (Emp1.basePay * 0.2) + Emp1.basePay;
    }
    
    cout << "Please enter number of years in service: " << flush;
    cin >> Emp1.yearsService;
    
    if (Emp1.yearsService >= 0 || Emp1.yearsService <= 10) {
        Emp1.basePay = (Emp1.basePay * 0.05) + Emp1.basePay;
    } else if (Emp1.yearsService > 10 || Emp1.yearsService <= 50)  {
        Emp1.basePay = ((Emp1.basePay * 0.05)) + Emp1.basePay;
    }
    
    cout << "Please enter your current educational code ( 1/2/3/4 ): " << flush;
    cin >> Emp1.eduCode;
    if (Emp1.eduCode == 1) {
        Emp1.salary = ((Emp1.basePay * 0.0) + Emp1.basePay) - 4.5;
        
    } else if (Emp1.eduCode == 2) {
        Emp1.salary = ((Emp1.basePay * 0.05) + Emp1.basePay) - 4.5;
    } else if (Emp1.eduCode == 3) {
        Emp1.salary = ((Emp1.basePay * 0.12) + Emp1.basePay) - 4.5;
    } else if (Emp1.eduCode == 4) {
        Emp1.salary = ((Emp1.basePay * 0.20) + Emp1.basePay) - 4.5;
    }
    cout << endl;
    
    string full = Emp1.firstName + " " + Emp1.lastName;
    cout<<left;
    cout << setw(20)<<"Name" << setw(15)<< "ID#" <<setw(20)<< "Job Type" << setw(20)<<"Gross Salary($)" <<  endl;
    cout << setw(20)<< full << setw(15) << Emp1.empID << setw(20) << Emp1.jobType << setw(20) << Emp1.salary << endl;

    return 0;
}
