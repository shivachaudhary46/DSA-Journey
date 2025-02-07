//normal binary tree to balanced binary tree 
//formula : (height(left) - height(right) ) <= 1
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

// Inorder Traversal to store BST elements in a sorted array
void inorderTraversal(Node* root, vector<int>& BSTinorder) {
    if (root == NULL) return;

    inorderTraversal(root->left, BSTinorder);
    BSTinorder.push_back(root->data);
    inorderTraversal(root->right, BSTinorder);
}

Node* inorderToBst(vector<int> &inorder, int s, int e){

    if(s>e) return NULL;

    int mid = s+(e-s)/2;

    Node* newRoot = new Node(inorder[mid]);
    newRoot->left = inorderToBst(inorder, s, mid-1);
    newRoot->right = inorderToBst(inorder, mid+1, e);

    return newRoot;
}

// normal bst to balanced bst 
Node* balancedBst(Node* root){

    vector<int> inorder;
    //step 1: convert the bst to inorder
    inorderTraversal(root, inorder);

    return inorderToBst(inorder, 0, inorder.size());
}

void levelOrderTraversal(Node* root){
        if(root == NULL) return;
        //step 1* create queue, push root in queue and push NULL
        queue<Node*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            //step 2: while queue is not empty store front value of queue and pop 
            Node* temp = q.front();
            q.pop();
            if(temp == NULL){
                cout<<endl;
                if(!q.empty()){
                    q.push(NULL);
                }
            }else{
                cout<<temp->data<<" ";
                if(temp -> left){
                    q.push(temp->left);
                }
                if(temp -> right){ 
                    q.push(temp->right);
                }
            }
        }
    }
int main(){
    Node* root = new Node(10);
    root->left = new Node(8);
    root->left->left = new Node(4);
    root->left->left->left = new Node(2);
    
    root->right = new Node(12);
    root->right->right = new Node(16);
    root->right->right->right = new Node(20);
    
    //before balancing the binary search tree 
    levelOrderTraversal(root);

    root = balancedBst(root);
    //after balancing the binary search tree 
    levelOrderTraversal(root);


}