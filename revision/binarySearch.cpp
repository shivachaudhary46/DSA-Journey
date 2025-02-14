#include<iostream>
using namespace std;
int getIndexFromBinarySearch(int nums[], int n, int target){
    int s = 0;
    int e = n-1;
    int mid = s+(e-s)/2;
    int ans = -1;

    while(s<=e){
        if(nums[mid] == target){
            ans = mid;
        }

        if(nums[mid] < target){
            s = mid + 1;
        }else{
            e = mid - 1;
        }

        mid = s+(e-s)/2;
    }

    return ans;

}
int main (){
    int nums[] = {1, 5, 9, 16, 34, 56, 78};
    int n = sizeof(nums)/sizeof(nums[0]);
    cout<<getIndexFromBinarySearch(nums, n, 1)<<endl;
    cout<<getIndexFromBinarySearch(nums, n, 67)<<endl;

 }