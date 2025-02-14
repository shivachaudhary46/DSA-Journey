/*pure aggresive cows*/
#include<iostream>
using namespace std;
bool checkDistance(int nums[], int n, int k, int mid){
	int lastpos = nums[0], cowCount=1;
	for(int i=0; i<n; i++){
		if(nums[i]-lastpos>=mid){
			cowCount++;
			if(cowCount==k){
				return true;
			}
			lastpos=nums[i];
		}
		
	}
	return false;
}
int findMaximumDist(int nums[], int n, int k){
	int maxi=-1, s=0;
	for(int i=0; i<n; i++){
		maxi=max(maxi, nums[i]);
	}
	int e=maxi;
	int mid=s+(e-s)/2;
	while(s<=e){
		if(checkDistance(nums, n, k, mid)){
			s=mid+1;
		}else{
			e=mid-1;
		}
		mid=s+(e- s)/2;
	}
	return e;
}
int main(){
	int stalls[]={ 1,2,4,8,9};
	int n=sizeof(stalls)/sizeof(stalls[0]);
	int no_of_cows=3;
	cout<<findMaximumDist(stalls, n, no_of_cows);
}
