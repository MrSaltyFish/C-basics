// Anvesh Khode
// 3a - Write a program to
// demonstrate classes and objects in C++

#include <iostream>

class Student {
   public:
    std::string name;
    int age;

    void greet() {
        std::cout << "Hello, my name is " << name << " and I am " << age
                  << " years old."
                  << "\n";
    }
};

int main() {
    Student person;

    person.name = "Alice";
    person.age = 25;
    person.greet();
    return 0;
}
