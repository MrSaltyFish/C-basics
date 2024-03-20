// Anvesh Khode
// 6e - WAP for addition of two complex numbers
// using copy constructor.

#include <iostream>

class Complex {
   private:
    double real;
    double imaginary;

   public:
    Complex(int real, int imaginary) : real(real), imaginary(imaginary) {}

    Complex(const Complex& other)
        : real(other.real), imaginary(other.imaginary) {}

    Complex add(const Complex& other) {
        Complex result(0, 0);
        result.real = real + other.real;
        result.imaginary = imaginary + other.imaginary;
        return result;
    }

    void display() {
        std::cout << real << " + " << imaginary << "i"
                  << "\n";
    }
};

int main() {
    double realPart, imaginaryPart;

    std::cout << "Enter real part of the complex number 1: ";
    std::cin >> realPart;
    std::cout << "Enter imaginary part of the complex number 1: ";
    std::cin >> imaginaryPart;
    Complex number1(realPart, imaginaryPart);

    std::cout << "Enter real part of the complex number 2: ";
    std::cin >> realPart;
    std::cout << "Enter imaginary part of the complex number 2: ";
    std::cin >> imaginaryPart;
    Complex number2(realPart, imaginaryPart);

    Complex number2Copy(number2);
    Complex result = number1.add(number2Copy);

    std::cout << "The sum of the two complex numbers is: ";
    result.display();
    return 0;
}
