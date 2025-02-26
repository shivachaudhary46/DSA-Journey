#include<iostream>
#include<vector>
using namespace std;
void bubbleSort(vector<int> &arr, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}
int main(){
    vector<int> arr;
    arr.push_back(5);
    arr.push_back(9);
    arr.push_back(3);
    arr.push_back(12);
    arr.push_back(1);

    bubbleSort(arr, arr.size());

    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}