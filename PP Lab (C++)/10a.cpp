// Anvesh Khode
// 10a - WAP in C++ to implement static variable.

#include <iostream>
using namespace std;
class student {
   public:
    static int total;
    student() { total += 1; }
};
int student::total = 0;

int main() {
    student s1;
    cout << "no of student : " << s1.total << endl;
    student s2;
    cout << "no of student : " << s1.total << endl;
    return 0;
}