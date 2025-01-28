#include<iostream>
#include<stack>
using namespace std;

/*-----------pop function is mal functionigng ----
 ----so not working -----------*/

//reverse an stack  
class Stack{

    public:
    char top;
    int size;
    char *arr;

    //constructor to initialize stack
    Stack(int size){
        this->size = size;1
        arr = new char[size];
        top = -1;
    }

    //push operation in the stack 
    //why should we show stack is overflow in the stack??
    //because in push function will not push element if top of the 
    //stack is equal to size of the stack
    void push(char element){
        if(size - top > 1){
            top++;
            arr[top] = element;
        }else{
            cout<<"stack is overflow "<<endl;
        }
    }

    //where pop function removes element in the stack 
    void pop(){
        if(top >= 0){
            top--;
        }else{
            cout<<"stack is underflow "<<endl;
        }
    }

    //return the top of the stack if the stack of the top is less 
    //than the size 
    int peek(){
        if(top >= 0){
            return arr[top];
        }else{
            return -1;
        }
    }
    

};
int main(){
    string name = "shiva";
    int size = name.size();
    Stack copySt(size);
    for(int i=0; i<size; i++){
        copySt.push(name[i]);
    }

    //
    Stack reverseSt(size);

    for(int i=0; i<size; i++){
        char element  = copySt.peek();
        copySt.pop();
        reverseSt.push(element);
    }

    cout<< reverseSt.peek()<<endl;
}