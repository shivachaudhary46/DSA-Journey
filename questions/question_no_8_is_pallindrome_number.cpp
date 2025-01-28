//pallindrome number 
#include<iostream>
using namespace std;
class isPallindrome{
	public:
	bool isPallin(int n) {
		int sum = 0;
		while(n!=0){
			int rem = n % 10;
			sum = (sum*10) + rem;
			n/=10;
		}
		if(n == sum){
			return true;
		}else{
			return false;
		}
	}
};
int main(){
	isPallindrome t1;
	if(t1.isPallin(121)){
		cout<<"121 is pallindrome number";
	}else{
		cout<<"121 is not pallindrome number";
	}
}
