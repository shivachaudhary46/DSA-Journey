//question binary to decimal 
#include<cmath>
#include<iostream>
using namespace std;
int main(){
	cout<<"enter the number: ";
	int n;
	cin>>n;
	
	int i = 0, ans = 0;
	while(n!=0){
		int rem = n % 10;
		if(rem == 1){
			ans = pow(2, i) + ans;
		}
		i++;
		n = n/10;
	}
	
	cout<<"answer is : "<<ans<<endl;
}
