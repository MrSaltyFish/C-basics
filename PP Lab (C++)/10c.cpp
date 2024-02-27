// Anvesh Khode
// 10c - Write a program to create inline functions for the arithmetic
// operations within the class definition. The function defitnition
// must be outside the class definition




#include <iostream>
using namespace std;

class example
{
public:
    int add(int a, int b);
    int sub(int a, int b);
};
inline int example::add(int a, int b)
{
    int c = a + b;
    cout << a << " + " << b << " = " << c << endl;
}
inline int example::sub(int a, int b)
{
    int c = a - b;
    cout << a << " - " << b << " = " << c << endl;
}
int main()
{
    example a1;
    a1.add(2, 3);
    a1.sub(2, 3);
}