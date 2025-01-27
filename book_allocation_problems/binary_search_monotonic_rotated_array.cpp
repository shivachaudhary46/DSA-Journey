#include<iostream>
#include<vector>
using namespace std;
int getPivot(int nums[], int start, int end){
        int s = start;
        int e = end;
        int mid = s+(e-s)/2;
        while(s<e){
            if(nums[mid]>=nums[0]){
                s = mid+1;
            }else{
                e = mid;
            }
            mid = s+(e-s)/2;
        }
        return s;
    }
    int binarySearch(int nums[], int start, int end, int target){
        int s=start;
        int e=end;
        int mid=s+(e-s)/2;
        while(s<=e){
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] > target){
                e = mid -1;
            }else{
                s =mid+1;
            }
            mid = s+(e-s)/2;
        }
    }
    int search(int nums[], int target) {
        int n = sizeof(nums)/sizeof(nums[0]);
        int pivot = getPivot(nums, 0, n-1);
        if(nums[pivot] <= target && nums[n-1]>=target){
            return binarySearch(nums, pivot, n-1, target);
        }else{
            return binarySearch(nums, 0, pivot-1, target);
        }
        return -1;
    }
int main(){
	int nums[7] = {4,5,6,7,0,1,2};
	int target = 0;
	int n = sizeof(nums)/sizeof(nums[0]);
	int ans = search(nums, 1);
	cout<<"answer : "<<ans<<endl;
	int pivot = getPivot(nums, 0, 6);
	cout<<"pivot = "<<pivot<<endl;
	int binary1 = binarySearch(nums, pivot, n-1, target);
	int binary2 = binarySearch(nums, 0, pivot-1, target);
	cout<<"1 = "<<binary1<<" 2 = "<<binary2<<endl;
}



