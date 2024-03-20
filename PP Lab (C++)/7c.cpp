// Anvesh Khode
// 7c - WAP to implement constructor overloading to initialise and display the
// employee details such as ID,name,department,date of joining,salary.

#include <iostream>
#include <string>

class Employee {
   public:
    int employeeId;
    std::string name;
    std::string department;
    std::string dateOfJoining;
    double salary;

    Employee(int id, const std::string& n, const std::string& dept,
             const std::string& doj)
        : employeeId(id),
          name(n),
          department(dept),
          dateOfJoining(doj),
          salary(0.0) {}
    Employee(int id, std::string empName, std::string dept, std::string doj,
             double empSalary)
        : employeeId(id),
          name(empName),
          department(dept),
          dateOfJoining(doj),
          salary(empSalary) {}

    void displayDetails() {
        std::cout << "Employee ID:" << employeeId << "\n";
        std::cout << "Name:" << name << "\n";
        std::cout << "Department:" << department << "\n";
        std::cout << "Date of Joining:" << dateOfJoining << "\n";
        std::cout << "Salary:" << salary << "\n";
    }
};
int main() {
    Employee emp1(101123, "Richa Zararia", "HR", "15/2/2020", 55000.0);
    Employee emp2(102214, "Jasmine Sharma", "Engineering", "5/7/2019", 60000.0);
    Employee emp3(101125, "Abdul Kalam", "HR", "15/2/2024");

    std::cout << "Employee 1 details:"
              << "\n";
    emp1.displayDetails();
    std::cout << "\nEmployee 2 details:"
              << "\n";
    emp2.displayDetails();
    std::cout << "\nEmployee 3 details:"
              << "\n";
    emp3.displayDetails();
    return 0;
}