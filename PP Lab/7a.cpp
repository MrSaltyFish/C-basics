// Anvesh Khode
// 7a - WAP to implement function overloading
// for addition of three different sets of values.

#include<iostream>
using namespace std;
class A{
	public:
		int addfunc(int a,int b,int c)
		{
			return a+b+c;
		}
		double addfunc(double d1,double d2,double d3){
			return d1+d2+d3;
		}
		float addfunc(float n1,float n2,float n3){
			return n1+n2+n3;
		}
};
int main(){
	A a1;
	cout<<"Sum of 7,8 and 4 is "<<a1.addfunc(7,8,4)<<endl;
	cout<<"Sum of 5.0,2.5 and 2.0 is "<<a1.addfunc(5.0,2.5,2.0)<<endl;
	cout<<"Sum of 4.5,6.7 and 2.1 is "<<a1.addfunc(4.5,6.7,2.1)<<endl;
	return 0;
}
