//double ended queue 
#include<iostream>
using namespace std;
class dqueue{
    private:
    int size;
    int *queue;
    int front;
    int back;

    public:
    dqueue(int size){
        this->size = size;
        queue = new int[size];
        front = -1;
        back = -1;
    }

    bool push_back(int element){
        //step 1: if queue is full no need to insert element 
        if(isFull()){
            cout<<"queue is overflowed"<<endl;
            return false;
        }else if(isEmpty()){
            //if queue is empty  
            front = back = 0;
        }else if(back == size-1 && front != 0){
            //maintain circular queue 
            back = 0;
        }else{
            //normal flow 
            back++;
        }
        queue[back] = element;
        return true; 
    }

    int pop_back(){
        int ans = queue[back];
        //step 1: if queue is full no need to push
        if(isEmpty()){
            cout<<"queue is underflow"<<endl;
            return -1;
        }else if(front == back){
            //if queue has only one element 
            front = back = -1;
        }else if(back == 0){
            //maintain circular queue 
            back = size-1;
        }else{
            //normal flow 
            back--;
        }
        return ans;
    }

    bool push_front(int element){
        //step 1: if queue is full no need to push
        if(isFull()){
            cout<<"queue is overflowed"<<endl;
            return false;
        }else if(isEmpty()){
            //if queue is empty  
            front = back = 0;
        }else if(front == 0 && back != (size-1)){
            //maintain circular queue 
            front = size-1;
        }else{
            //normal flow 
            front--;
        }
        queue[back] = element;
        return true; 
    }

    int pop_front(){
        int ans = queue[front];
        //step 1: if queue is full no need to push
        if(isEmpty()){
            cout<<"queue is underflow"<<endl;
            return -1;
        }else if(front == back){
            //if queue has only one element 
            front = back = -1;
        }else if(front == size-1){
            //maintain circular queue 
            front = 0;
        }else{
            //normal flow 
            front++;
        }
        return ans;
    }

    bool isFull(){
        //if queuee is full
        if((front - 1) % (size - 1) == back){
            return 1;
        }else{
            return 0;
        }
    }

    bool isEmpty(){
        //if queue is empty 
        if(front == -1){
            return 1;
        }else{
            return 0;
        }
    }

    int getFront(){
        if(isEmpty()){
            return -1;
        }else{
            return queue[front];
        }
    }
    int getBack(){
        if(isEmpty()){
            return -1;
        }else{
            return queue[back];
        }
    }
};
int main(){
    dqueue deque(5);
    cout<<deque.push_front(4)<<endl;
    cout<<deque.push_back(6)<<endl;

    cout<<deque.getFront()<<endl;
    cout<<deque.getBack()<<endl;

    cout<<deque.pop_front()<<endl;
    cout<<deque.pop_back()<<endl;

    cout<<deque.getFront()<<endl;
    cout<<deque.getBack()<<endl;

    cout<<endl;
    cout<<deque.push_front(4)<<endl;
    cout<<deque.push_front(6)<<endl;
    cout<<deque.push_front(7)<<endl;
    cout<<deque.push_front(8)<<endl;
    cout<<deque.push_front(9)<<endl;
    cout<<deque.push_back(10)<<endl; // queue overflowed 

    cout<<endl;
    cout<<deque.pop_front()<<endl;
    cout<<deque.pop_front()<<endl;
    cout<<deque.pop_front()<<endl;
    cout<<deque.pop_front()<<endl;
    cout<<deque.pop_front()<<endl;
    cout<<deque.pop_back()<<endl; 
}