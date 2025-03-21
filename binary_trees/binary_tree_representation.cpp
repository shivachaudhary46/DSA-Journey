#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    //initialize a constructor 
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
Node* buildTree(Node* root) {

        cout << "Enter the data: " << endl;
        int data;
        cin >> data;
        root = new Node(data);    

        if(data == -1) {
            return NULL;
        }

        cout << "Enter data for inserting in left of " << data << endl;
        root->left = buildTree(root->left);
        cout << "Enter data for inserting in right of " << data << endl;
        root->right = buildTree(root->right);
        return root;
    }

    void levelOrderTravrsal(Node* root){
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
    void inorderTraversal(Node* root){

        //base case
        if(root == NULL){
            return;
        }
        
        inorderTraversal(root->left);
        cout<<root->data<<" ";
        inorderTraversal(root->right);
    }
    void preOrderTraversal(Node* root){

        //base root
        if(root == NULL){
            return;
        }
        cout<<root->data<<" ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
    void postOrderTraversal(Node* root){

        //base root
        if(root == NULL){
            return;
        }

        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout<<root->data<<" ";
    }
    void buildLevelTree(Node* &root){
        cout<<"enter  the data ";
        int data;
        cin>>data;

        //root is null:
        root = new Node(data);

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            Node* temp = q.front();
            q.pop();

            cout<<"enter the value for left of "<<temp->data<<" : ";
            int leftData;
            cin>>leftData;
            if(leftData != -1){
                temp -> left = new Node(leftData);
                q.push(temp->left);
            }

            cout<<"enter the value for right of "<<temp->data<<" : ";
            int rightData;
            cin>>rightData;
            if(rightData != -1){
                temp -> right = new Node(rightData);
                q.push(temp -> right);
            }
        }
    }
    void countLeaf(Node* root, int &count){
        if(root == NULL){
            return;
        }

        //inorder
        countLeaf(root->left, count);

        if(root -> left == NULL && root->right == NULL){
            count++;
        }
        countLeaf(root->right, count);
    }
    int countLeafNode(Node* root){
        int count;
        countLeaf(root, count);
        return count;
    }
int main(){
    Node* root = NULL;
    //1 3 5 7 11 17 -1 -1 -1 -1 -1 -1
    buildLevelTree(root);

    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    levelOrderTravrsal(root);

    
    cout<<"total no of leaf node is "<<countLeafNode(root)<<endl;
    // cout<<endl;
    // inorderTraversal(root);
    // cout<<endl;
    // preOrderTraversal(root);
    // cout<<endl;
    // postOrderTraversal(root);
    // cout<<endl;
}