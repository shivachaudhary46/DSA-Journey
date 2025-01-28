#include<iostream>
using namespace std;
int main(){
	for(int i=1; i<=5; i++){
		for(int j=i; j<=5; j++){
			if(i+j == 4){
				break;
			}
			cout<<i<<" "<<j<<endl;
		}
	}
}
