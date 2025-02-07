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
void inorder(Node* root, vector<int> &inorderBst){
    if(root==NULL){
        return;
    }

    inorder(root->left, inorderBst);
    inorderBst.push_back(root->data);
    inorder(root->right, inorderBst);
}

vector<int> mergeArray(vector<int> a, vector<int> b){
    vector<int> ans(a.size()+b.size());
    
    int i=0, j=0;
    int k = 0;

    while(i < a.size() && j < b.size()){
        if(a[i] < b[j]){
            ans[k++] = a[i++];
        }else{
            ans[k++] = b[j++];
        }
    }

    while(i < a.size()){
        ans[k++] = a[i++];
    }

    while (j < b.size()){
        ans[k++] = b[j++];
    }
    
    return ans;
}

Node* convertInorderBst(vector<int> inorder, int s, int e){
    if(s > e){
        return NULL;
    }

    int mid = s+(e-s)/2;

    Node* root = new Node(inorder[mid]);
    root->left = convertInorderBst(inorder, s, mid-1);
    root->right = convertInorderBst(inorder, mid+1, e);

    return root;
}
void levelOrderTravrsal(Node* root){
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
    void deleteTree(Node* root){
        if(root == NULL){
            return;
        }

        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
    Node* mergeTwoBinarytree(Node* &root1, Node* &root2){
        vector<int> a;
        vector<int> b;

        //step 1: convert the two trees and store in vector
        inorder(root1, a);
        inorder(root2, b);
        
        //step 2: merge two arrays
        vector<int> ans = mergeArray(a, b);
        
        //step 3: convert the array to bst
        Node* newroot = convertInorderBst(ans, 0, ans.size()-1);

        deleteTree(root1);
        deleteTree(root2);

        return newroot;
    }

int main(){
     Node* root = new Node(10);
     root->left = new Node(4);
     root->left->left = new Node(3);
     root->left->right = new Node(7);

     root->right = new Node(40);
    root->right->right = new Node(55);

    Node* root1 = new Node(20);
    root1->left = new Node(10);
    root1->left->left = new Node(5);
    root1->left->right = new Node(15);
    root1->left->left->left = new Node(3);
    root1->left->left->left = new Node(8);

    root1->right = new Node(30);
    root1->right->left = new Node(25);
    root1->right->right = new Node(40);

    root = mergeTwoBinarytree(root, root1);

    //step 4: print the bst
    levelOrderTravrsal(root);
}