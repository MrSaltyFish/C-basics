// Anvesh Khode
// 8c - WAP to overload the binary + operator for incrementing the
// value of the count variable which is initialized as 1.

#include <iostream>

using namespace std;

class ComplexNumber {
   private:
    double real;
    double imaginary;
    static int count;

   public:
    ComplexNumber() : real(0.0), imaginary(0.0) {}

    ComplexNumber(double r, double i) : real(r), imaginary(i) {}

    ComplexNumber(const ComplexNumber &other)
        : real(other.real), imaginary(other.imaginary) {}

    ComplexNumber operator+(const ComplexNumber &other) const {
        ComplexNumber result;
        result.real = real + other.real;
        result.imaginary = imaginary + other.imaginary;
        count++;
        return result;
    }

    void display() const { cout << real << " + " << imaginary << "i" << endl; }
    static int getCount() { return count; }
    void input() {
        cout << "Enter real part: ";
        cin >> real;
        cout << "Enter imaginary part: ";
        cin >> imaginary;
    }
};

int ComplexNumber::count = 1;

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

    ComplexNumber sum = num1 + num2;
    cout << "Sum of Complex Numbers: ";
    sum.display();

    cout << "Count after increment: " << ComplexNumber::getCount() << endl;
    return 0;
}
