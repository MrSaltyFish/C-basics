// Anvesh Khode
// 9a - 9 a WAP in C++ that defines two classes, Account and Programmer, and then creates an object of the Pro

#include <iostream>
using namespace std;

class Account
{
protected:
    double balance;

public:
    Account(double initialBalance) : balance(initialBalance) {}

    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposited: " << amount << " into Account" << endl;
    }

    void withdraw(double amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
            cout << "Withdrawn: " << amount << " from Account" << endl;
        }
        else
        {
            cout << "Insufficient balance in Account" << endl;
        }
    }
};

class Programmer : public Account
{
private:
    string skill;

public:
    Programmer(double initialBalance, string skillType)
        : Account(initialBalance), skill(skillType) {}

    void displayInfo()
    {
        cout << "Account Balance: " << balance << endl;
        cout << "Programming Skill: " << skill << endl;
    }
};

int main()
{
    Programmer programmer(5000.0, "C++");

    programmer.displayInfo();

    programmer.deposit(1000.0);
    programmer.withdraw(2500.0);

    programmer.displayInfo();

    return 0;
}
