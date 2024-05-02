// Anvesh Khode
// 10a - WAP in C++ to implement static variable and static function.

#include <iostream>
using namespace std;

class Student {
   public:
    static int total;
    Student() { total += 1; }
    static void printTotal() {
        cout << "the value of total = " << total << endl;
    }
};
int Student::total = 0;

int main() {
    Student s1;
    Student::printTotal();
    Student s2;
    Student::printTotal();
    return 0;
}