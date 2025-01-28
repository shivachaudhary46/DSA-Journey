#include<iostream>
#include<queue>
using namespace std;
int main(){
    /*maximum heap */
    priority_queue<int> max;

    /*minimum-heap*/
    priority_queue<int, vector<int>, greater<int>> min;

    max.push(12);
    max.push(2);
    max.push(1);
    max.push(5);

    int m=max.size();
    for(int i=0; i<m; i++){
        cout<<"top: "<<max.top()<<endl;
        max.pop(); 
    }

    min.push(1);
    min.push(4);
    min.push(0);
    min.push(-1);

    cout<<endl;
    int n=min.size();
    for(int i=0; i<n; i++){
        cout<<"top: "<<min.top()<<endl;
        min.pop();
    }

    cout<<"is empty or not: "<<min.empty()<<endl;
    
}