#include<iostream>
#include<queue>
#include<vector>
#include<map>
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
    void solve(Node* root, vector<int> &ans, int lvl){

        if(root == NULL){
            return;
        }

        //push the element in the each new lvl of the tree
        if(lvl == ans.size()){
            ans.push_back(root->data);
        }

        solve(root->left, ans, lvl+1);
        solve(root->right, ans, lvl+1);
    }
    vector<int> leftView(Node* &root){
        vector<int> ans;
        solve(root, ans, 0);
        return ans;
    }
int main(){
    Node* root = NULL;
    buildLevelTree(root);

    levelOrderTravrsal(root);

    cout<<"left view of tree : ";
    vector<int> ans = leftView(root);
    int size = ans.size();
    for(int i=0; i<size; i++){
        cout<<ans[i]<<" ";
    }
}