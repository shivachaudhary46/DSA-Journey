#include<iostream>
#include<deque>
/*deque is double end queue*/
using namespace std;
int main(){
    deque<int> deq;
    deq.push_back(1);
    deq.push_front(6);
    deq.push_back(2);
    deq.push_front(5);
    deq.push_back(3);
    deq.push_back(4);

    for(auto i:deq){
        cout<<i<<" ";
    }
    cout<<endl;
    deq.pop_front();
    deq.pop_back();
    for(auto i:deq){
        cout<<i<<" ";
    }

    cout<<endl;
    cout<<"front: "<<deq.front()<<endl;
    cout<<"back: "<<deq.back()<<endl;
    cout<<"empty: "<<deq.empty()<<endl;
    
    /*erase() time complexity-> (start, end) */
    deq.erase(deq.begin(), deq.begin()+1);

    for(auto i:deq){
        cout<<i<<" ";
    }

}