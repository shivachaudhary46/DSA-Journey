/*book allocation problem - advanced binary search  problrem*/
#include<iostream>
#include<algorithm>
using namespace std;
bool isPossible(int nums[], int n, int k, int mid){
	int sum=0, stuCount=1;
	
	//selection sorting algorithm to sort in ascending order
	for(int i=0; i<n-1; i++){
		int minIndex=0;
		for(int j=i+1; j<n; j++){
			if(nums[minIndex] < nums[j]) minIndex=j;
		}
		swap(nums[minIndex], nums[i]);
	}
	
	for(int i=0; i<n; i++){
		if(sum+nums[i]<=mid){
			sum=sum+nums[i];
		}else{
			stuCount++;
			if(stuCount>k || nums[i]>mid){
				return false;
			}
			sum=nums[i];
		}
	}
	return true;
}
int splitArray(int nums[], int n, int k){
	int s=0, total=0;
	for(int i=0; i<n; i++){
		total += nums[i];
	}
	int ans = -1;
	int e=total;
	int mid = s+(e-s)/2;
	while(s<e){
		if(isPossible(nums, n, k, mid)){
			ans=mid;
			e=mid-1;
		}else{
			s=mid+1;
		}
		mid = s+(e-s)/2;
	} 
	return ans;
}
int main(){
	int nums[5] = {7,2,5,10,8};
	cout<<splitArray(nums, 5, 2);
}
