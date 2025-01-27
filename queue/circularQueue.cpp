#include<iostream>
using namespace std;

class Queue{
    public:
    int *queue;
    int size;
    int front;
    int rear;

    //initalize a queue
    Queue(int size){
        this->size = size;
        queue = new int[size];
        front = -1;
        rear = -1;
    }

    //if we can push element in  queue return true if not false
    bool enqueue(int element){
        //step 1: if queue is overflowed we don`t need to push
        if((front-1) % size-1 == rear || (front == 0 && rear == size-1)){
            cout<<"queue overflowed"<<endl;
            return false;
        }else if(front == -1){
            //step 2: if front and rear is empty iinsert at first element 
            front = rear = 0;
        }else if(rear == (size - 1) && front != 0){
            //step 3: if rear is equivalent to size and front is at middle 
            rear = 0;
        }else{
            //step 4: normal flow 
            rear++;
        }
        queue[rear] = element;
        return true;
    }

    int dequeue(){
        //step 1: if queue is empty no need to pop
        int ans = queue[front];
        if(front == -1){
            cout<<"queue is underflowed"<<endl;
        }else if(front == rear){
            //step 2: if queue has only one element
            front = -1;
        }else if(front == size - 1){
            //step 3: maintain circular queue 
            front = 0;
        }else{
            //step 4: normal flow 
            front++;
        }
        return ans;
    }

    int getFront(){
        //step 1: check if queue is empty 
        if(front == -1){
            return -1;
        }else{
            //step 2: if not return front elemeent of queue
            return queue[front];
        }
    }

    int getBack(){
        //step 1: check if queue is empty 
        if(front == -1){
            return -1;
        }else{
            //step 2: if not return back element of queue
            return queue[rear];
        }
    }
};
int main(){
    
    Queue q(5);
    cout<<q.enqueue(15)<<endl;
    cout<<q.enqueue(25)<<endl;
    cout<<q.enqueue(35)<<endl;
    cout<<q.enqueue(45)<<endl;


    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.getFront()<<endl;
    cout<<q.getBack()<<endl;

    cout<<q.enqueue(1)<<endl;
    cout<<q.enqueue(2)<<endl;
    cout<<q.enqueue(3)<<endl;
    cout<<q.enqueue(4)<<endl;
}