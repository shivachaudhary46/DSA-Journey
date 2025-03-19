#include<iostream>
using namespace std;
class stack{
    public:
        int size;
        int *arr;
        int top;

        stack(int size){
            this->size = size;
            arr = new int[size];
            top = -1;
        }

        void push(int element){
            if(size - top > 1){
                top++;
                arr[top] = element;
            }
        }

        void pop(){
            if(top >= 1){
                top--;
            }else{
                cout<<"stack is underflow";
            }
        }
};
int main(){

}