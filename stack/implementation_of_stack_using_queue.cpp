#include<iostream>
using namespace std;
class Stack{
    queue<int> q1, q2;

    public:
        void Push(int element){
            q2.push(element);

            while (!q1.empty()){
                int val = q1.front();
                q1.pop();
                q2.push(val);
            }
            
            queue<int> q = q1;
            q1 = q2;
            q2 = q;
        }

        void pop(){
            if(q1.empty()){
                return;
            }else{
                q1.pop();
            }
        }

        int size(){
            return q1.size();
        }

        int top(){
            if(q1.empty()){
                return -1;
            }else{
                return q1.front();
            }
        }

};
int main(){
    Stack s;

    s.Push(5);
    s.Push(6);
    s.Push(7);
    s.Push(8);
    s.Push(9);

    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;

}