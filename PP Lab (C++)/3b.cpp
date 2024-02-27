// Anvesh Khode
// 3b - Write a program to calculate the area of Circle, Square, Rectangle using classes and objects.

#include <iostream>

using namespace std;

class Shape
{
public:
    virtual double area() = 0;
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double radius) : radius(radius) {}

    double area() override
    {
        return 3.14 * radius * radius;
    }
};

class Square : public Shape
{
private:
    double sideLength;

public:
    Square(double sideLength) : sideLength(sideLength) {}

    double area() override
    {
        return sideLength * sideLength;
    }
};

class Rectangle : public Shape
{
private:
    double length;
    double width;

public:
    Rectangle(double length, double width) : length(length), width(width) {}

    double area() override
    {
        return length * width;
    }
};

int main()
{
    Circle circle(5);

    double circleArea = circle.area();

    cout << "The area of the circle is: " << circleArea << endl;

    Square square(10);

    double squareArea = square.area();

    cout << "The area of the square is: " << squareArea << endl;

    Rectangle rectangle(20, 30);

    double rectangleArea = rectangle.area();

    cout << "The area of the rectangle is: " << rectangleArea << endl;

    return 0;
}
