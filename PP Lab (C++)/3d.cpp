// Anvesh Khode
// 3d - WAP to create a class name 'Student' with
// a string 'name' and integer 'rollNo'.
// Assign the value of 'rollNo' as 2 and that of 'name'
// John by creating an object of the class 'Student'.

#include <iostream>

class Student {
   public:
    std::string name;
    int rollNo;

    Student(std::string str, int input1) : name(str), rollNo(input1) {}

    void printData() {
        std::cout << "Name: " << name << "\n";
        std::cout << "Roll Number: " << rollNo << "\n";
    }
};

int main() {
    Student person("John", 2);
    person.printData();
    return 0;
}
