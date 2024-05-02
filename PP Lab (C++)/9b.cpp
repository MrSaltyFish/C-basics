// Anvesh Khode
// 9b - 9 b Define two classes, Shape and Area, and calculate the area of a
// shape with a given length and breadth using single inheritance.

#include <iostream>
using namespace std;

class Shape {
   protected:
    double length;
    double breadth;

   public:
    Shape(double l, double b) : length(l), breadth(b) {}
};

class Area : public Shape {
   public:
    Area(double l, double b) : Shape(l, b) {}
    double calculateArea() { return length * breadth; }
};

int main() {
    double length, breadth;

    cout << "Enter length: ";
    cin >> length;
    cout << "Enter breadth: ";
    cin >> breadth;

    Area shape(length, breadth);
    double area = shape.calculateArea();

    cout << "Area of the shape: " << area << endl;
    return 0;
}
