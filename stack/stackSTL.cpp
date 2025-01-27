#include<iostream>
using namespace std;
//stack as an array implementation 
//----------------------complete tommorow-------------
class Stack{
    public:
    int size;
    int *arr;
    int top;

    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element){
        //size - top if there is space left then 
        if(size - top > 1){
            top++;
            top = element;
        }else{
            //means stack is empty with top value -1
            cout<<"stack is underflow "<<endl;
        }
    }

    void pop(){
        if(top == -1){
            cout<<"stack is empty "<<endl;
        }else{
            top--;
            peek();
        }
    }

    int peek(){
        if(size - top > 1){
            return arr[top];
        }else{
            //if stack is empty return -1;
            return -1;
        }
    }

    int isEmpty(int arr*){
        
    }
};


int main(){
    //created stack size of the st
    stack st(5);

    st.push(4);
    st.push(5);
    st.push(9);

    cout<<st.peek()<<endl;
}