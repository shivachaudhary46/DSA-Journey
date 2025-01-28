#include<iostream>
using namespace std;
void maximum_rowArray(int arr[][3], int row, int col){
    for(int i=0; i<row; i++){
        int sum=0;
        for(int j=0; j<col; j++){
            sum+=arr[i][j];
        }
        cout<<"sum: "<<sum<<endl;
    }
}
void print_array(int arr[][3], int row, int col){
    cout<<"printing the array* "<<endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<3; j++){in
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int arr[2][3];
    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            cout<<"enter the "<<i<<j<<" ";
            cin>>arr[i][j]; 
        }
    }
    print_array(arr, 2, 3);
    maximum_rowArray(arr, 2, 3);
}