// Anvesh Khode
// 2b - Write a program to check whether a
// 3-digit number is palindrome or not. (use 'while' loop)

#include <iostream>

int main() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    int rev = 0;
    int temp = num;
    while(temp > 0) {
        int rem = temp % 10;
        rev = rev * 10 + rem;
        temp /= 10;
    }

    if(num == rev) {
        std::cout << "The number is a palindrome."
                  << "\n";
    } else {
        std::cout << "The number is not a palindrome."
                  << "\n";
    }

    return 0;
}
