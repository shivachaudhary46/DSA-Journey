#include<iostream>
using namespace std;
vector<int> wavePrint(int nums[][4], int nrows, int ncols){
    vector<int> ans;
    for(int col=0; col<=ncols; col++){
        if(col&1){//odd number from bottom to top@ 
            for(int row=nrows-1; row>=0; row==){
                ans.push_back(nums[row][col]);
            }

        }else{
            for(int row=0; row<nrows; row++){
                ans.push_back(nums[row][col]);
            }
        }
    }
}
int main(){
    int nums[4][6];
    for(int i=0; i<4; i++){
        for(int j=0; j<6;  j++){
            cout<<"enter* "<<i<<j<<" ";
            cin>>nums[i][j];
        }
    }
    
}