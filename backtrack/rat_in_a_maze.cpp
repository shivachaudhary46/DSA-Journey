#include<iostream>
using namespace std;
void solve(vector<vector<int>> &mat, vector<vector<bool>> &visited, vector<string> temp, string path){

    //base case 
    if()
}
vector<string> findPath(vector<vector<int>> &mat) {
    // code here

    vector<string> ans;
    string path = "";

    int n = mat[0].size();
    //create a visited array list 
    vector<vector<bool> >visited(n, vector<bool> (n, 0));


    //back tracking 
    solve(mat, visited, ans, path);

}