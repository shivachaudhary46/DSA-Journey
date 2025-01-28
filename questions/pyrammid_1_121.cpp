#include<iostream>
using namespace std;
int main(){
	int n, row, col, start;
	cout<<"enter the number n: ";
	cin>>n;
	int space = n - row;
	while(space){
		cout<<" ";
		space = space - 1;
		
		while(row <= n){
			cout<<col;
			col = col + 1;
			start = row - 1;
			
			while(col <= row){
				cout<<start;
				start = start + 1;
			}
		cout<<endl;
		row = row + 1;
		}
	}
	
	
		
	
}
