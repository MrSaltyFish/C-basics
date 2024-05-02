// Anvesh Khode
// 4b - WAP to print the 'rollNo' and 'averageMarks' of
// 8 students in three subjects each out of 100.
// The 'marks' are entered by user, and the
// 'rollNo' is automatically assigned.

#include <iostream>

class Student {
   private:
    int rollNo;
    double marks[3];
    double averageMarks;

   public:
    static int rollCounter;

    Student() {
        rollNo = ++rollCounter;
        for(int i = 0; i < 3; ++i) {
            std::cout << "Subject " << i + 1 << " for student " << rollNo
                      << ": ";
            std::cin >> marks[i];
        }
        calculateAverage();
    }

    void calculateAverage() {
        double sum = 0;
        for(int i = 0; i < 3; ++i) {
            sum += marks[i];
        }
        averageMarks = sum / 3;
    }

    void displayDetails() {
        std::cout << "Roll No: " << rollNo
                  << ", Average Marks: " << averageMarks << std::endl;
    }
};

int Student::rollCounter = 0;

int main() {
    const int numStudents = 8;

    std::cout << "Enter marks for"
              << "\n";
    Student students[numStudents];
    std::cout << "\n";
    for(int i = 0; i < numStudents; ++i) {
        students[i].displayDetails();
    }

    return 0;
}
