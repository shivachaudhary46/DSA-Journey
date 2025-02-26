#include<iostream>
using namespace std;
int main(){
    for(int i=0; i<4; i++){
        int space = 4-i;

        while(space){
            cout<<" ";
            space = space - 1;
        }

        for(int j=0; j<=i; j++){
            cout<<"*";
        }

        for(int j=0; j<i; j++){
            cout<<"*";
        }

        cout<<endl;
    }
}