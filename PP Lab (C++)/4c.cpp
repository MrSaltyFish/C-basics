// Anvesh Khode
// 4c - WAP to calculate the average height of all
// students of the class, and also find the number of students.
// The student's names and their heights are to be
// entered by the user. Use array of objects.

#include <iostream>
using namespace std;

class Student {
   public:
    string name;
    int height;
};

int main() {
    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;
    Student students[numStudents];

    for(int i = 0; i < numStudents; i++) {
        cout << "Enter the name and height (in cm) of student " << i + 1
             << ": ";
        cin >> students[i].name >> students[i].height;
    }

    int totalHeight = 0;
    for(int i = 0; i < numStudents; i++) {
        totalHeight += students[i].height;
    }
    double averageHeight = totalHeight / numStudents;

    cout << "The average height of all the students is " << averageHeight
         << " cm."
         << "\n";

    return 0;
}
