// Anvesh Khode
// 3e - assign and print the roll number, phone number and address
// of two student having names Sam and John
// resp. by creating two object of the class Student.

#include <iostream>

class Student {
   public:
    std::string name;
    int rollNo;
    unsigned long long int phoneNumber;
    std::string address;

    Student(std::string nameStr, int rollInt, unsigned long long int phoneNum,
            std::string addr)
        : name(nameStr),
          rollNo(rollInt),
          phoneNumber(phoneNum),
          address(addr) {}

    void printData() {
        std::cout << "Name: " << name << "\n";
        std::cout << "Roll Number: " << rollNo << "\n";
        std::cout << "Phone Number: " << phoneNumber << "\n";
        std::cout << "Address: " << address << "\n\n";
    }
};

int main() {
    Student student1("Sam", 1, 9576432891,
                     "22/1, Connaught Place, New Delhi, 110001");
    Student student2("John", 2, 7463728190,
                     "123, Lajpat Nagar, New Delhi, 110024");
    student1.printData();
    student2.printData();
    return 0;
}
