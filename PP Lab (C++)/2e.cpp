// Anvesh Khode
// 2e - Write a program to design a calculator
// for arithmetic operations using 'switch' case

#include <iostream>
using namespace std;

int main()
{
    char op;
    float num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    cout << "Enter an operator (+, -, *, /): ";
    cin >> op;

    float result;
    switch (op)
    {
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
        cout << "Invalid operator";
        return 1;
    }

    cout << "The result is: " << result << endl;

    return 0;
}
