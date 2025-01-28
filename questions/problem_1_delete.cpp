#include<iostream>
#include<vector>
using namespace std;
void mergeSort(vector<int> nums1, int m, vector<int> nums2, int n){
    int i=0, j=0;
    while(i<m && j<n){
        if(nums1[i]<nums2[j]){
            nums1[i++] = nums2[j++];
        }
    }
    while(i<m){
        nums1[i++] = nums2[j];
    }
}
void print(vector<int>& nums1){
    for(int i=0; i<nums1.size(); i++){
        cout<<nums1[i]<<" ";
    }
    cout<<endl;
}
int main(){
    /*nums1 has the length of m+n where first m elements denote the elements that should be merged */

    vector<int> nums1;
    vector<int> nums2;

    nums1.push_back(5);
    nums1.push_back(7);
    nums1.push_back(9);
    nums1.push_back(0);
    nums1.push_back(0);
    nums1.push_back(0);

    nums2.push_back(1);
    nums2.push_back(3);
    nums2.push_back(4);
    nums2.push_back(12);
    mergeSort(nums1, nums1.size(), nums2, nums2.size());
    print(nums1);

}
