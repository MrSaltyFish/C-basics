// Anvesh Khode
// 7d - vehicle ford TVS

#include <cstring>
#include <iostream>
using namespace std;

class Vehicle {
   public:
    float mileage;
    double price;
};
class cars : public Vehicle {
   public:
    double ownership_cost;
    int warranty;
    int sitting_capacity;
    string fuel_type;
};
class bikes : public Vehicle {
   public:
    int no_of_gears;
    int no_of_cylinder;
    string cooling_type;
    int fuel_tank_size;
    string wheel_type;
};
class Audi : public cars {
   public:
    string mode_type;
    Audi(float mileage, double price, double ownership_cost, int warranty,
         int sitting_capacity, string fuel_type) {
        this->mileage = mileage;
        this->price = price;
        this->ownership_cost = ownership_cost;
        this->warranty = warranty;
        this->sitting_capacity = sitting_capacity;
        this->fuel_type = fuel_type;
    }
    void display() {
        cout << "display details\t : " << endl
             << "Mileage\t : " << mileage << endl
             << "Price\t : " << price << endl
             << "Ownership cost\t : " << ownership_cost << endl;
        cout << "Warrenty\t : " << warranty << endl
             << "Sitting Capacity\t : " << sitting_capacity << endl
             << "Fule Type\t : " << fuel_type << endl;
    }
};
class ford : public cars {
   public:
    string mode_type;
    ford(float mileage, double price, double ownership_cost, int warranty,
         int sitting_capacity, string fuel_type) {
        this->mileage = mileage;
        this->price = price;
        this->ownership_cost = ownership_cost;
        this->warranty = warranty;
        this->sitting_capacity = sitting_capacity;
        this->fuel_type = fuel_type;
    }
    void display() {
        cout << "display details\t : " << endl
             << "Mileage\t : " << mileage << endl
             << "Price\t : " << price << endl
             << "Ownership cost\t : " << ownership_cost << endl;
        cout << "Warrenty\t : " << warranty << endl
             << "Sitting Capacity\t : " << sitting_capacity << endl
             << "Fule Type\t : " << fuel_type << endl;
    }
};
class Bajaj : public bikes {
   public:
    string make_type;
    Bajaj(float mileage, double price, int no_of_gears, int no_of_cylinder,
          string cooling_type, int fuel_tank_size, string make_type,
          string wheel_type) {
        this->mileage = mileage;
        this->price = price;
        this->no_of_cylinder = no_of_cylinder;
        this->no_of_gears = no_of_gears;
        this->cooling_type = cooling_type;
        this->fuel_tank_size = fuel_tank_size;
        this->make_type = make_type;
        this->wheel_type = wheel_type;
    }
    void display() {
        cout << "display details\t : " << endl
             << "Mileage\t : " << mileage << endl
             << "Price\t : " << price << endl
             << "Number of Gears\t : " << no_of_gears << endl;
        cout << "Cooling Type\t : " << cooling_type << endl
             << "Fule Tank Size\t : " << fuel_tank_size << endl
             << "Make Type\t : " << make_type << endl
             << "wheel Type\t : " << wheel_type << endl;
    }
};
class TVS : public bikes {
   public:
    string make_type;
    TVS(float mileage, double price, int no_of_gears, int no_of_cylinder,
        string cooling_type, int fuel_tank_size, string make_type,
        string wheel_type) {
        this->mileage = mileage;
        this->price = price;
        this->no_of_cylinder = no_of_cylinder;
        this->no_of_gears = no_of_gears;
        this->cooling_type = cooling_type;
        this->fuel_tank_size = fuel_tank_size;
        this->make_type = make_type;
        this->wheel_type = wheel_type;
    }
    void display() {
        cout << "display details\t : " << endl
             << "Mileage\t : " << mileage << endl
             << "Price\t : " << price << endl
             << "Number of Gears\t : " << no_of_gears << endl;
        cout << "Cooling Type\t : " << cooling_type << endl
             << "Fule Tank Size\t : " << fuel_tank_size << endl
             << "Make Type\t : " << make_type << endl
             << "wheel Type\t : " << wheel_type << endl;
    }
};
int main() {
    Audi audi(25, 5000000, 200000, 3, 5, "Petrol");
    audi.display();

    ford ford(20, 4000000, 180000, 2, 4, "Diesel");
    ford.display();

    Bajaj bajaj(50, 200000, 5, 2, "Air", 10, "Pulsar", "Spokes");
    bajaj.display();

    TVS tvs(45, 180000, 6, 1, "Liquid", 11, "Apache", "Alloys");
    tvs.display();

    return 0;
}