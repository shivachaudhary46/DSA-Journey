#include<iostream>
using namespace std;
int getSum(int arr[], int size){

    //base case 
    if(size == 0){
        return false;
    }
    int ans = arr[0] + getSum(arr+1, size-1);
    return ans;
}
int main(){
    int arr[5] = {18, 2, 5, 13, 9};
    int ans = getSum(arr, 5);
    cout<<ans<<endl; 
}