#include <iostream>

class Complex {
   private:
    double real;
    double imag;

   public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag,
                       real * other.imag + imag * other.real);
    }

    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        return Complex((real * other.real + imag * other.imag) / denominator,
                       (imag * other.real - real * other.imag) / denominator);
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
    Complex c1(3, 2);
    Complex c2(1, 4);

    std::cout << "Enter values for Complex Number 1:"
              << "\n";
    c1.input();
    std::cout << "Enter values for Complex Number 2:"
              << "\n";
    c2.input();

    std::cout << "c1 = ";
    c1.display();
    std::cout << "c2 = ";
    c2.display();

    Complex result;
    result = c1 - c2;
    std::cout << "Subtraction result: ";
    result.display();

    result = c1 * c2;
    std::cout << "Multiplication result: ";
    result.display();

    result = c1 / c2;
    std::cout << "Division result: ";
    result.display();

    return 0;
}
