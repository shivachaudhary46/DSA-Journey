#include<iostream>
using namespace std;
int getPivot(int nums[], int n){
    int s = 0;
    int e = n - 1;

    int mid = s+(e-s)/2;

    while(s<e){
        if(nums[0] < nums[mid] ){
            s = mid+1;
        }else if(nums[0] > nums[mid]){
            e = mid -1;
        }

        mid = s+(e-s)/2;
    }
    return s;
}
int rotatedBinaryArray(int nums[], int target){
    int n = sizeof(nums)/sizeof(nums[0]);
    int s = getPivot(nums, n);
    int e = n-1;

    int mid = s+(e-s)/2;
    while(s<=e){

        if(nums[mid] == target){
            return mid;
        }

        if(nums[mid] > target){
            e=mid-1;
        }else{
            s=mid+1;
        }

        mid = s+(e-s)/2;
    }

    return -1;
}
int main(){
    int nums[] = {7, 8, 9, 1, 2, 3};
    int ans = rotatedBinaryArray(nums, 3);

    cout<<"binary search in rotated sorted array if target is 3 "<<ans<<endl;
}