#include<iostream>
#include<queue>
using namespace std;
/*first in first out*/
int main(){
    queue<string> q;
    
    q.push("string");
    q.push("shiva");
    q.push("jevis");
    q.push("anjelika");

    cout<<"top element : "<<q.front()<<endl;
    q.pop();
    cout<<"top element : "<<q.front()<<endl;
    q.pop();
    cout<<"top element : "<<q.front()<<endl;
}