// Anvesh Khode
// 3c - Write a program to create a class “Shopping” and write member functions

#include <iostream>
using namespace std;
class fruit
{
public:
    int a1, m1, b1, o1;
    fruit()
    {
        cout << "enter no of apples: " << endl;
        cin >> a1;
        cout << "enter no of mangoes: " << endl;
        cin >> m1;
        cout << "enter no of bananas: " << endl;
        cin >> b1;
        cout << "enter no of oranges: " << endl;
        cin >> o1;
    }
};

class mango : virtual public fruit
{
public:
    int a2, m2, b2, o2;
    mango()
    {
        cout << "enter no of apples: " << endl;
        cin >> a2;
        cout << "enter no of mangoes: " << endl;
        cin >> m2;
        cout << "enter no of bananas: " << endl;
        cin >> b2;
        cout << "enter no of oranges: " << endl;
        cin >> o2;
    }
    int M = m1 + m2;
};

class apple : virtual public fruit, virtual public mango
{
public:
    int A = a1 + a2;
};

class basket : public apple, virtual public mango
{
public:
    int t = A + M + o1 + o2 + b1 + b2;
};
int main()
{
    basket B1;
    cout << "Apples=" << B1.A << "\nMangoes=" << B1.M << "\nBananas=" << B1.b1 + B1.b2 << "\nOranges=" << B1.o1 + B1.o2;
}