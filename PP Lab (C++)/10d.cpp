// Anvesh Khode
// 10d - WAP in C++ to demonstrate virtual functions.

#include <iostream>
using namespace std;
class base
{
public:
    virtual void print()
    {
        cout << "This is Base class funtion";
    }
    void display()
    {
        cout << "This is not a virtual funtion of base class\n";
    }
};

class derived : public base
{
public:
    void print()
    {
        cout << "This is derived class Funtion\n";
    }
    void display()
    {
        cout << "This is not a virtual funtion of derived\n";
    }
};

int main()
{
    base *bptr;
    derived d;
    bptr = &d;
    bptr->print();
    bptr->display();

    return 0;
}