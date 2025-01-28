//pattern_17
#include<iostream>
using namespace std;
int main() {
	int row = 0, n;
	cout<<"enter the number : ";
	cin>>n;
	
	while(row <= n){
		int stars = n - row;
		while(stars) {
			cout<<"*";
			stars = stars - 1;
		}
		cout<<endl;
		row = row + 1;
	}
}
