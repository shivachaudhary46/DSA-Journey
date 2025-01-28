//decimal to binary  
#include<iostream>
#include<cmath>
using namespace std;
int main(){
	cout<<"enter the number : ";
	int n;
	cin>>n;
	int ans = 0, i=0;
	while(n!=0){
		int bit = n & 1;
		ans = bit * pow(10, i) + ans;
		n = n >> 1;
		i++;
	}
	cout<<"answer is : "<<ans<<endl<<n<<endl;
	/*aaba int negative ma aayo bhane k
	 garne ta 
	*/
	
	
}
