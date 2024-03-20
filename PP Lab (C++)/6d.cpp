// Anvesh
// 6d - Define a copy constructor for 'Car' class that performs
// the copy of the data members 'brand' and 'yrs'.
#include <iostream>
#include <string>

class Car {
   private:
    std::string brand;
    int yrs;

   public:
    Car(std::string b, int y) : brand(b), yrs(y) {}

    Car(const Car& other) {
        brand = other.brand;
        yrs = other.yrs;
    }

    void displayDetails() const {
        std::cout << "Brand: " << brand << ", Years: " << yrs << std::endl;
    }
};

int main() {
    Car car1("Toyota", 5);
    Car car2 = car1;

    std::cout << "Details of Car 1:\n";
    car1.displayDetails();
    std::cout << "Details of Car 2 (copied from Car 1):\n";
    car2.displayDetails();
    return 0;
}
