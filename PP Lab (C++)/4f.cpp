// Anvesh Khode
// 4f - define class country with attributes name,population and area.
// create an array of 8 Country objects and calculate the
// population density [population by area for each country]

#include <iostream>
#include <string>

class Country {
   private:
    std::string name;
    double population;
    double area;

   public:
    Country(std::string name, double population, double area)
        : name(name), population(population), area(area) {}

    double calculatePopulationDensity() const { return population / area; }

    std::string getName() const { return name; }
    double getPopulation() const { return population; }
    double getArea() const { return area; }
};

int main() {
    Country countries[8] = {Country("USA", 331002651, 9833517),
                            Country("China", 1439323776, 9596961),
                            Country("India", 1380004385, 3287263),
                            Country("Russia", 145934462, 17098242),
                            Country("Brazil", 212559417, 8515767),
                            Country("Australia", 25499884, 7692024),
                            Country("Canada", 37742154, 9984670),
                            Country("Argentina", 45195777, 2780400)};

    std::cout << "Population density for each country:\n";
    for(int i = 0; i < 8; ++i) {
        double density = countries[i].calculatePopulationDensity();
        std::cout << "Country: " << countries[i].getName()
                  << ", Population Density: " << density << " people/sq km\n";
    }

    return 0;
}
