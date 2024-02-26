// Anvesh Khode
// 7d - WAP in C++ to overload the constructor for
// performing addition operations with

#include <iostream>
#include <string>
using namespace std;
class Student {
	public:
    string name;
    int age;
    string address;
    Student(){
        name="Unknown";
        address="Not Available";}
    void setInfo(string studentName, int studentAge){
        name=studentName;
        age=studentAge; }
    void setInfo(string studentName, int studentAge, string studentAddress){
        name=studentName;
        age=studentAge;
        address=studentAddress; }
    void displayInfo() {
        cout<<"Name:"<<name<<endl;
        cout<<"Age:"<<age<<endl;
        cout<<"Address:"<<address<<endl;
        cout<<endl;}};
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
    for (int i=0;i<10;++i) {
        cout<<"Student "<<i+1<<":"<<endl<<"Details:"<<endl;
        students[i].displayInfo();
    }
    return 0;
}