#include<iostream>
using namespace std;
class Queue{
    private:
    stack<int> s1, s2;

    public:
    void enqueue(int element){
        while(!s1.empty()){
            int val = s1.top();
            s1.pop();
            s2.push(val);
        }

        //push element into stack 1
        s1.push(element);

        while(!s2.empty()){
            int val = s2.top();
            s2.pop();
            s1.push(val);
        }
    }
    void dequeue(){
        if(s1.empty()){
            return;
        }
        s1.pop();
    }

    int top(){
        if(s1.empty()){
            return -1;
        }else{
            return s1.top();
        }
    }
};
int main(){
    Queue q;
    q.enqueue(56);
    q.enqueue(67);
    q.enqueue(89);
    q.enqueue(1);
    cout<<q.top()<<endl;

    q.dequeue();
    cout<<q.top()<<endl;
}