//linear search 
#include<iostream>
using namespace std;
bool search(int arr[], int size, int key){
	//brute force or linear search or greedy approch
	for(int i=0; i<size; i++){
		if(arr[i] == key){
			return true;
		}
	}
	return false;
}
int main(){
	int n;
	cout<<"enter the key: ";
	cin>>n;
	int num[10] = {-2, 6, 1, 13, 7, 5, 24, 75, 3, 5};
	(search(num, sizeof(num)/sizeof(num[0]), n))?cout<<"key is present "<<n
	<<endl:cout<<"key is absent "<<n<<endl;
	
}	

