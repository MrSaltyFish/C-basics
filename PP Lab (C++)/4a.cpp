// Anvesh Khode
// 4a - WAP to print the 'name', 'salary', and 'date of joining'
// of 10 employees in a company using array of objects.

#include <iostream>

using namespace std;

class Employee {
   public:
    string name;
    int salary;
    string dateOfJoining;

    void print() {
        cout << "Name: " << name << endl;
        cout << "Salary: Rs. " << salary << endl;
        cout << "Date of joining: " << dateOfJoining << endl;
    }
};

int main() {
    Employee employees[10];

    for(int i = 0; i < 10; i++) {
        cout << "Enter the name of employee " << i + 1 << ": ";
        cin >> employees[i].name;
        cout << "Enter the salary of employee " << i + 1 << ": ";
        cin >> employees[i].salary;
        cout << "Enter the date of joining of employee " << i + 1 << ": ";
        cin >> employees[i].dateOfJoining;
    }

    for(int i = 0; i < 10; i++) {
        employees[i].print();
    }

    return 0;
}
