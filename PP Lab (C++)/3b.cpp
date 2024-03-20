// Anvesh Khode
// 3b - WAP to calculate the area of Circle, Square,
// Rectangle using Classes and objects.

#include <iostream>

class Shape {
   public:
    virtual double area() = 0;
};

class Circle : public Shape {
   private:
    double radius;

   public:
    Circle(double radius) : radius(radius) {}
    double area() override { return 3.14 * radius * radius; }
};

class Square : public Shape {
   private:
    double sideLength;

   public:
    Square(double sideLength) : sideLength(sideLength) {}
    double area() override { return sideLength * sideLength; }
};

class Rectangle : public Shape {
   private:
    double length;
    double width;

   public:
    Rectangle(double length, double width) : length(length), width(width) {}
    double area() override { return length * width; }
};

int main() {
    Circle circle(5);
    double circleArea = circle.area();
    std::cout << "The area of the circle is: " << circleArea << "\n";

    Square square(10);
    double squareArea = square.area();
    std::cout << "The area of the square is: " << squareArea << "\n";

    Rectangle rectangle(20, 30);
    double rectangleArea = rectangle.area();
    std::cout << "The area of the rectangle is: " << rectangleArea << "\n";

    return 0;
}
