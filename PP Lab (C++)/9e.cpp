// Anvesh Khode
// 9e - Create a class named shape with a function that prints "This is
// shape". Create another class named Polygon inheriting the class Shape,
// printing "Polygon is a shape" in the same method. Create two other classes
// named Rectangle and Triangle having same function for printing "Rectangle is
// a polygon" and "Triangle is a polygon" respectively. Try calling the
// functions of these classes using the object of only one class.

#include <iostream>
using namespace std;

class Shape {
   public:
    void printShape() { cout << "This is shape" << endl; }
};

class Polygon : public Shape {
   public:
    void printPolygon() { cout << "Polygon is a shape" << endl; }
};

class Rectangle : public Polygon {
   public:
    void printRectangle() { cout << "Rectangle is a polygon" << endl; }
};

class Triangle : public Polygon {
   public:
    void printTriangle() { cout << "Triangle is a polygon" << endl; }
};

int main() {
    Rectangle rectangle;
    rectangle.printShape();
    rectangle.printPolygon();
    rectangle.printRectangle();

    Triangle triangle;
    triangle.printShape();
    triangle.printPolygon();
    triangle.printTriangle();

    return 0;
}
