#include<iostream>
using namespace std;
int main() {
	int a = 3, b = 2;
	if(a++ > 2 || b > 2) {
		cout<<"we are inside - if"<<endl;
	}else{
		cout<<"we are inside - else"<<endl;
	}
	cout<<"a : "<<a<<endl<<"b : "<<b<<endl;
}
