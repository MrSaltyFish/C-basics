// Anvesh Khode
// 7b - Create a class named 'Programming'.
// While creating an object of the class,
//     if nothing is passed, print "i like programming languages"
//     else print "i like <parameter>"

#include<iostream>

using namespace std;
class programming{
	public:
	programming(){
	cout<<"I like programming languages"<<endl;
	}
	programming(char lang[8]){
		cout<<"I like "<<lang;
	}
};
int main(){
	programming p;
	programming p1("cats");
	return 0;
}