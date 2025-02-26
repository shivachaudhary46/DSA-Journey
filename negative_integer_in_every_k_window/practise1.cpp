#include<iostream>
#include<deque>
#include<vector>
using namespace std;
void print(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
vector<int> FirstNegativeInteger(vector<int> arr, int k){
    int n = arr.size();
    vector<int> ans;
    deque<int> dq;

    for(int i=0; i<k; i++){
        if(arr[i] < 0){
            dq.push_back(i);
        }
    }

    if(dq.size() > 0){
        ans.push_back(arr[dq.front()]);
    }else{
        ans.push_back(0);
    }

    for(int i=k; i<n; i++){
        if(!dq.empty() && (i-dq.front()) >= k){
            dq.pop_front();
        }

        if(!dq.empty()){
            ans.push_back(arr[dq.front()]);
        }else{
            ans.push_back(0);
        }

        if(arr[i] < 0){
            dq.push_back(i);
        }
    }
    return ans;
}
int main(){
    vector<int> arr;
    arr.push_back(-3);
    arr.push_back(5);
    arr.push_back(-5);
    arr.push_back(6);
    arr.push_back(-3);
    arr.push_back(8);

    vector<int> ans = FirstNegativeInteger(arr, 2);
    print(ans);
}