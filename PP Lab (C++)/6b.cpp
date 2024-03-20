// Anvesh Khode
// 6b - For class 'Person' with the following attributes - 'name', 'age' and
// 'occupation', implement a parametrized constructor that takes the value from
// all three attributes and initializes them.
// Create 3 objects of 'Person' and display their values/attributes.

#include <iostream>
#include <string>

class Person {
   private:
    std::string name;
    int age;
    std::string occupation;

   public:
    Person(std::string n, int a, std::string occ)
        : name(n), age(a), occupation(occ) {}

    void displayDetails() const {
        std::cout << "Name: " << name << "\n";
        std::cout << "Age: " << age << "\n";
        std::cout << "Occupation: " << occupation << "\n\n";
    }
};

int main() {
    Person person1("John Doe", 30, "Engineer");
    Person person2("Alice Smith", 25, "Doctor");
    Person person3("Bob Johnson", 40, "Teacher");

    std::cout << "Details of Person 1:\n";
    person1.displayDetails();
    std::cout << "Details of Person 2:\n";
    person2.displayDetails();
    std::cout << "Details of Person 3:\n";
    person3.displayDetails();
    return 0;
}
