// Anvesh Khode
// 9c - WAP to demonstrate multilevel inheritance in which class University
// intializes university name and city. The derived class from University,
// College, gives the details about the college affiliated to the university.
// The next derived class from College, Student, give the information about the
// total number of student in the college.
#include <iostream>
using namespace std;

class University {
   protected:
    string universityName;
    string city;

   public:
    University(string& name, string& loc) : universityName(name), city(loc) {
        cout << "University: " << universityName << " located in " << city
             << endl;
    }
};

class College : public University {
   protected:
    string collegeName;

   public:
    College(string& uName, string& uCity, string& cName)
        : University(uName, uCity), collegeName(cName) {
        cout << "College: " << collegeName << " is affiliated with " << uName
             << endl;
    }
};

class Student : public College {
   protected:
    int totalStudents;

   public:
    Student(string& uName, string& uCity, string& cName, int students)
        : College(uName, uCity, cName), totalStudents(students) {
        cout << "Total Students in " << cName << " college: " << totalStudents
             << endl;
    }
};

int main() {
    string uniName = "Symbiosis University";
    string uniCity = "Nagpur";
    string colName = "Symbiosis Institute of Technology(SIT)";
    int numStudents = 500;

    Student studentInfo(uniName, uniCity, colName, numStudents);

    return 0;
}
