#include<iostream>
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
void leftTraversal(Node* root, vector<int>& ans){
    if((root == NULL) || (root->left == NULL && root->right == NULL)){
        return;
    }

    ans.push_back(root->data);
    if(root -> left){
        leftTraversal(root->left, ans);
    }else{
        leftTraversal(root->right, ans);
    }
}

void leafTraversal(Node* root, vector<int>& ans){
    if(root == NULL){
        return;
    }

    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
    }

    leafTraversal(root->left, ans);
    leafTraversal(root->right, ans);
}
void rightTraversal(Node* root, vector<int>& ans){
    if((root == NULL) || (root->left == NULL && root->right == NULL)){
        return;
    }

    if(root->right){
        rightTraversal(root->right, ans);
    }else{
        rightTraversal(root->left, ans);
    }

    ans.push_back(root->data);
}
vector<int> boundaryTraversal(Node* root){
    vector<int> ans;
    
    ans.push_back(root->data);

    //left traversal
    leftTraversal(root->left, ans);

    //leaf nodes traversal
    //left sub tree 
    leafTraversal(root->left, ans);

    //right sub tree 
    leafTraversal(root->right, ans);

    //right 
    rightTraversal(root->right, ans);
    
    return ans;
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
int main(){
    Node* root = NULL;
    buildLevelTree(root);;

    levelOrderTravrsal(root);

    cout<<"boundary traversal : ";
    vector<int> ans = boundaryTraversal(root);
    int size = ans.size();
    for(int i=0; i<size; i++){
        cout<<ans[i]<<" ";
    }
}