// Anvesh Khode
// 3a - Write a program to
// demonstrate classes and objects in C++

#include <iostream>

using namespace std;
class Person
{
public:
    string name;
    int age;

    void greet()
    {
        cout << "Hello, my name is " << name << " and I am " << age << " years old." << endl;
    }
};

int main()
{
    Person person;

    person.name = "Alice";
    person.age = 25;

    person.greet();

    return 0;
}
