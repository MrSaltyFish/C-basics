// Anvesh Khode
// 8a - WAP to overload binary arithematic operator(user)

#include <iostream>

class Complex {
   public:
    double real;
    double imag;

    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    Complex operator+(const Complex &other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    void input() {
        std::cout << "Enter real part: ";
        std::cin >> real;
        std::cout << "Enter imaginary part: ";
        std::cin >> imag;
    }
    void display() const { std::cout << real << " + " << imag << "i\n"; }
};

int main() {
    Complex num1, num2;

    std::cout << "Enter values for Complex Number 1:"
              << "\n";
    num1.input();
    std::cout << "Enter values for Complex Number 2:"
              << "\n";
    num2.input();

    std::cout << "Complex Number 1: ";
    num1.display();
    std::cout << "Complex Number 2: ";
    num2.display();

    Complex sum = num1 + num2;
    std::cout << "Sum of Complex Numbers: ";
    sum.display();

    return 0;
}
