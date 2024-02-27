// Anvesh Khode
// 3e - Write a program to demonstrate parameterized function using class and object in C++

#include <iostream>

using namespace std;

class Person
{
public:
    string name;
    int age;

    void greet(string name)
    {
        cout << "Hello, " << name << ", my name is " << this->name << " and I am " << this->age << " years old." << endl;
    }
};

int main()
{
    Person person;

    person.name = "Alice";
    person.age = 25;

    person.greet("Bob");

    return 0;
}
