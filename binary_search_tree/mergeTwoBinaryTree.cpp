#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};
void bstToInorder(Node* root, vector<int> &inorder){
    if(root  == NULL){
        return;
    }

    bstToInorder(root->left, inorder);
    inorder.push_back(root->data);
    bstToInorder(root->right, inorder);
}
void mergeTwoBinaryTree()
int main(){
    Node* root = NULL;


}