// Anvesh Khode
// 4d - Create a class car if the car model and milage of
// the car is given as input, find the car

#include <iostream>
#include <string>

class Car {
   private:
    std::string model;
    double mileage;

   public:
    Car(std::string model, double mileage) : model(model), mileage(mileage) {}

    std::string getModel() const { return model; }
    double getMileage() const { return mileage; }
};

int main() {
    Car cars[7] = {Car("Toyota", 20.5),    Car("Honda", 18.2),
                   Car("Ford", 22.3),      Car("Chevrolet", 19.8),
                   Car("Hyundai", 21.7),   Car("Nissan", 20.9),
                   Car("Volkswagen", 23.1)};

    double maxMileage = cars[0].getMileage();
    std::string maxMileageModel = cars[0].getModel();

    for(int i = 1; i < 7; ++i) {
        if(cars[i].getMileage() > maxMileage) {
            maxMileage = cars[i].getMileage();
            maxMileageModel = cars[i].getModel();
        }
    }

    std::cout << "Car with the highest mileage: " << maxMileageModel << " ("
              << maxMileage << " kmpl)"
              << "\n";
    return 0;
}
