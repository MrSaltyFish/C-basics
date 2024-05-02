// Anvesh Khode
// 10d - WAP in C++ to find the greater number between the two numbers
// who are private members of two different classes using friend class
// implementation and display the result.

#include <iostream>
using namespace std;

class Two;

class One {
   private:
    int num1;

    friend int isGreater(One o1, Two o2);

   public:
    One() : num1(5) {}
};

class Two {
   private:
    int num2;

    friend int isGreater(One o1, Two o2);

   public:
    Two() : num2(3) {}
};

int isGreater(One o1, Two o2) {
    if(o1.num1 > o2.num2) {
        cout << o1.num1 << " is greater than " << o2.num2 << endl;
    } else {
        cout << o2.num2 << " is greater than " << o1.num1 << endl;
    }
}

int main() {
    One obj1;
    Two obj2;
    isGreater(obj1, obj2);
    return 0;
}