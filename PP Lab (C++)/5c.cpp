// Anvesh Khode
// 5c - Create a constructor student calculate the total marks
// of 5 students in 5 subjects and

#include <iostream>

using namespace std;

class Student {
public:
  string name;
  int marks[5];

  Student(string name, int marks[5]) {
    this->name = name;
    for (int i = 0; i < 5; i++) {
      this->marks[i] = marks[i];
    }
  }

  int calculateTotalMarks() {
    int totalMarks = 0;
    for (int i = 0; i < 5; i++) {
      totalMarks += marks[i];
    }
    return totalMarks;
  }
};

Student findStudentWithLeastTotalMarks(Student students[5]) {
  int leastTotalMarks = students[0].calculateTotalMarks();
  Student studentWithLeastTotalMarks = students[0];
  for (int i = 1; i < 5; i++) {
    int currentTotalMarks = students[i].calculateTotalMarks();
    if (currentTotalMarks < leastTotalMarks) {
      leastTotalMarks = currentTotalMarks;
      studentWithLeastTotalMarks = students[i];
    }
  }
  return studentWithLeastTotalMarks;
}

int main() {
  Student students[5];

  students[0] = Student("Alice", {90, 80, 70, 60, 50});
  students[1] = Student("Bob", {80, 70, 60, 50, 40});
  students[2] = Student("Charlie", {70, 60, 50, 40, 30});
  students[3] = Student("Daisy", {60, 50, 40, 30, 20});
  students[4] = Student("Eve", {50, 40, 30, 20, 10});

  Student studentWithLeastTotalMarks = findStudentWithLeastTotalMarks(students);

  cout << "The student with the least total marks is " << studentWithLeastTotalMarks.name << " with " << studentWithLeastTotalMarks.calculateTotalMarks() << " marks." << endl;

  return 0;
}