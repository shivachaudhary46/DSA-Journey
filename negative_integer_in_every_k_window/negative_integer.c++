#include<iostream>
#include<vector>
#include<deque>
using namespace std;
void print(vector<int> & ans){
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
vector<int> firstnegative(vector<int> &arr, int k){
    int n = arr.size();
    vector<int> ans;
    deque<int> dq;

    //step 1 : iterate and check 
    // if negative integer exist in the first window
    for(int i=0; i<k; i++){
        if(arr[i] < 0){
            dq.push_back(i);
        }
    }

    //step 2 : if deque has found an element in the first 
    //window
    if(dq.size() > 0){
        ans.push_back(arr[dq.front()]);
    }else{
        ans.push_back(0);
    }

    //step 3 : iterate in the next windows 
    for(int i=k; i<n; i++){
        
        //step 4 : pop element if the windows is complete 
        if(!dq.empty() && (i-dq.front()) >= k){
            dq.pop_front();
        }

        //step 5 : push the negative integer in the vector
        if(!dq.empty()){
            ans.push_back(arr[dq.front()]);
        }else{
            ans.push_back(0);
        }

        //step 6 : if negatiive integer exist then 
        if(arr[i] < 0){
            dq.push_back(i);
        }
    }

    return ans;
}
int main(){
    vector<int> nums;
    nums.push_back(-8);
    nums.push_back(5);
    nums.push_back(0);
    nums.push_back(-2);
    nums.push_back(-7);
    nums.push_back(8);

    int window_size = 2;
    vector<int> ans = firstnegative(nums, window_size);

    cout<<"after finding first negative integer in each windows : "<<endl;
    print(ans);
}