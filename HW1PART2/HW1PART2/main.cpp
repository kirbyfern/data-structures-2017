//============================================================================
// Name        : Data Structures
// Author      : Kirby James Fernandez
// Professor   : Dr. Singhal
//============================================================================

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#define MAX 30
using namespace std;

struct Emp {
    string fName[MAX], lName[MAX], jobType[MAX];
    int jobCode[MAX], empID[MAX], yearsService[MAX], eduCode[MAX];
    int empCount;
    double salary[MAX];
};

bool checkEmptyFile(fstream &fin);
void readFile(fstream &fin, string &iFileName);
bool validateEmployeeId(int employeeId);
void programMenu(Emp &Employee);
void searchMenu(Emp &Employee);
void searchByEmployeeId(Emp &Employee);
void searchByLastName(Emp &Employee);
void saveAndExit(Emp &Employee);
void displayAndExit(Emp &Employee);
double calculateGross(int empCount, Emp &Employee);
void sortEmployee(Emp &Employee);
void sorting(Emp &Employee, int j);
void bubbleSort(Emp &Employee, char option);

int main()
{
    string iFileName;
    fstream fin;
    
    cout << "Please enter input file name: ";
    cin >> iFileName;
    cout << endl;
    
    fin.open(iFileName);
    
    if (fin.fail()) {
        while (fin.fail()) {
            cerr << "Error reading the file" << endl;
            cout << "Please enter input file name: ";
            getline(cin, iFileName);
            cout << endl;
            
            fin.open(iFileName.c_str());
        }
    }
    
    //Professor Added This Part
    if (fin.is_open()) {
        readFile(fin, iFileName);
    }
    else {
        cout << "Failed to open input file." << endl;
    }
    //Professor Added This Part
    
    if (fin && !checkEmptyFile) {
        readFile(fin, iFileName);
    }
    else if (checkEmptyFile(fin)) {
        cout << "File is empty!" << endl;
        exit(0);
    }
    else if (!fin.eof()) {
        cout << "Error reading the file" << endl;
        exit(0);
    }
    else {
        cout << "Couldn't read the file" << endl;
        exit(0);
    }
    
    return 0;
    
}

//Using this omits an error
bool checkEmptyFile(fstream &fin)
{
    return fin.peek() == std::ifstream::traits_type::eof();
}

void readFile(fstream &fin, string &iFileName) {
    Emp Employee;
    int counter = 0;
    
    while (fin.good()) {
        string tempFName, tempLName;
        char tempEmployeeCode;
        int tempEmployeeId, tempJobClass, tempYears, tempEducCode;
        fin >> tempFName;
        fin >> tempLName;
        fin >> tempEmployeeCode;
        fin >> tempEmployeeId;
        fin >> tempJobClass;
        fin >> tempYears;
        fin >> tempEducCode;
        
        fin.ignore();
        
        Employee.fName[counter] = tempFName;
        Employee.lName[counter] = tempLName;
        
        if (islower(tempEmployeeCode)) {
            Employee.jobType[counter] = "Invalid Employee Code";
        }
        else {
            if (tempEmployeeCode == 'S') {
                Employee.jobType[counter] = "Factory Worker";
            }
            else if (tempEmployeeCode == 'O') {
                Employee.jobType[counter] = "Office Worker";
            }
            else if (tempEmployeeCode == 'M') {
                Employee.jobType[counter] = "Management";
            }
        }
        
        if (!validateEmployeeId(tempEmployeeId)) {
            Employee.empID[counter] = -1;
        }
        else {
            Employee.empID[counter] = tempEmployeeId;
        }
        
        if (tempYears < 1 || tempYears > 50) {
            Employee.yearsService[counter] = -1;
        }
        else {
            Employee.yearsService[counter] = tempYears;
        }
        
        if (tempJobClass < 1 || tempJobClass > 3) {
            Employee.jobCode[counter] = -1;
        }
        else {
            Employee.jobCode[counter] = tempJobClass;
        }
        
        if (tempEducCode < 1 || tempEducCode > 4) {
            Employee.eduCode[counter] = -1;
        }
        else {
            Employee.eduCode[counter] = tempEducCode;
        }
        
        Employee.salary[counter] = calculateGross(counter, Employee);
        //maximum index reached, exit program
        if (counter > 30) {
            cout << "Number of records execeeded the program capacity. Only 30 records will be processed." << endl;
            exit(0);
        }
        counter++;
    }
    // close the file
    
    Employee.empCount = counter;
    programMenu(Employee);
}

bool validateEmployeeId(int employeeId) {
    bool valid = false;
    int counter = 0;
    
    while (employeeId) {
        employeeId = employeeId / 10;
        counter++;
    }
    
    if (counter == 4) {
        valid = true;
    }
    
    return valid;
}

void programMenu(Emp &Employee) {
    char option;
    char sort;
    
    cout << endl << "Menu:" << endl;
    cout << "'S' -- Search Employee." << endl;
    cout << "'F' -- Save data to file and Exit the Program." << endl;
    cout << "'D' -- Display data and Exit the Program." << endl;
    
    cout << "Choose a letter from the menu: " << flush;
    cin >> option;
    cout << endl;
    
    switch (option)
    {
        case 'S':
            searchMenu(Employee);
            break;
        case 'F':
            cout << "Sort Employee? [Y/N]: ";
            cin >> sort;
            if (sort == 'Y') {
                sortEmployee(Employee);
                saveAndExit(Employee);
            }
            else {
                saveAndExit(Employee);
            }
            break;
        case 'D':
            cout << "Sort Employee? [Y/N]: ";
            cin >> sort;
            if (sort == 'Y') {
                sortEmployee(Employee);
                displayAndExit(Employee);
            }
            else {
                displayAndExit(Employee);
            }
            break;
        default:
            cout << "Please choose a letter from the menu." << endl;
            break;
    }
}

void searchMenu(Emp &Employee) {
    char option;
    cout << endl << "SEARCH EMPLOYEE:" << endl;
    cout << "'I' -- By Employee ID." << endl;
    cout << "'L' -- By Last Name." << endl;
    cout << "'G' -- Go Back to Main Menu." << endl;
    
    cout << "Choose a letter from the menu: " << flush;
    cin >> option;
    cout << endl;
    
    switch (option)
    {
        case 'I':
            searchByEmployeeId(Employee);
            break;
        case 'L':
            searchByLastName(Employee);
            break;
        case 'G':
            programMenu(Employee);
            break;
        default:
            cout << "Please choose a letter from the menu." << endl;
            break;
    }
}

void searchByEmployeeId(Emp &Employee) {
    int empId, empIndex;
    bool existing = false;
    
    cout << "SEARCH BY LAST NAME" << endl;
    cout << "Please enter Employee's ID #: ";
    cin >> empId;
    
    for (int x = 0; x < Employee.empCount; x++) {
        if (empId == Employee.empID[x]) {
            existing = true;
            empIndex = x;
            break;
        }
    }
    
    if (existing) {
        cout << "Employee ID:\t" << Employee.empID[empIndex] << endl;
        cout << "Name:\t" << Employee.fName[empIndex] + ' ' + Employee.lName[empIndex] << endl;
        cout << "Job Type:\t" << Employee.jobType[empIndex] << endl;
        cout << "Years of Service:\t" << Employee.yearsService[empIndex] << endl;
    }
    else {
        cout << "Employee's ID # doesn't exist!" << endl;
    }
    searchMenu(Employee);
}

void searchByLastName(Emp &Employee) {
    string lastName;
    int empIndex;
    bool existing = false;
    
    cout << "SEARCH BY LAST NAME" << endl;
    cout << "Please enter Employee's Last Name: ";
    cin >> lastName;
    
    for (int x = 0; x < Employee.empCount; x++) {
        if (lastName == Employee.lName[x]) {
            existing = true;
            empIndex = x;
            break;
        }
    }
    
    if (existing) {
        cout << "Employee ID:\t" << Employee.empID[empIndex] << endl;
        cout << "Name:\t" << Employee.fName[empIndex] + ' ' + Employee.lName[empIndex] << endl;
        cout << "Job Type:\t" << Employee.jobType[empIndex] << endl;
        cout << "Years of Service:\t" << Employee.yearsService[empIndex] << endl;
    }
    else {
        cout << "Employee's Last Name doesn't exist!";
    }
    searchMenu(Employee);
}

void saveAndExit(Emp &Employee) {
    ofstream fout;
    string oFileName;
    
    cout << "Please enter output file name: ";
    cin >> oFileName;
    fout.open(oFileName.c_str());
    
    if (fout) {
        fout << left << setprecision(2) << fixed;
        fout << setw(20) << "Name" << setw(20) << "ID#" << setw(20) << "Job Type" << setw(20) << "Gross Salary" << endl;
        
        for (int x = 0; x < Employee.empCount; x++) {
            fout << left << setprecision(2) << fixed;
            if (Employee.empID[x] != -1 && Employee.yearsService[x] != -1 && Employee.jobCode[x] != -1 && Employee.eduCode[x] != -1) {
                fout << setw(20) << Employee.fName[x] + ' ' + Employee.lName[x] << setw(20) << Employee.empID[x] << setw(20) << Employee.jobType[x] << "$" << Employee.salary[x] << endl;
            }
            else {
                fout << setw(20) << Employee.fName[x] + ' ' + Employee.lName[x] << setw(20) << "Gross Salary could not be calculated due to bad data" << endl;
            }
        }
        
        fout.close();
    }
}

void displayAndExit(Emp &Employee) {
    
    cout << left << setprecision(2) << fixed;
    cout << setw(20) << "Name" << setw(20) << "ID#" << setw(20) << "Job Type" << setw(20) << "Gross Salary" << endl;
    
    for (int x = 0; x < Employee.empCount; x++) {
        cout << left << setprecision(2) << fixed;
        if (Employee.empID[x] != -1 && Employee.yearsService[x] != -1 && Employee.jobCode[x] != -1 && Employee.eduCode[x] != -1) {
            cout << setw(20) << Employee.fName[x] + ' ' + Employee.lName[x] << setw(20) << Employee.empID[x] << setw(20) << Employee.jobType[x] << "$" << Employee.salary[x] << endl;
        }
        else {
            cout << setw(20) << Employee.fName[x] + ' ' + Employee.lName[x] << setw(20) << "Gross Salary could not be calculated due to bad data" << endl;
        }
    }
}

double calculateGross(int empCount, Emp &Employee) {
    double salary = 0;
    int basePay = 0;
    // Job Code
    
    if (Employee.jobCode[empCount] == 1) {
        basePay = 800;
        salary = basePay + (basePay * 0.05);
    }
    if (Employee.jobCode[empCount] == 2) {
        basePay = 1000;
        salary = basePay + (basePay * 0.1);
    }
    else if (Employee.jobCode[empCount] == 3) {
        basePay = 1500;
        salary = basePay + (basePay * 0.2);
    }
    else {
        salary = 0;
    }
    
    if (Employee.yearsService[empCount] >= 11 && Employee.yearsService[empCount] <= 50) {
        salary += ((Employee.yearsService[empCount] - 5) * 0.0100) * basePay;
    }
    else {
        salary += (basePay * 0.05);
    }
    // Educational Code
    if (Employee.eduCode[empCount] == 2) {
        salary += (basePay * 0.05);
    }
    else if (Employee.eduCode[empCount] == 3) {
        salary += (basePay * 0.12);
    }
    else if (Employee.eduCode[empCount] == 4) {
        salary += (basePay * 0.20);
    }
    else {
        salary += 0;
    }
    return salary;
}

void sortEmployee(Emp &Employee)
{
    char option;
    
    cout << "SORT LIST" << endl;
    cout << "'I' -- Sort on ID#." << endl;
    cout << "'N' -- Sort on Last Name." << endl;
    cout << "'S' -- Sort on Gross Salary." << endl;
    
    cout << "Choose a letter from the menu: " << flush;
    cin >> option;
    
    if (option == 'I' || option == 'N' || option == 'S') {
        bubbleSort(Employee, option);
    }
}

void sorting(Emp &Employee, int j)
{
    string temp;
    temp = Employee.lName[j];
    Employee.lName[j] = Employee.lName[j + 1];
    Employee.lName[j + 1] = temp;
    
    temp = Employee.fName[j];
    Employee.fName[j] = Employee.fName[j + 1];
    Employee.fName[j + 1] = temp;
    
    temp = Employee.jobType[j];
    Employee.jobType[j] = Employee.jobType[j + 1];
    Employee.jobType[j + 1] = temp;
    
    int temp1;
    temp1 = Employee.jobCode[j];
    Employee.jobCode[j] = Employee.jobCode[j + 1];
    Employee.jobCode[j + 1] = temp1;
    
    temp1 = Employee.empID[j];
    Employee.empID[j] = Employee.empID[j + 1];
    Employee.empID[j + 1] = temp1;
    
    temp1 = Employee.yearsService[j];
    Employee.yearsService[j] = Employee.yearsService[j + 1];
    Employee.yearsService[j + 1] = temp1;
    
    temp1 = Employee.eduCode[j];
    Employee.eduCode[j] = Employee.eduCode[j + 1];
    Employee.eduCode[j + 1] = temp1;
    
    double temp2;
    temp2 = Employee.salary[j];
    Employee.salary[j] = Employee.salary[j + 1];
    Employee.salary[j + 1] = temp2;
}

void bubbleSort(Emp &Employee, char option)
{
    
    for (int x = 1; x < Employee.empCount; x++)
    {
        for (int j = 0; j < Employee.empCount - 1; j++)
        {
            if ((Employee.empID[j] > Employee.empID[j + 1]) && option == 'I')
            {
                sorting(Employee, j);
            }
            if ((Employee.lName[j] > Employee.lName[j + 1]) && option == 'N')
            {
                sorting(Employee, j);
            }
            if ((Employee.salary[j] > Employee.salary[j + 1]) && option == 'S')
            {
                sorting(Employee, j);
            }
        }
    }
}
