/*selection sort algorithm*/
#include<iostream>
using namespace std;
void selectionSort(int nums[], int n){
	for(int i=0; i<n-1; i++){
		int minIndex=i;
		for(int j=i+1; j<n; j++){
			if(nums[minIndex]>nums[j]){
				minIndex=j;
			}
		}
		swap(nums[minIndex], nums[i]);
	}
	cout<<endl;
	for(int i=0; i<n; i++){
		cout<<nums[i]<<" ";
	}
	cout<<endl;
}
int main(){
	int nums[]={9, 8, 7, 6, 5, 4, 3};
	int n=sizeof(nums)/sizeof(nums[0]);
	selectionSort(nums, n);
	
}
