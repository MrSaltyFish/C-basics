// Anvesh Khode
// 2b - Write a program to check whether a number is palindrome or not

#include <iostream>

using namespace std;

int main() {
  int num;
  cout << "Enter a number: ";
  cin >> num;

  int rev = 0;
  int temp = num;
  while (temp > 0) {
    int rem = temp % 10;
    rev = rev * 10 + rem;
    temp /= 10;
  }

  if (num == rev) {
    cout << "The number is a palindrome." << endl;
  } else {
    cout << "The number is not a palindrome." << endl;
  }

  return 0;
}
