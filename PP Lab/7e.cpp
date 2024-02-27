// Anvesh Khode
// 7e - Suppose you have a piggy bank with an initial amount of $50
// and you have to add

#include<iostream>
using namespace std;
class addamount{
	public:
	int amount=50;
	addamount(){
		cout<<amount<<endl;
	}
	addamount(int add){
     amount=amount+add;
	 cout<<amount;
	}
};
int main(){
	addamount a;
	addamount a1(100);
	return 0;
}