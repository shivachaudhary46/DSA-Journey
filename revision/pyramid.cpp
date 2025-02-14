#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter the number : ";
    cin>>n;

    for(int row = 0; row < n; row++){

        int space = n-row;
        while(space){

            cout<<" ";
            space = space - 1;
        }

        //print the right angle trianglee 
        for(int col=0; col<=row; col++){
            cout<<"*";
        }

        //print the left triangle 
        for(int col=0; col<row; col++){
            cout<<"*";
        }

        cout<<endl;
    }
}