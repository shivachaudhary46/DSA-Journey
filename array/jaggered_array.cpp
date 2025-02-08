#include<iostream>
using namespace std;
int main(){
    //examples of the jaggered array 

    int row, col;//declaaring row and col
    row = 3;

     int sizes[] = {4, 3, 1}; //each row will have different no of codes 
     //pointer creation with 3*4+8bytes of the row 
     int **arr = new int* [row];

    //creating array for col with each sizes 
    for(int i=0; i<row; i++){
        *(arr+i) = new int[sizes[i]];
    }
    
    //taking input in jagged array 
    for(int i=0; i<row; i++){
        for(int j=0; j<sizes[i]; j++){
            cin>>arr[i][j];
        }
    }
    
    //printing jagged array
    cout<<"printing the jaggered array "<<endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<sizes[i]; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    //dealloacating memory
    for(int i=0; i<row; i++){

        delete[] arr[i]; //free each row
    }

    delete[] arr;//free each pointers 
}