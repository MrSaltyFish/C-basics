// Anvesh Khode
// 4e - Define class 'Employee' with
// attributes 'name', 'department' and 'salary'.
// Create an array of 4 'Employee' objects and
// write a function to increase the 'salary' of
// each employee by 10%.

#include <iostream>
#include <string>

class Employee {
   private:
    std::string name;
    std::string department;
    double salary;

   public:
    Employee(std::string name, std::string department, double salary)
        : name(name), department(department), salary(salary) {}

    void increaseSalary() { salary *= 1.1; }

    std::string getName() const { return name; }
    std::string getDepartment() const { return department; }
    double getSalary() const { return salary; }
};

int main() {
    Employee employees[4] = {Employee("John Doe", "HR", 50000),
                             Employee("Alice Smith", "Finance", 60000),
                             Employee("Bob Johnson", "IT", 55000),
                             Employee("Emily Brown", "Marketing", 52000)};

    for(int i = 0; i < 4; ++i) {
        employees[i].increaseSalary();
    }

    std::cout << "Updated salaries after increasing by 10%:\n";
    for(int i = 0; i < 4; ++i) {
        std::cout << "Employee: " << employees[i].getName()
                  << ", Department: " << employees[i].getDepartment()
                  << ", Salary: " << employees[i].getSalary() << std::endl;
    }

    return 0;
}
