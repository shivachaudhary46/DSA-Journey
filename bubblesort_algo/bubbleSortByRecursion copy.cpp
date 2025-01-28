#include<iostream>
using namespace std;
void bubbleSort(int arr[], int n){
    //base case; assume sort if the size of the array
    if(n==0 || n==1) return;

    //processing;
    for(int i=0; i<n-1; i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }
     
    //recursive relaation 
    bubbleSort(arr, n-1);
}
void print(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int nums[8] = {6, 2, 1, 8, 9, 0, 11, 34};
    int size = sizeof(nums)/sizeof(nums[0]);
    bubbleSort(nums, size);
    print(nums, size);

}