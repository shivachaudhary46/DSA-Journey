#include<iostream>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k) {
        
        //step 1: insert the queue element in stack upto k
        stack<int> s;
        for(int i=0; i<k; i++){
            int val = q.front();
            q.pop();
            s.push(val);
        }

        //step 2: pop element from stack and push into queue
        while(!s.empty()){
            int val = s.top();
            s.pop();
            q.push(val);
        }

        int  t = q.size()-k;
        while(t){
            int val = q.front();
            q.pop();
            q.push(val);
            t--;
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
    q.push(1);
    q.push(-3);
    q.push(7);
    q.push(-9);
    q.push(0);
    
    cout<<"before reversing k no element : ";
    print(q);

    int k = 3;
    queue<int> newQ = modifyQueue(q, k);

    cout<<"after reversing k no element : ";
    print(newQ);
}