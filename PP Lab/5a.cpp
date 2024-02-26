// Anvesh Khode
// 5a - Write a program in C++ to implement
// the use of constructor.

#include <iostream>

using namespace std;

class Person {
public:
  string name;
  int age;

  Person(string name, int age) {
    this->name = name;
    this->age = age;
  }

  void greet() {
    cout << "Hello, my name is " << name << " and I am " << age << " years old." << endl;
  }
};

int main() {
  Person person("Alice", 25);

  person.greet();

  return 0;
}
