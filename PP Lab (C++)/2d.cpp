// Anvesh Khode
// 2d - Write a program to find the factorial
// of a number. (use 'while' loop)

#include <iostream>

int main() {
    int number, factorial = 1;
    std::cout << "Enter a number: ";
    std::cin >> number;

    while(number > 0) {
        factorial *= number;
        number--;
    }

    std::cout << "The factorial of the number is: " << factorial << "\n";
    return 0;
}
