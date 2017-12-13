#include "BankAccountList.hpp"

// initialize the constructor
BankAccountList::BankAccountList() {
    num_elements = 0;
    list_state = 0;
}


void BankAccountList::addAccount(const BankAccount &BA)
{
    if (isFull())
    {
        cout << "List is already full." << endl;
    }
    
    int index = 0;
    bool found = findAccount(BA.getAccountNumber(), index);
    
    if (!found)
    {
        List[num_elements] = BA;
        num_elements++;
        list_state = 0;
    }
    else
    {
        cout << "Account Number: " << BA.getAccountNumber() << " is already in the list." << endl;
    }
}

bool BankAccountList::deleteAccount(const string &actNum)
{
    int index;
    bool found = findAccount(actNum, index);
    
    if (found)
    {
        List[index] = List[num_elements - 1];
        num_elements--;
        cout << "Successfully deleted Bank Account Number: " << actNum << endl;
        return true;
    }
    else
    {
        cout << "Account Number" << actNum << "is not on the list." << endl;
        return false;
    }
}

bool BankAccountList::depositMoney(const string & actNum, double money)
{
    int index;
    bool found = findAccount(actNum, index);
    
    if (found)
    {
        //If deposit is successful then returns true, otherwise returns false. List state is set to unsorted(0) if list was already sorted by balance.
        if (list_state == 3) {
            list_state = 0;
        }
        List[index].deposit(money);
        cout << "Successfully deposited amount to Bank Account Number: " << actNum << endl;
        return true;
    }
    else
    {
        cout << "Account number doesn't exist." << endl;
        return false;
    }
}

void BankAccountList::makeEmpty()
{
    num_elements = 0;
    list_state = 0;
}

bool BankAccountList::updateAccount()
{
    if (isEmpty())
    {
        cout << "List is empty." << endl;
        return false;
    }
    string actNum;
    int index;
    
    cout << "Enter Account Number to be updated: ";
    cin >> actNum;
    
    bool found = findAccount(actNum, index);
    
    if (found)
    {
        string lastName;
        //If list was sorted based on last name then sets list state to unsorted state value(0)
        if (list_state == 2) {
            list_state = 0;
        }
        cout << "Enter new Last Name: ";
        cin >> lastName;
        List[index].setLastName(lastName);
        return true;
    }
    else
    {
        cout << "Account doesn't exist." << endl;
        return false;
    }
}

bool BankAccountList::withDrawMoney(const string & actNum, double money)
{
    int index;
    bool found = findAccount(actNum, index);
    
    if (found)
    {
        //List state is set to unsorted (0) if it was sorted based on balance.
        if (list_state == 3) {
            list_state = 0;
        }
        List[index].withdraw(money);
        cout << "Successfully withrawn amount from Bank Account Number: " << actNum << endl;
        return true;
    }
    else
    {
        cout << "Account number doesn't exist." << endl;
        return false;
    }
}

void BankAccountList::sort(int flag)
{
    for (size_t i = 0; i < num_elements; i++)
    {
        for (size_t j = 0; j < num_elements - i - 1; j++)
        {
            // sorts based on account number in ascending order
            if (flag == 1)
            {
                if (List[j].getAccountNumber() > List[j + 1].getAccountNumber())
                {
                    BankAccount temp;
                    temp = List[j];
                    List[j] = List[j + 1];
                    List[j + 1] = temp;
                }
                list_state = 1;
            }
            // sorts based on last name of customer in ascending order
            else if (flag == 2)
            {
                if (List[j].getLastName() > List[j + 1].getLastName())
                {
                    BankAccount Temp;
                    Temp = List[j];
                    List[j] = List[j + 1];
                    List[j + 1] = Temp;
                }
                list_state = 2;
            }
            // sorts based on balance in ascending order
            else if (flag == 3)
            {
                if (List[j].getBalance() > List[j + 1].getBalance())
                {
                    BankAccount temp;
                    temp = List[j];
                    List[j] = List[j + 1];
                    List[j + 1] = temp;
                }
                list_state = 3;
            }
        }
    }
}

void BankAccountList::setAccountAt(BankAccount &BA, unsigned int index)
{
    if (index < num_elements)
    {
        BA = List[index];
        list_state = 0;
    }
    else
    {
        cout << "No change was made." << endl;
    }
    
}

// duplicate ng updateAccount()?
void BankAccountList::setLastName(const string & lname, const string &actNum)
{
    
}

bool BankAccountList::findAccount(const string &actNum, int &i) const
{
    bool found = false;
    i = -1;
    
    static_cast<int>(num_elements);
    
    for (int x = 0; x < num_elements; x++)
        
    {
        if (List[x].getAccountNumber() == actNum)
        {
            found = true;
            i = x;
        }
    }
    return found;
}

bool BankAccountList::getAccountAt(BankAccount & BA, unsigned int &index) const
{
    if (index < num_elements)
    {
        BA = List[index];
        return true;
    }
    else
    {
        cout << "No change was made." << endl;
        return false;
    }
}

double BankAccountList::getBalance(const string &actNum) const
{
    int index;
    bool found = findAccount(actNum, index);
    
    if (found)
    {
        cout << "Account Balance: " << List[index].toString() << endl;
        return List[index].getBalance();
    }
    else
    {
        cout << "Account number doesn't exist." << endl;
        return 0.0;
    }
}

int BankAccountList::getCapacity()
{
    return MAX;
}

const string BankAccountList::getFirstName(const string &actNum) const
{
    string fn;
    int index;
    bool found = findAccount(actNum, index);
    
    if (found)
    {
        fn = List[index].getFirstName();
    }
    else
    {
        cout << "Account number doesn't exist." << endl;
    }
    return fn;
}

const string BankAccountList::getFullName(const string &actNum) const
{
    string fullname;
    int index;
    bool found = findAccount(actNum, index);
    
    if (found)
    {
        fullname = List[index].getFullName();
    }
    else
    {
        cout << "Account number doesn't exist." << endl;
    }
    return fullname;
}

void BankAccountList::getHighestBalanceAccount(BankAccount &BA) const
{
    double temp = 0.0;
    
    if (isEmpty())
    {
        cout << "List is empty." << endl;
    }
    else {
        for (int x = 0; x < num_elements; x++)
        {
            if (List[x].getBalance() > temp) {
                temp = List[x].getBalance();
                BA = List[x];
            }
        }
        cout << temp;
    }
}

void BankAccountList::getInstance(BankAccountList &BAL)
{
    BankAccount temp;
    BankAccount::getInstance(temp);
    BAL.addAccount(temp);
}

void BankAccountList::getInstance(BankAccountList &BAL, ifstream &in)
{
    size_t index = 0;
    while (in.peek() != EOF && index < MAX)
    {
        BankAccount temp;
        BankAccount::getInstance(temp, in);
        BAL.addAccount(temp);
        index++;
    }
}

const string BankAccountList::getLastName(const string & actNum)const
{
    string ln;
    int index;
    bool found = findAccount(actNum, index);
    if (found)
    {
        ln = List[index].getLastName();
    }
    else
    {
        cout << "Account number doesn't exist." << endl;
    }
    return ln;
}

int BankAccountList::getLengthOfLongestFirstName() const
{
    int temp = 0;
    
    for (int x = 0; x < num_elements; x++) {
        if (getFirstName(List[x].getAccountNumber()).length() > temp) {
            temp = getFirstName(List[x].getAccountNumber()).length();
        }
    }
    return temp;
}

int BankAccountList::getLengthOfLongestLastName() const
{
    int temp = 0;
    
    for (int x = 0; x < num_elements; x++) {
        if (getLastName(List[x].getAccountNumber()).length() > temp) {
            temp = getLastName(List[x].getAccountNumber()).length();
        }
    }
    return temp;
}

int BankAccountList::getListState() const
{
    return list_state;
}

double BankAccountList::getMeanOfAllDeposits() const
{
    return sumAllDeposits() / num_elements;
}

int BankAccountList::getNumberOfElements() const
{
    return num_elements;
}

void BankAccountList::getSmallestBalanceAccount(BankAccount &BA) const
{
    double temp = 0.0;
    
    if (isEmpty())
    {
        cout << "List is empty." << endl;
    }
    else {
        for (int x = 0; x < num_elements; x++)
        {
            if (x == 0) {
                temp = List[x].getBalance();
            }
            if (List[x].getBalance() < temp) {
                temp = List[x].getBalance();
                BA = List[x];
            }
        }
        cout << temp;
    }
}


double BankAccountList::sumAllDeposits() const
{
    double sum = 0.0;
    
    for (int x = 0; x < num_elements; x++) {
        sum += List[x].getBalance();
    }
    return sum;
}

bool BankAccountList::isEmpty() const
{
    if (getNumberOfElements() == 0)
    {
        return true;
    }
    else {
        return false;
    }
}
bool BankAccountList::isFull() const
{
    if (getNumberOfElements() == MAX)
    {
        return true;
    }
    else {
        return false;
    }
}

const string BankAccountList::listDescription() const
{
    int listState = getListState();
    string desc;
    
    if (listState == 0)
    {
        desc = "List is unsorted.";
    }
    else if (listState == 1)
    {
        desc = "List is sorted by Account Number.";
    }
    else if (listState == 2)
    {
        desc = "List is sorted by Last Name.";
    }
    else if (listState == 3)
    {
        desc = "List is sorted by Balance.";
    }
    return desc;
}

unsigned int BankAccountList::numberOfDepositsAboveMean() const
{
    int counter = 0;
    
    for (int x = 0; x < num_elements; x++) {
        if (List[x].getBalance() > getMeanOfAllDeposits()) {
            counter++;
        }
    }
    return counter;
}

unsigned int BankAccountList::numberOfDepositsAtOrBelowMean() const
{
    int counter = 0;
    
    for (int x = 0; x < num_elements; x++) {
        if (List[x].getBalance() <= getMeanOfAllDeposits()) {
            counter++;
        }
    }
    return counter;
}

void BankAccountList::print(ostream & out = cout) const
{
    for (size_t x = 0; x < num_elements; x++)
    {
        out << "Account Number: " << List[x].getAccountNumber() << endl;
        out << "Last Name: " << List[x].getLastName() << endl;
        out << "First Name: " << List[x].getFirstName() << endl;
        out << "Balance: " << List[x].toString() << endl;
    }
}

void BankAccountList::printListAsReport() const
{
    string oFileName;
    ofstream out;
    cout << "Please enter output filename for the report: ";
    cin >> oFileName;
    
    out.open(oFileName);
    if (out.is_open()) {
        out << "Account Number" << setw(15) << "Last Name" << setw(15) << "First Name" << setw(15) <<"Balance" << endl;
        out << toString();
        
        printStatistics(out);
    }
    
    out.close();
}

void BankAccountList::printStatistics(ostream &out = cout) const
{
    BankAccount BA;
    out << fixed << setprecision(2);
    out << "Number of accounts: " << getNumberOfElements() << endl;
    out << "Sum of all deposits: $" << sumAllDeposits() << endl;
    out << "Mean or average deposit : " << getMeanOfAllDeposits() << endl;
    out << "Number of accounts above mean: " << numberOfDepositsAboveMean() << endl;
    out << "Number of accounts below or at mean: " << numberOfDepositsAtOrBelowMean() << endl;
    out << "Amount of money in highest deposit account: $";
    getHighestBalanceAccount(BA);
    out << endl;
    out << "Amount of money in the lowest deposit account: $";
    getSmallestBalanceAccount(BA);
    out << endl;
    out << "Standard deviation of deposits or balances: " << Standard_Deviation_Deposits() << endl;
}

double BankAccountList::Standard_Deviation_Deposits() const
{
    double sd = 0.0;
    double mean = getMeanOfAllDeposits();
    for (int x = 0; x < num_elements; x++) {
        sd += sqrt((pow(List[x].getBalance() - mean, 2)));
    }
    return sd / num_elements;
}

const string BankAccountList::toString() const
{
    string accounts = "";
    
    for (size_t x = 0; x < num_elements; x++)
    {
        accounts += List[x].getAccountNumber() + "\t\t" + List[x].getLastName() + "\t\t" + List[x].getFirstName() + "\t\t" + List[x].toString() + "\n";
    }
    
    return accounts;
}

void BankAccountList::writeToNewInputFile(ostream &out) const
{
    for (size_t x = 0; x < num_elements; x++)
    {
        out << fixed << setprecision(2);
        out << endl << List[x].getAccountNumber() << " " << List[x].getLastName() << " " << List[x].getFirstName() << " " << List[x].getBalance();
    }
}

