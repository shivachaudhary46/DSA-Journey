#include<iostream>
using namespace std;
bool searchFind(int nums[][4], int target, int row, int col){
    int nums[row][col];
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(nums[i][j]==target){
                return true;
            }
        }
    }
    return false;
}
int main(){
    int nums[3][4];
    cout<<"enter the target number: ";
    int target;
    cin>>target;
    if(searchFind(nums, target, 3, 4)){
        cout<<"target is found"<<endl;
    }else{
        cout<<"target not found"<<endl;
    }
}