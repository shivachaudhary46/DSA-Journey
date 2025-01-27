#include<iostream>
using namespace std;
queue<int> queue_reversal(queue<int>q){
    stack<int> s;

    while(!q.empty()){
        int element = q.front();
        q.pop();
        s.push(element);
    }

    while (!s.empty()){
        int element = s.top();
        s.pop();
        q.push(element);
    }
    return q;
}
void print(queue<int> q){
    while(!q.empty()){

        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}
int main(){
    queue<int> q;
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);
    q.push(10);
    q.push(11);

    cout<<"before reversing element : ";
    print(q);

    queue<int> newQ = queue_reversal(q);

    cout<<"after reversing element : ";
    print(newQ);
}