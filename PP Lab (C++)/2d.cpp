// Anvesh Khode
// 2d - Write a program to find the factorial of a number using while loop.

#include <iostream>

using namespace std;

int main()
{
    int number, factorial = 1;
    cout << "Enter a number: ";
    cin >> number;

    while (number > 0)
    {
        factorial *= number;
        number--;
    }

    cout << "The factorial of the number is: " << factorial << endl;

    return 0;
}
