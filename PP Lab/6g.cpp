// Anvesh Khode
// 6g - WAP for addition of two complex numbers using copy constructor.

#include <iostream>

using namespace std;

class Complex {
private:
  int real;
  int imaginary;

public:
  Complex(int real, int imaginary) : real(real), imaginary(imaginary) {}

  Complex(const Complex& other) : real(other.real), imaginary(other.imaginary) {}

  Complex add(const Complex& other) {
    Complex result;
    result.real = real + other.real;
    result.imaginary = imaginary + other.imaginary;
    return result;
  }

  void display() {
    cout << real << " + " << imaginary << "i" << endl;
  }
};

int main() {
  Complex number1(1, 2);
  Complex number2(3, 4);

  Complex number2Copy(number2);

  Complex result = number1.add(number2Copy);

  cout << "The sum of the two complex numbers is: ";
  result.display();

  return 0;
}
