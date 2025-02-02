#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data ){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
pair<bool, int> isSumTreeFast(Node* root){
    //base case 1
    if(root == NULL){
        pair<bool, int> p;
        p = make_pair(true, 0);
        return p;
    }
    //base cse 2 
    if(root->left == NULL && root->right == NULL){
        pair<bool, int> p;
        p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int>leftans = isSumTreeFast(root->left);
    pair<bool, int> rightans = isSumTreeFast(root->right);

    bool left = leftans.first;
    bool second = rightans.first;

    bool condn = root ->data == leftans.second + rightans.second;

    pair<bool, int> ans;

    if(left && second && condn){
        ans.first = true;
        ans.second = root->data + leftans.second + rightans.second;
    }else{
        ans.first = false;
    }
    return ans;
}
bool isSumTree(Node* root){
    return isSumTreeFast(root).first;
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
    buildLevelTree(root);
    levelOrderTravrsal(root);

    if(isSumTree(root)){
        cout<<"yes, the given tree is sum tree"<<endl;
    }else{
        cout<<"no, the given tree is not sum tree"<<endl;
    }
}