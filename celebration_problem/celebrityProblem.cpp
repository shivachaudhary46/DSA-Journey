#include <iostream>
using namespace std;

class Solution {
    private:
        bool known(vector<vector<int> >& mat, int a, int b){
            if(mat[a][b] == 1){
                return true;
            }else{
                return false;
            }
        }
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        stack<int> s;
        int n = mat.size();
        
        //step 1; push all element in the stack
        for(int i=0; i<n; i++){
            s.push(n);
        }
        
        //step 2; pop two element in stack 
        //if a knows b,  pop a and push b, viceversa
        //carry out this process until stack size is 1
        
        while(s.size() > 1){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            
            if(known(mat, a, b)){
                s.push(b);
            }else{
                s.push(a);
            }
        }
        
        //step 3; top element of stack is potential candidate 
        //so check, candidate knows nobody, row = 0
        //everyone knows candidate, col = 1
        //return index candidate
        int zeroCount = 0;
        int candidate = s.top();
        bool knowsR = false;
        
        for ( int i=0; i<n; i++){
            if(mat[candidate][i] == 0){
                zeroCount++;
            }
        }
        
        if(zeroCount == n){
            knowsR = true;
        }
        
        //everyone knows candidate 
        int oneCount = 0;
        bool knowsC = false;
        
        for ( int i=0; i<n; i++){
            if(mat[i][candidate] == 1){
                oneCount++;
            }
        }
        
        if(oneCount == n-1){
            knowsC = true;
        }
        
        if(knowsR == true && knowsC == true){
            return candidate;
        }else{
            return -1;
        }
    }
};

int main() {
    vector<vector<int>> nums{{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};
    // nums.push_back({0, 1, 0});
    // nums.push_back({0, 0, 0});
    // nums.push_back({0, 1, 0});

    int cols = nums.size();
    int rows = nums[0].size();

    for(int  i=0; i<rows; i++){
        for(int j=0; j<cols; j++){

            cout<<nums[i][j]<<" ";
        }
        cout<<endl;
    }


}

// } Driver Code Ends