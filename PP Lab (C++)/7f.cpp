// Anvesh Khode
// 7f - create a class name 'Programming'. While creating a object of the class,
// if nothing is passed to it then the message 'i like programming languages'
// should be printed, if some string is passed to it then in place of
// 'programming languages', the string should be printed.

#include <iostream>

class programming {
   public:
    programming() { std::cout << "I like programming languages" << std::endl; }
    programming(char lang[8]) { std::cout << "I like " << lang << std::endl; }
};
int main() {
    programming p;
    programming p1("cats");
    return 0;
}