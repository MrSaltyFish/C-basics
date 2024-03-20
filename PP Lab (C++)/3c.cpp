// Anvesh Khode
// 3c - Create a class named 'Shopping', and calculate the
// billing amount of three different sections in a store
// like 'grocery', 'electronic gadgets' and 'clothes'.

#include <iostream>

class Shopping {
   private:
    double groceryAmount;
    double electronicsAmount;
    double clothesAmount;

   public:
    Shopping() : groceryAmount(0), electronicsAmount(0), clothesAmount(0) {}

    void addGrocery(double amount) { groceryAmount += amount; }
    void addElectronics(double amount) { electronicsAmount += amount; }
    void addClothes(double amount) { clothesAmount += amount; }
    double calculateTotal() {
        return groceryAmount + electronicsAmount + clothesAmount;
    }
};

int main() {
    Shopping bill;
    float groceryInput, electronicsInput, clothesInput;

    std::cout << "Enter the amount for each category: \n";
    std::cout << "Grocery: ";
    std::cin >> groceryInput;
    std::cout << "Electronics: ";
    std::cin >> electronicsInput;
    std::cout << "Clothes: ";
    std::cin >> clothesInput;

    bill.addGrocery(groceryInput);
    bill.addElectronics(electronicsInput);
    bill.addClothes(clothesInput);

    double totalAmount = bill.calculateTotal();

    std::cout << "\nTotal Billing Amount: Rs." << totalAmount << std::endl;
    return 0;
}