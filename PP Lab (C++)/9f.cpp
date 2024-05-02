// Anvesh Khode
// 9f - All the banks operating in India are controlled by RBI. RBI has set
// guidelines which all banks must follow, for example - RBI has set minimum
// interest rates applicable to saving bank accounts to 4% equally. Write a
// program to implement bank functionality; create class RBI as base class and
// implement few derived classes as SBI, ICICI, AXIS. Asssume and implement
// required member variables and functions in each class.
#include <iostream>
using namespace std;

class RBI {
   protected:
    double minSavingsInterestRate;

   public:
    RBI() : minSavingsInterestRate(4.0) {}

    void setMinSavingsInterestRate(double rate) {
        minSavingsInterestRate = rate;
    }

    void displayGuidelines() {
        cout << "RBI Guidelines:" << endl;
        cout << "Minimum Savings Interest Rate: " << minSavingsInterestRate
             << "%" << endl;
    }
};

class SBI : public RBI {
   public:
    void displayBankInfo() {
        cout << "SBI Bank:" << endl;
        cout << "Savings Interest Rate: " << minSavingsInterestRate << "%"
             << endl;
    }
};

class ICICI : public RBI {
   public:
    void displayBankInfo() {
        cout << "ICICI Bank:" << endl;
        cout << "Savings Interest Rate: " << minSavingsInterestRate << "%"
             << endl;
    }
};

class Axis : public RBI {
   public:
    void displayBankInfo() {
        cout << "Axis Bank:" << endl;
        cout << "Savings Interest Rate: " << minSavingsInterestRate << "%"
             << endl;
    }
};

int main() {
    SBI sbi;
    ICICI icici;
    Axis axis;

    sbi.displayBankInfo();
    icici.displayBankInfo();
    axis.displayBankInfo();

    sbi.setMinSavingsInterestRate(3.75);

    cout << "\nAfter rate change:" << endl;
    sbi.displayBankInfo();
    icici.displayBankInfo();
    axis.displayBankInfo();

    return 0;
}
