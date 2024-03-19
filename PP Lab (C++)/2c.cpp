// Anvesh Khode
// 2c - Write a program to print the Fibonacci
// series upto 'n' terms (using 'for' loop)

#include <iostream>

int main() {
    int n, t1 = 0, t2 = 1, nextTerm = 0;
    std::cout << "Enter the number of terms: ";
    std::cin >> n;
    std::cout << "Fibonacci Series: ";

    for(int i = 1; i <= n; ++i) {
        // Prints the first two terms.
        if(i == 1) {
            std::cout << t1 << ", ";
            continue;
        }

        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;

        std::cout << t1 << ", ";
    }

    std::cout << nextTerm;
    return 0;
}