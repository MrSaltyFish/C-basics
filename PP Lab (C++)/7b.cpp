// Anvesh Khode
// 7b - WAP to implement method overloading to find the area of
// different shapes like rectangle, circle and square.

#include <iostream>
using namespace std;
class A {
   public:
    double area(double l, double b) { return l * b; }
    int area(int s) { return s * s; }
    double area(double r) { return 3.14 * r * r; }
};
int main() {
    A a1;
    cout << "Area of rectangle:" << a1.area(4, 5) << endl;
    cout << "Area of circle:" << a1.area(2.0) << endl;
    cout << "Area of square:" << a1.area(5) << endl;
    return 0;
}