// Anvesh Khode
// 8a - write a c++ program to overload binary arithematic operator(user)

#include <iostream>

using namespace std;

class ComplexNumber {
private:
    double real;
    double imaginary;

public:
    ComplexNumber() : real(0.0), imaginary(0.0) {}

    ComplexNumber(double r, double i) : real(r), imaginary(i) {}

    ComplexNumber(const ComplexNumber &other) : real(other.real), imaginary(other.imaginary) {}

    ComplexNumber add(const ComplexNumber &other) {
        double newReal = real + other.real;
        double newImaginary = imaginary + other.imaginary;
        return ComplexNumber(newReal, newImaginary);
    }

    void display() const {
        cout << real << " + " << imaginary << "i" << endl;
    }

    void input() {
        cout << "Enter real part: ";
        cin >> real;
        cout << "Enter imaginary part: ";
        cin >> imaginary;
    }
};

int main() {
    ComplexNumber num1, num2;

    cout << "Enter values for Complex Number 1:" << endl;
    num1.input();

    cout << "Enter values for Complex Number 2:" << endl;
    num2.input();

    cout << "Complex Number 1: ";
    num1.display();
    cout << "Complex Number 2: ";
    num2.display();

    ComplexNumber sum = num1.add(num2);
    cout << "Sum of Complex Numbers: ";
    sum.display();

    return 0;
}
