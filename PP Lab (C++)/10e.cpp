// Anvesh Khode
// 10e - WAP in C++ using friend class to find the sum of
// two private members of two different classes.

#include <iostream>
using namespace std;

class Test2;

class Test1 {
   private:
    int m;
    friend int add(Test1, Test2);

   public:
    Test1() : m(2) {}
};
class Test2 {
   private:
    int n;

    friend int add(Test1, Test2);

   public:
    Test2() : n(3){};
};

int add(Test1 a, Test2 b) {
    int sum = a.m + b.n;
    return sum;
}

int main() {
    Test1 t1;
    Test2 t2;
    int result = add(t1, t2);
    cout << "Sum is: " << result << endl;
    return 0;
}