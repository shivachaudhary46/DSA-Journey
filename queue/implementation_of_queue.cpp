#include<iostream>
using namespace std;
class Queue{
    public:
    int size;
    int *nums;
    int front;
    int back;

    Queue(int size){
        this->size = size;
        nums = new int[size];
        front = -1;
        back = -1;
    }

    ~Queue(){
        delete[] nums; 
    }

    void push_back(int element){
        if(back == size-1){
            cout<<"queue is overflowed"<<endl;
        }

        if(front == -1){
            front = 0;
        }
        else{
            back++;
            nums[back] = element;
        }
    }

    void pop(){
        if(front == -1 || front > back){
            cout<<"queue is underflow"<<endl;
            return;
        }else if(front > back){
            front = -1;
            back = -1;
        }
        else{
            front++;
        }
    }

    int peek(){
        if(front == -1 || front > back){
            return -1;
        }else{
            return nums[front];
        }
    }

};
int main(){
    Queue q(5);

    q.push_back(45);
    q.push_back(-11);
    q.push_back(105);
    q.push_back(23);

    q.pop();

    cout<<q.peek()<<endl;

    
}