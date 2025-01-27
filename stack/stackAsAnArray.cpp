#include<iostream>
using namespace std;
//stack as an array implementation 
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
            arr[top] = element;
        }else{
            //means stack is empty with top value -1
            cout<<"stack is underflow "<<endl;
        }
    }

    void pop(){
        if(top >= 1){
            top--;
        }else{
            cout<<"stack is underflow"<<endl;
        }
    }

    int peek(){
        if(top >= 1){
            return arr[top];
        }else{
            return -1;
        }
    }

    bool isEmpty(){
        if(top == -1){
            return 1;
        }else{
            return 0;
        }
    }
};


int main(){
    //created stack size of the st
    Stack st(5);

    st.push(4);
    st.push(5);
    st.push(9);

    cout<<st.peek()<<endl;

    st.pop();

    cout<<st.peek()<<endl;

    // st.pop();
    // st.pop();

    if(st.isEmpty()){
        cout<<"stack is empty"<<endl;
    }else{
        cout<<"stack is not empty"<<endl;
    }

    
}