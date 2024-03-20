// Anvesh Khode
// 7e - Suppose you have a piggy bank with the initial amount of dollar 50
// and you have to add some more amount to it.create a class add amount with a
// data member named amount with an initial values of $50 now make two
// constructor of this class as follows:-
// 1)without any parameter no amount will be added to piggy bank.
// 2)having a parameter which is amount that will be added to piggy bank.
// 3)create an object of AddAmount class and display the final amount in the
//   piggy bank.

#include <iostream>
using namespace std;
class AddAmount {
   public:
    int amount = 50;
    AddAmount() {}
    AddAmount(int add) { amount = amount + add; }

    void printAmount() { cout << "Amount: $" << amount << endl; }
};
int main() {
    AddAmount a;
    a.printAmount();
    AddAmount a1(100);
    a1.printAmount();
    return 0;
}