// Anvesh Khode
// 2e - Write a program to design a calculator
// for arithmetic operations using 'switch' case

#include <iostream>

int main() {
    char op;
    float num1, num2;
    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;
    std::cout << "Enter an operator (+, -, *, /): ";
    std::cin >> op;

    float result;
    switch(op) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        default:
            std::cout << "Invalid operator";
            return 1;
    }
    std::cout << "The result is: " << result << std::endl;
    return 0;
}
