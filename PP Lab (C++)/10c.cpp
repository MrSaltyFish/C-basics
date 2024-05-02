// Anvesh Khode
// 10c - WAP in C++ to demonstrate virtual functions.

#include <iostream>
using namespace std;
class Base {
   public:
    virtual void print() { cout << "This is Base class funtion"; }
    void display() { cout << "This is not a virtual funtion of Base class\n"; }
};

class Derived : public Base {
   public:
    void print() { cout << "This is Derived class Funtion\n"; }
    void display() { cout << "This is not a virtual funtion of Derived\n"; }
};

int main() {
    Base *bptr;
    Derived d;

    bptr = &d;
    bptr->print();
    bptr->display();

    return 0;
}