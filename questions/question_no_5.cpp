#include<iostream>
using namespace std;
int main(){
	int n = 15;
	for(int i=0; i<=n; i+=2){
		cout<<i<<" ";
		if(i&1){
			continue;
		}
		i++;
	}
}
