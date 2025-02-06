#include<iostream>
using namespace std;

class searchTree{

    public:
    int data;
    searchTree* left;
    searchTree* right;

    searchTree(int data){
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

searchTree* solve(vector<int> &preorder, int mini, int max, int &i){

    if(i >= preorder.size()){

        return NULL;
    }

    if(preorder[i] < mini || preorder[i] > max){
        return NULL;
    }

    searchTree* root = new searchTree(preorder[i++]);
    root->left = solve(preorder, mini, root->data, i);
    root->right = solve(preorder, root->data, max, i);
    return root;
}

searchTree* preorderToBST(vector<int> &preorder){
    int mini = INT_MIN;
    int max = INT_MAX;
    int i=0;
    searchTree* root = solve(preorder, mini, max, i);
    return root;

}

void inorderTraversal(searchTree* root){

    if(root == NULL){
        return;
    }

    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);

}
void preorderTraversal(searchTree* root){

    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);

}

int main(){
    searchTree* s = NULL;
    vector<int> pre;
    pre.push_back(10);
    pre.push_back(4);
    pre.push_back(3);
    pre.push_back(7);
    pre.push_back(40);
    pre.push_back(55);

    s = preorderToBST(pre);
    inorderTraversal(s);
    cout<<endl;
    preorderTraversal(s);
}