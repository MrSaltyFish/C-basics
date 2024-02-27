// Anvesh Khode
// 7c - WAP to overload the constructor for
// initializing and displaying employee details

#include <iostream>
#include <string>
using namespace std;
class Employee {
public:
int employeeId;
string name;
string department;
string dateOfJoining;
double salary;
Employee(int id,string empName,string dept,string doj,double empSalary){
        employeeId=id;
        name=empName;
        department=dept;
        dateOfJoining=doj;
        salary=empSalary; }
    void displayDetails() {
        cout<<"Employee ID:"<<employeeId<<endl;
        cout<<"Name:"<<name<<endl;
        cout<<"Department:"<<department<<endl;
        cout<<"Date of Joining:"<<dateOfJoining<<endl;
        cout<<"Salary:"<<salary<<endl;
    }};
int main() {
    Employee emp1(101123,"Richa Zararia","HR","15/2/2020",55000.0);
    Employee emp2(102213,"Jasmine Sharma","Engineering","5/7/2019",60000.0);
    cout<<"Employee 1 details:"<<endl;
    emp1.displayDetails();
    cout<<"\nEmployee 2 details:"<<endl;
    emp2.displayDetails();
    return 0;}