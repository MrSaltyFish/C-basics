// Anvesh Khode
// 6c - Demonstrate the implementation of the copy constructor in C++ for the
// 'Wall' class. Create an instance of the Wall class, initialize it with both
// dimensions and calculate its area. Create a new object 'wall2' that is a copy
// of the existing object 'wall1', and display the area of both walls.

#include <iostream>

class Wall {
   private:
    double length;
    double height;

   public:
    Wall(double l, double h) : length(l), height(h) {}

    Wall(const Wall& other) {
        length = other.length;
        height = other.height;
    }

    double calculateArea() const { return length * height; }

    void displayArea() const {
        std::cout << "Area of the wall: " << calculateArea() << " square units"
                  << std::endl;
    }
};

int main() {
    Wall wall1(10.5, 8.3);
    std::cout << "Wall 1 ";
    wall1.displayArea();

    Wall wall2 = wall1;
    std::cout << "Wall 2 (copy of Wall 1) ";
    wall2.displayArea();

    return 0;
}
