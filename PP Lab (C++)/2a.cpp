// Anvesh Khode
// 2a - Write a program to add two
// numbers given by the user in C++

#include <iostream>

int main() {
    int num1, num2;
    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;

    int sum = num1 + num2;
    std::cout << "The sum of the two numbers is: " << sum << "\n";

    return 0;
}
