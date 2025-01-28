#include<iostream>
using namespace std;
void merge(int nums1[], int m, int nums2[], int n, int nums3[]){
    int i=0, j=0, k=0;
    while(i<m && j<n){
        if(nums1[i]<nums2[j]){
            nums3[k++] = nums1[i++];
        }else{
            nums3[k++] = nums2[j++];
        }
    }

    /*copying remaining spaces for the nums1*/
    while(i<m){
        nums3[k++] = nums1[i++];
    }

    /*copying remaining spaces for the nums2 */
    while(j<n){
        nums3[k++] = nums2[j++];
    }
} 
void print(int nums[], int n){
    for(int i=0; i<n; i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int nums1[5] = {2, 4, 6, 8, 10};
    int nums2[8] = {1, 3, 5, 7, 9, 11, 13, 15};
    int nums3[8+5];

    merge(nums1, 5, nums2, 8, nums3);
    print(nums3, 8+5);
}