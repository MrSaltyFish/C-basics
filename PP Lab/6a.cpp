// Anvesh Khode
// 6a - 6. a) Create a parameterized constructor addition
// to perform the addition of three float

#include <iostream>

using namespace std;

class Addition {
private:
  float a;
  float b;
  float c;

public:
  Addition(float a, float b, float c) : a(a), b(b), c(c) {}

  float add() {
    return a + b + c;
  }
};

int main() {
  Addition addition1(1.0f, 2.0f, 3.0f);
  Addition addition2(4.0f, 5.0f, 6.0f);

  cout << "Addition result for the first set of values: " << addition1.add() << endl;
  cout << "Addition result for the second set of values: " << addition2.add() << endl;

  return 0;
}
