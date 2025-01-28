//bubble sort algorithm 
#include<iostream>
#include<vector>
using namespace std;
void bubbleSort(vector<int>& nums){
	int n=nums.size();
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(nums[j]>nums[j+1]){
				swap(nums[j], nums[j+1]);
			}
		}
	}
}
int main(){
	vector<int> nums;
	nums.push_back(6);
	nums.push_back(9);
	nums.push_back(1);
	nums.push_back(4);
	nums.push_back(12);
	
	bubbleSort(nums);
	for(int i=0; i<nums.size(); i++){
		cout<<nums[i]<<" ";
	}
}
