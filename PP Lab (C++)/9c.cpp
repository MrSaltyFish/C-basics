// Anvesh Khode
// 9c - 9 c wap to demostrate multilevel inheritance in  which class university intialise university name and 

#include <iostream>
using namespace std;

class University {
protected:
    string universityName;
    string city;

public:
    University( string& name,  string& loc) : universityName(name), city(loc) {
        cout << "University: " << universityName << " located in " << city << endl;
    }
};

class College : public University {
protected:
    string collegeName;

public:
    College( string& uName,  string& uCity,  string& cName) : University(uName, uCity), collegeName(cName) {
        cout << "College: " << collegeName << " is affiliated with " << uName << endl;
    }
};

class Student : public College {
protected:
    int totalStudents;

public:
    Student( string& uName,  string& uCity,  string& cName, int students)
        : College(uName, uCity, cName), totalStudents(students) {
        cout << "Total Students in " << cName << " college: " << totalStudents << endl;
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
