// Anvesh Khode
// 3d - Write a program to demonstrate private and public access specifiers in C++

#include <iostream>

using namespace std;

class BankAccount
{
private:
    int balance = 0;

public:
    string name;

    void deposit(int amount)
    {
        balance += amount;
    }

    void withdraw(int amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
        }
        else
        {
            cout << "Insufficient funds." << endl;
        }
    }

    int getBalance()
    {
        return balance;
    }
};

int main()
{
    BankAccount account;

    account.name = "Alice";

    account.deposit(100);

    account.withdraw(50);

    int balance = account.getBalance();

    cout << "Balance: $" << balance << endl;

    return 0;
}
