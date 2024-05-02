// Anvesh Khode
// 7d - Create a class student which 3 data members which are
// name,age and address. The constructor of the class must assign
// default values to name as 'Unknown' and address as 'Not Available'.
// It has two function with same names 'setInfo', first function has
// 2 parameters for name and age whereas the second function takes
// three parameters which are assigned to name, age, and address
// of 10 students using array of objects.

#include <iostream>
#include <string>
using namespace std;
class Student {
   public:
    string name;
    int age;
    string address;
    Student() {
        name = "Unknown";
        address = "Not Available";
    }
    void setInfo(string studentName, int studentAge) {
        name = studentName;
        age = studentAge;
    }
    void setInfo(string studentName, int studentAge, string studentAddress) {
        name = studentName;
        age = studentAge;
        address = studentAddress;
    }
    void displayInfo() {
        cout << "Name:" << name << endl;
        cout << "Age:" << age << endl;
        cout << "Address:" << address << endl;
        cout << endl;
    }
};
int main() {
    Student students[10];
    students[0].setInfo("Alice", 28, "123 Main St");
    students[1].setInfo("Natalya", 19, "456 Elm St");
    students[2].setInfo("Charlie", 18, "789 Oak St");
    students[3].setInfo("Aastha", 23, "101 Pine St");
    students[4].setInfo("Emily", 24, "202 Maple St");
    students[5].setInfo("Natasha", 29, "303 Cedar St");
    students[6].setInfo("Shanaya", 26, "404 Birch St");
    students[7].setInfo("Hank", 57, "505 Redwood St");
    students[8].setInfo("Riya", 18, "606 Sequoia St");
    students[9].setInfo("Milee", 29, "707 Walnut St");
    for(int i = 0; i < 10; ++i) {
        cout << "Student " << i + 1 << ":" << endl << "Details:" << endl;
        students[i].displayInfo();
    }
    return 0;
}