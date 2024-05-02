// Anvesh Khode
// 5b - Create a constructor for the class 'Employee' and display the details of
// 5 Employee objects that is the name of the 'employee' , 'salary', 'date of
// joining', 'email id', and 'phone number'. The constructor should be used to
// initialise details of the employee.

#include <iostream>

using namespace std;

class Employee {
   public:
    string name;
    int id;
    int salary;
    string dateOfJoining;

    Employee(string name, int id, int salary, string dateOfJoining) {
        this->name = name;
        this->id = id;
        this->salary = salary;
        this->dateOfJoining = dateOfJoining;
    }

    void displayDetails() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Salary: " << salary << endl;
        cout << "Date of joining: " << dateOfJoining << endl;
    }
};

int main() {
    Employee employees[5] = {
        Employee("Alice", 12345, 10000, "2023-10-01"),
        Employee("Bob", 54321, 20000, "2023-10-02"),
        Employee("Charlie", 98765, 30000, "2023-10-03"),
        Employee("Daisy", 67543, 40000, "2023-10-04"),
        Employee("Eve", 34567, 50000, "2023-10-05"),
    };
    for(int i = 0; i < 4; i++) {
        employees[i].displayDetails();
    }

    return 0;
}
