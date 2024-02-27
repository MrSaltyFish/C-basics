// Anvesh Khode
// 9g - 9 g Implement hierarchical inheritance derived rectangle and triangle from the shape class compute the

#include <iostream>
using namespace std;

class Shape {
public:
    double calculateArea() {
        return 0.0;
    }
};

class Rectangle : public Shape {
protected:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double calculateArea() {
        return length * width;
    }
};

class Triangle : public Shape {
protected:
    double base;
    double height;

public:
    Triangle(double b, double h) : base(b), height(h) {}

    double calculateArea() {
        return 0.5 * base * height;
    }
};

int main() {
    Rectangle rect(4.0, 5.0);
    Triangle tri(3.0, 4.0);

    cout << "Area of Rectangle: " << rect.calculateArea() << endl;
    cout << "Area of Triangle: " << tri.calculateArea() << endl;

    return 0;
} 
