// Anvesh Khode
// 6f - 6. Create a copy constructor for
// copying student records like student roll no, name and grade

#include <iostream>

using namespace std;

class Student {
   private:
    int rollNo;
    string name;
    int grade;

   public:
    Student(int rollNo, string name, int grade)
        : rollNo(rollNo), name(name), grade(grade) {}

    Student(const Student& other)
        : rollNo(other.rollNo), name(other.name), grade(other.grade) {}

    void displayRecord() {
        cout << "Roll No: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Grade: " << grade << endl;
    }
};

int main() {
    Student student1(1, "Alice", 90);
    Student student2(student1);

    cout << "Student 1 record:" << endl;
    student1.displayRecord();
    cout << "Student 2 record:" << endl;
    student2.displayRecord();
    return 0;
}
