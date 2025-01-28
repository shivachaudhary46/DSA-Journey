#include<iostream>
using namespace std;
int max_row(int arr[][4], int row, int col){
    int max=INT_MIN;
    for(int i=0; i<row; i++){
        int sum=0;
        for(int j=0; j<col; j++){
            sum=sum+arr[i][j];
        }
        if(max<sum){
            max=sum;
        }
    }

    return max;
}
void print(int nums[][4], int row, int col){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<nums[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int nums[3][4];
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            cout<<"enter * ";
            cin>>nums[i][j];
        }
    }
    print(nums, 3, 4);
    cout<<max_row(nums, 3, 4);
}