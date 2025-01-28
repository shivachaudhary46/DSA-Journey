#include<iostream>
using namespace std;
int main(){
	int i = 1, n = 3;
	while(i <= n){
		int j = 1;
		while(j <= n){
			cout<<n+j-i;
			j = j + 1;
		}
		cout<<endl;
		i = i + 1;
	}
}
