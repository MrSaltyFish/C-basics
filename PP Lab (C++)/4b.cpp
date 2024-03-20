// Anvesh Khode
// 4b - WAP to print the roll no.and average marks of
// 8 students in three subjects each out of 100.
// The marks  are entered by user and
// the roll nos. are automatically assigned.

#include <iostream>

class Student {
   private:
    int rollNo;
    double marks[3];
    double average;

   public:
    static int rollCounter;

    Student() {
        rollNo = ++rollCounter;
        for(int i = 0; i < 3; ++i) {
            std::cout << "Enter marks for subject " << i + 1 << " for student "
                      << rollNo << ": ";
            std::cin >> marks[i];
        }
        calculateAverage();
    }

    void calculateAverage() {
        double sum = 0;
        for(int i = 0; i < 3; ++i) {
            sum += marks[i];
        }
        average = sum / 3;
    }

    void displayDetails() {
        std::cout << "Roll No: " << rollNo << ", Average Marks: " << average
                  << std::endl;
    }
};

int Student::rollCounter = 0;

int main() {
    const int numStudents = 8;
    Student students[numStudents];
    std::cout << "\n";
    for(int i = 0; i < numStudents; ++i) {
        students[i].displayDetails();
    }

    return 0;
}
