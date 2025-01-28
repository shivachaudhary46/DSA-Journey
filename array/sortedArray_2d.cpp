#include<iostream>
using namespace std;
int main(){
    int matrix[2][4]={{89, 2, 1, 45}, {6, 19, 7, 5}};
    int max = INT_MIN;
    for(int i=0; i<2; i++){
        for(int j=0; j<4; j++){
            if(max<matrix[i][j]){
                max=matrix[i][j];
            }
        }
    }
    
}