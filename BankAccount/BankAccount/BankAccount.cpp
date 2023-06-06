// BankAccount.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>

using namespace std;

const uint8_t PAUSE_TIME_SECONDS = 6;

class bankAccnt {
public:
    bankAccnt(string name);
    bankAccnt(string name, double balance);
    void withAccount(double amount);
    void depAccount(double amount);
    void tranAccount(vector<bankAccnt>& acc,string name, double amount);
    double getBalance() { return this->balance; };
    string getName() { return this->name; };
    double balance = 0.0;
private:
    
    string name;
};

void remAccount(vector<bankAccnt>& b);
void addAccount(vector<bankAccnt>& b);

bankAccnt* search(vector<bankAccnt>& b, string name);
void printThinking();
void displayVector(vector<bankAccnt> b);

int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    vector <string> queue;
    string nextAccount;
    vector<bankAccnt> accounts;
    string accountName;
    string accountName2;

    double dollarVal = 0.0;

    char menuInput;

    do {
        displayVector(accounts);
        cin >> menuInput;
        menuInput = toupper(menuInput);
        switch (menuInput) {
        case 'W':
            cout << "\nWhich account?: ";
            cin >> accountName;
                if (search(accounts, accountName) != nullptr) {
                    cout << "\nHow much to withdraw?: ";
                    cin >> dollarVal;
                    search(accounts, accountName)->withAccount(dollarVal);
                }
                else if (search(accounts, accountName) == nullptr) {
                    cout << "\nNo name match found";
                    printThinking();
                }
            break;
        case 'A':
            addAccount(accounts);
            break;
        case 'R':
            remAccount(accounts);
            break;
        case 'D':
            cout << "\nWhich account?: ";
            cin >> accountName;
            if (search(accounts, accountName) != nullptr) {
                cout << "\nHow much to deposit?: ";
                cin >> dollarVal;
                search(accounts, accountName)->depAccount(dollarVal);
            }
            else if (search(accounts, accountName) == nullptr) {
                cout << "\nNo name match found";
                printThinking();
            }
            break;
        case 'T':
            cout << "\nHow much money to transfer?: ";
            cin >> dollarVal;
            cout << "\nSelect an account to transfer from: ";
            cin >> accountName;
            cout << "\nSelect an account to transfer to: ";
            cin >> accountName2;
            if (search(accounts, accountName) != nullptr && search(accounts, accountName2) != nullptr) {
                search(accounts, accountName)->tranAccount(accounts,accountName2,dollarVal);
            }
            else if (search(accounts, accountName) == nullptr || search(accounts, accountName2) == nullptr) {
                cout << "\nAccount mismatch.";
                printThinking();
            }
            break;
        }
    } while (menuInput != 'Q');
    cout << "\nThank you for using Online Banking(TM)!" << endl;
}

void bankAccnt::withAccount(double amount) {
    this->balance -= amount;
}

void bankAccnt::depAccount(double amount) {
    this->balance += amount;
}

void addAccount(vector<bankAccnt>& b) {
    string name;
    double balance;
    cout << "\nWho is your new account with?: ";
    cin >> name;
    cout << "\nHow much is in your new account?: ";
    cin >> balance;
    bankAccnt newAccount(name, balance);
    b.push_back(newAccount);
}

void remAccount(vector<bankAccnt>& b) {
    string name;
    if (b.size() > 0) {
        cout << "what account would you like removed?: ";
        cin >> name;
        for (auto it = b.begin(); it != b.end(); ++it) {
            if (it->getName() == name) {
                b.erase(it);
                break;
            }
            else {
                cout << "\nNo such account.";
                printThinking();
            }
        }
    }
    else {
        cout << "\nPlease Add an account before attempting to remove one";
        printThinking();
    }
}

void bankAccnt::tranAccount(vector<bankAccnt>& acc,string name, double amount) {
    this->balance -= amount;
    search(acc, name)->balance += amount;
}

bankAccnt::bankAccnt(string name){
    this->name = name;
}

bankAccnt::bankAccnt(string name, double balance){
    this->name = name; 
    this->balance = balance;
}

void displayVector(vector<bankAccnt> b) {
    double totalBal = 0.0;
    system("cls");
    cout << "\nAccount          Balance\n";
    cout << "--------------------------\n";

    for (bankAccnt ba:b) {
        cout << ba.getName() << "          " << ba.getBalance() << "$" << endl;
        totalBal += ba.getBalance();
    }
    cout << "                    " << totalBal << "$";
    cout << "\n(A)dd, (R)emove, (Q)uit, (W)ithdraw, (D)eposit, (T)ransfer: ";
}

bankAccnt* search(vector<bankAccnt>& b, string name) {
    for (bankAccnt& match : b) {
        if (match.getName() == name) {
            return &match;
        }
    }
    return nullptr;
}

void printThinking() {
    for (int i = 0; i < 6; i++) {
        cout << ". ";
        Sleep(PAUSE_TIME_SECONDS * 100);
    }

}