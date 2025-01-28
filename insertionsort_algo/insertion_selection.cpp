#include<iostream>
using namespace std;
void insertionSelect(int nums[], int n){
	for(int i=1; i<n; i++){
 		int j=i-1;
		int temp=nums[i];
		while(j>=0){
			if(nums[j]>temp){
				nums[j+1]=nums[j];
			}else{
				break;
			}
			j--;
		}
		nums[j+1]=temp;
	}
}
void printing(int nums[], int n){
	for(int i=0; i<n; i++){
		cout<<nums[i]<<" ";
	}
}
int main(){
	int nums[8]={4, 3, 2, 1, 10, 7, 23, 90};
	insertionSelect(nums, 8);
	printing(nums, 8);
}
