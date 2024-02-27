// Anvesh Khode
// 8g - 8 g wap in c++ to overload the unary -- operator for performing the subtraction operation

#include <iostream>

using namespace std;

class Subtraction {
private:
    int value;

public:
    Subtraction(int initialValue) : value(initialValue) {}

    Subtraction operator--() {
        Subtraction result(value);
        --value;
        return result;
    }

    int getValue() const {
        return value;
    }
};

int main() {
    int initialValue;

    cout << "Enter the initial value: ";
    cin >> initialValue;

    Subtraction subtractionObj(initialValue);

    cout << "Initial Value: " << subtractionObj.getValue() << endl;

    --subtractionObj;

    cout << "After Prefix Subtraction: " << subtractionObj.getValue() << endl;

    return 0;
}
