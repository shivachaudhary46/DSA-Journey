#include<iostream>
using namespace std;

class Stack{

    public:
        int size;
        int *nums;
        int top;

        Stack(int size){
            this->size = size;
            nums = new int[size];
            top = -1;
        }

        void push(int data){
            if(top <= size - 1 ){
                top++;
                nums[top] = data;
            }else{
                cout<<"stack is overflow"<<endl;
            }
        }

        void pop(){
            if(top == -1){
                cout<<"stack is underflow"<<endl;
            }else{
                top--;
            }
        }

        int peek(){
            if(top == -1){
                return -1;
            }else{
                return nums[top];
            }
        }

        bool isFUll(){
            if(top == size - 1){
                return true;
            }else{
                return false;
            }
        }

        bool isEmpty(){
            if(top == -1){
                return true;
            }else{
                return false;
            }
        }
};
int main(){
    Stack s(5);

    s.push(6);
    s.push(-1);
    s.push(9);
    s.push(10);
    s.push(5);

    cout<<s.peek()<<endl;
    s.push(-11);
    cout<<s.peek()<<endl;
    s.push(10);
    cout<<s.peek()<<endl;
    s.push(105);
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl; 
    cout<<s.isEmpty()<<endl;
    cout<<s.isFUll()<<endl;
}