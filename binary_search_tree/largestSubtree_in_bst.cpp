#include<iostream>
#include<climits>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
class info{
    public:
    int maxi;
    int mini;
    bool isBst;
    int size;
};

info solve (Node* root, int &ans){
    //base case
    if(root == NULL){
        return {INT_MIN, INT_MAX, true, 0};
    }

    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info currNode;

    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root->data, right.maxi);
    currNode.mini = min(root->data, left.mini);

    if(left.isBst && right.isBst && (left.maxi < root->data && right.mini > root->data)){
        currNode.isBst = true;
    }else{
        currNode.isBst = false;
    }

    if(currNode.isBst){
        ans = max(ans, currNode.size);
    }

    return currNode;
}
int largestBst(Node* root){
    int maxsize = 0;

    info temp = solve(root, maxsize);
    return maxsize;
}
int main(){
    Node* root = new Node(10);
    root->left = new Node(5);
    root->left->left = new Node(2);
    root->left->right = new Node(3);

    root->right = new Node(9);

    cout<<"largest bst subtree in the bst : "<<largestBst(root)<<endl;
}