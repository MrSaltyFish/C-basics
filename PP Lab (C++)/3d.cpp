// Anvesh Khode
// 3d - WAP to create a class name Student with
// a string variable name and integer variable roll no.
// assigned the value of rollno. as 2 and that of name
// john by creating object of the class Student.

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
