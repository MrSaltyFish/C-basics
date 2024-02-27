// Anvesh Khode
// 9h - 9 h wap in c++ to claculate the grocess salary of an employee by using the components basic DA,HRA and

#include <iostream>
using namespace std;

class Employee {
protected:
    double basic;
    double da;
    double hra;

public:
    Employee(double b, double d, double h) : basic(b), da(d), hra(h) {}

    virtual double calculateGrossSalary() {
        return basic + da + hra;
    }
};

class RegularEmployee : public Employee {
public:
    RegularEmployee(double b, double d, double h) : Employee(b, d, h) {}

    double calculateGrossSalary() override {
        return Employee::calculateGrossSalary();
    }
};

class BonusEmployee : public Employee {
public:
    BonusEmployee(double b, double d, double h) : Employee(b, d, h) {}

    double calculateGrossSalary() override {
        double bonus = 0.0;
        if (basic < 25000) {
            bonus = 0.10 * basic;
        } else {
            bonus = 0.15 * basic;
        }
        return Employee::calculateGrossSalary() + bonus;
    }
};

int main() {
    RegularEmployee regular(30000, 5000, 2000);
    BonusEmployee bonus(20000, 4000, 1500);

    cout << "Regular Employee's Gross Salary: " << regular.calculateGrossSalary() << endl;
    cout << "Bonus Employee's Gross Salary: " << bonus.calculateGrossSalary() << endl;

    return 0;
}
