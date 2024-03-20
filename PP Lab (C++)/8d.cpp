// Anvesh Khode
// 8d - 8 d write a program to overload the unary decreament operator as both
// prefix and postfix

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

    Counter operator--() {
        Counter result;
        result.count = --count;
        return result;
    }
    Counter operator--(int) {
        Counter result(*this);
        count--;
        return result;
    }
};

int main() {
    Counter myCounter;

    cout << "Enter the initial value of count: ";
    cin >> myCounter;

    cout << "Initial Count: " << myCounter.getCount() << endl;
    --myCounter;
    cout << "After Prefix Decrement: " << myCounter.getCount() << endl;
    myCounter--;
    cout << "After Postfix Decrement: " << myCounter.getCount() << endl;

    return 0;
}
