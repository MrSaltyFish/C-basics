// Anvesh Khode
// 5e - Create a constructor bank to initialise
// the saving account details of customer that is
// customer name, account no., balance,date of opening account
// display the details using another function
// implement the code for 10 account details.
// Also find the account details for least account balance details.

#include <iostream>
#include <limits>
#include <string>

class Bank {
   private:
    std::string customerName;
    int accountNumber;
    double balance;
    std::string openingDate;

   public:
    Bank(std::string name, int accNo, double bal, std::string date)
        : customerName(name),
          accountNumber(accNo),
          balance(bal),
          openingDate(date) {}

    void displayDetails() const {
        std::cout << "Customer Name: " << customerName << std::endl;
        std::cout << "Account Number: " << accountNumber << std::endl;
        std::cout << "Balance: " << balance << std::endl;
        std::cout << "Date of Opening Account: " << openingDate << std::endl
                  << std::endl;
    }

    double getBalance() const { return balance; }
};

int main() {
    Bank accounts[10] = {Bank("John Doe", 1001, 5000, "2024-01-01"),
                         Bank("Alice Smith", 1002, 8000, "2024-02-15"),
                         Bank("Bob Johnson", 1003, 3000, "2024-03-10"),
                         Bank("Emily Brown", 1004, 6000, "2024-04-20"),
                         Bank("Michael Clark", 1005, 9000, "2024-05-05"),
                         Bank("Sophia Martinez", 1006, 2000, "2024-06-30"),
                         Bank("William Lee", 1007, 4000, "2024-07-12"),
                         Bank("Olivia Harris", 1008, 7000, "2024-08-25"),
                         Bank("Daniel King", 1009, 10000, "2024-09-18"),
                         Bank("Emma Wilson", 1010, 1500, "2024-10-03")};

    std::cout << "Account Details:\n";
    for(int i = 0; i < 10; ++i) {
        accounts[i].displayDetails();
    }

    double minBalance = std::numeric_limits<double>::max();
    const Bank* leastBalanceAccount = nullptr;
    for(int i = 0; i < 10; ++i) {
        if(accounts[i].getBalance() < minBalance) {
            minBalance = accounts[i].getBalance();
            leastBalanceAccount = &accounts[i];
        }
    }
    std::cout << "--------------------------------\n";
    if(leastBalanceAccount != nullptr) {
        std::cout << "Account with the least balance:\n";
        leastBalanceAccount->displayDetails();
    }

    return 0;
}
