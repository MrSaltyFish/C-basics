// Anvesh Khode
// 5c - WAP to convert the temperature from fahrenheit to celsius using
// constructor take the value of temperture in fahrenheit from the user
// and display the converted temperature within another function

#include <iostream>

class TemperatureConverter {
   private:
    double fahrenheit;
    double celsius;

   public:
    TemperatureConverter(double f) : fahrenheit(f) {
        celsius = (fahrenheit - 32) * 5 / 9;
    }

    void displayConvertedTemperature() {
        std::cout << "Temperature in Fahrenheit: " << fahrenheit << "F\n";
        std::cout << "Temperature in Celsius: " << celsius << "C\n";
    }
};

int main() {
    double fahrenheitInput;

    std::cout << "Enter temperature in Fahrenheit: ";
    std::cin >> fahrenheitInput;

    TemperatureConverter converter(fahrenheitInput);
    converter.displayConvertedTemperature();
    return 0;
}
