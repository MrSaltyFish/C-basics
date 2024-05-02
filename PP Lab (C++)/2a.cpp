// Anvesh Khode
// 2a - WAP to find the smallest number among the
// given 5 numbers. (use if-else ladder)

#include <iostream>

int main() {
    double num1, num2, num3, num4, num5;

    std::cout << "Enter five numbers: ";
    std::cin >> num1 >> num2 >> num3 >> num4 >> num5;

    double smallest = num1;

    if(num2 < smallest) {
        smallest = num2;
    }
    if(num3 < smallest) {
        smallest = num3;
    }
    if(num4 < smallest) {
        smallest = num4;
    }
    if(num5 < smallest) {
        smallest = num5;
    }

    std::cout << "The smallest number among the given 5 numbers is: "
              << smallest << "\n";

    return 0;
}
