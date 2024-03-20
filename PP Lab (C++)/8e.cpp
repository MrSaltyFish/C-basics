// Anvesh Khode
// 8e - 8 e write a program to overload the unary
// increment operator as both prefix and postfix

#include <iostream>

using namespace std;

class Counter {
   private:
    int count;

   public:
    Counter() : count(1) {}
    int getCount() const { return count; }

    friend istream& operator>>(istream& input, Counter& c) {
        input >> c.count;
        return input;
    }

    Counter operator++() {
        Counter result;
        result.count = ++count;
        return result;
    }
    Counter operator++(int) {
        Counter result(*this);
        count++;
        return result;
    }
};

int main() {
    Counter myCounter;

    cout << "Enter the initial value of count: ";
    cin >> myCounter;
    cout << "Initial Count: " << myCounter.getCount() << endl;
    ++myCounter;
    cout << "After Prefix Increment: " << myCounter.getCount() << endl;
    myCounter++;
    cout << "After Postfix Increment: " << myCounter.getCount() << endl;
    return 0;
}
