// Anvesh Khode
// 3g - Print the sum, difference and product of the two numbers
// by creating a class 'Complex' with seperate function
// for each operation whose real and imaginary parts are
// entered are entered by user.

#include <iostream>

class Complex {
   private:
    double real;
    double imaginary;

   public:
    Complex(double r, double im) : real(r), imaginary(im) {}

    Complex add(Complex c) {
        return Complex(real + c.real, imaginary + c.imaginary);
    }

    Complex subtract(Complex c) {
        return Complex(real - c.real, imaginary - c.imaginary);
    }

    Complex multiply(Complex c) {
        double resultReal = (real * c.real) - (imaginary * c.imaginary);
        double resultImaginary = (real * c.imaginary) + (imaginary * c.real);
        return Complex(resultReal, resultImaginary);
    }

    void display() { std::cout << real << " + " << imaginary << "i"; }
};

int main() {
    double real1, imaginary1, real2, imaginary2;

    std::cout << "Enter real and imaginary parts of the first complex number: ";
    std::cin >> real1 >> imaginary1;

    std::cout
        << "Enter real and imaginary parts of the second complex number: ";
    std::cin >> real2 >> imaginary2;

    Complex num1(real1, imaginary1);
    Complex num2(real2, imaginary2);

    std::cout << "Sum: ";
    num1.add(num2).display();
    std::cout << "\n";

    std::cout << "Difference: ";
    num1.subtract(num2).display();
    std::cout << "\n";

    std::cout << "Product: ";
    num1.multiply(num2).display();
    std::cout << "\n";

    return 0;
}
