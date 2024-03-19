// Anvesh Khode
// 3e - WAP that would print the information
// name,year of joining,salary and address of 3 employees
// by creating the class name employee

#include <iostream>

class Employee {
   public:
    std::string name;
    int yearOfJoining;
    int salary;
    std::string address;

    Employee(std::string nameStr, int yofJoin, int income, std::string addr)
        : name(nameStr),
          yearOfJoining(yofJoin),
          salary(income),
          address(addr) {}

    void printData() {
        std::cout << "Name: " << name << "\n";
        std::cout << "Year Of Joining: " << yearOfJoining << "\n";
        std::cout << "Salary: Rs. " << salary << "\n";
        std::cout << "Address: " << address << "\n\n";
    }
};

int main() {
    Employee student1("Sam", 1995, 86400,
                      "22/1, Connaught Place, New Delhi, 110001");
    Employee student2("John", 2005, 61200,
                      "123, Lajpat Nagar, New Delhi, 110024");
    Employee student3("Mitch", 2012, 45600,
                      "456, Karol Bagh, New Delhi, 110005");
    student1.printData();
    student2.printData();
    student3.printData();
    return 0;
}
