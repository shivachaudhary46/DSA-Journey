/*first and last position of element in sorted array -> 0123333333367 first=3, last=10*/
#include<iostream>
#include<vector>
#include<utility>
using namespace std;
int firstOccur(vector<int> &nums, int n, int k){
	int l=0, h=n-1;
	int mid = l+(h-l)/2;
	int ans = -1;
	while(l<=h){
		if(nums[mid] == k){
			ans = mid;
			h = mid-1;
		}else if(nums[mid] > k){
			h = mid-1;
		}else if(nums[mid]<k){
			l = mid+1;
		}
		mid = l+(h-l)/2;
	} 
	return ans;                       
}
int lastOccur(vector<int> &nums, int n, int k){
	int l=0, h=n-1;
	int mid = l+(h-l)/2;
	int ans = -1;
	while(l<=h){
		if(nums[mid] == k){
			ans = mid;
			l = mid + 1;
		}else if(nums[mid] > k){
			h = mid-1;
		}else if(nums[mid]<k){
			l = mid+1;
		}
		mid = l+(h-l)/2;
	} 
	return ans;
}
pair<int, int> firstAndLastPosition(vector<int> &nums, int n, int k){
	pair<int, int> p;
	p.first = firstOccur(nums, 10, 3);
	p.second = lastOccur(nums, 10, 3);
	return p;
}
void printing(pair<int, int> list){
	cout<<list.first<<endl;
	cout<<list.second<<endl;
}

int main(){
	pair<int, int> result;
	vector<int> nums;
	int key;
	cout<<"enter the key: ";
	cin>>key;
	cout<<"enter 10 numbers: ";
	for(int k=0; k<10; k++){
		cin>>k;
		nums.push_back(k);
	}
	result = firstAndLastPosition(nums, 10, key);
	printing(result);
}
