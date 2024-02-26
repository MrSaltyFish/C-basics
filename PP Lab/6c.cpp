// Anvesh Khode
// 6c - Create class called Person with the following attributes
// name, age and occupation.

#include <iostream>

using namespace std;

class Person {
private:
  string name;
  int age;
  string occupation;

public:
  Person(string name, int age, string occupation) : name(name), age(age), occupation(occupation) {}

  void displayDetails() {
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Occupation: " << occupation << endl;
  }
};

int main() {
  Person persons[3];

  persons[0] = Person("Alice", 25, "Software Engineer");
  persons[1] = Person("Bob", 30, "Doctor");
  persons[2] = Person("Charlie", 35, "Teacher");

  for (int i = 0; i < 3; i++) {
    persons[i].displayDetails();
  }

  return 0;
}
