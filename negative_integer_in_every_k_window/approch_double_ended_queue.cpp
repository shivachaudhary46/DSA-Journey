#include<iostream>
using namespace std;

vector<int> FirstNegativeInteger(vector<int>& arr, int k) {
        // write code here
        int n = arr.size();

        //create answer vector and deque to slide window 
        vector<int> ans;
        deque<int> dq;

        //for first k element 
        //step 1: check in first window whether there is negative int
        //step 2: insert index in deque if negataive integer
        for(int i=0; i<k; i++){
            if(arr[i]<0){
                dq.push_back(i); 
            }
        }

        //step 3: if dq consist of the negative integer
        // then push into answer 
        if(dq.size() > 0){
            ans.push_back(arr[dq.front()]);
        }else{
            ans.push_back(0);
        }

        //step 4: process for remaining windows 
        for(int i=k; i<n; i++){

            //step 5: remove from front if window size is equal in 
            //deque
            if(!dq.empty() && (i - dq.front()) >= k){
                dq.pop_front();
            }
            
            //step 6: push new element in deque
            if(arr[i] < 0){
                dq.push_back(i);
            }
            //step 7: push the dq.front() element in ans if negative integer 
            if(!dq.empty()) {
                ans.push_back(arr[dq.front()]);
            } else {
                ans.push_back(0);
            }
        }

        return ans;
    }
void print(vector<int> v){
    int n = v.size();
    for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> nums;
    nums.push_back(-8);
    nums.push_back(5);
    nums.push_back(0);
    nums.push_back(-2);
    nums.push_back(-7);
    nums.push_back(8);

    int k = 2;
    vector<int> ans = FirstNegativeInteger(nums, k);

    cout<<"first negative integer in "<<k<<" windows: ";
    print(ans);
}