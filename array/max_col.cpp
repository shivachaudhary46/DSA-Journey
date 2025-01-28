#include<iostream>
using namespace std;
int max_col(int nums[][3], int row , int col){
    int max=INT_MIN;
    for(int i=0; i<col; i++{
        int sum=0;
        for(int j=0; j<row; j++){
            sum+=nums[i][j];
        }
        if(max<sum){
            max=sum;
        }
    }
    return max;
}
int print(int nums[][3], int row, int col){
    for(int i=0; i<col; i++){
        for(int j=0; j<row; j++){
            cout<<nums[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int nums[3][4];
    
} 