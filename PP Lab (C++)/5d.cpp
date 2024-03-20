// Anvesh Khode
// 5d - Create a constructor to initialise the
// length and breadth of the rectangle and calculate
// the area and perimeter of the rectangle
// to display the result.

#include <iostream>

class Rectangle {
   private:
    double length;
    double breadth;

   public:
    Rectangle(double l, double b) : length(l), breadth(b) {}

    double calculateArea() const { return length * breadth; }

    double calculatePerimeter() const { return 2 * (length + breadth); }

    void displayResults() const {
        std::cout << "Rectangle with length " << length << " and breadth "
                  << breadth << ":\n";
        std::cout << "Area: " << calculateArea() << std::endl;
        std::cout << "Perimeter: " << calculatePerimeter() << std::endl;
    }
};

int main() {
    double length, breadth;

    std::cout << "Enter length of the rectangle: ";
    std::cin >> length;
    std::cout << "Enter breadth of the rectangle: ";
    std::cin >> breadth;

    Rectangle rect(length, breadth);

    rect.displayResults();

    return 0;
}
