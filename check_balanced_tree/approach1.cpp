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

pair<bool, int> checkBalanceFast(Node* root){
    if(root == NULL){
        pair<bool, int> p;
        p = make_pair(true, 0);
        return p;
    }

    pair<bool, int> leftans = checkBalanceFast(root->left);
    pair<bool, int> rightans = checkBalanceFast(root->right);

    bool Left = leftans.first;
    bool Right = rightans.first;

    bool diff = abs(leftans.second - rightans.second) <= 1;

    pair<bool, int> ans;
    ans.first = diff;
    ans.second = max(leftans.second, rightans.second) + 1;

    if(left && right && diff){
        return ans;
    }else{
        pair<bool, int> p;
        p = make_pair(false, ans.second);
        return p;
    }
}
void checkBalanceTree(Node* root){
    pair<bool, int> res = checkBalanceFast(root);
    if(res.first){
        cout<<"the tree is balanced "<<endl;
    }else{
        cout<<"the tree is not balanced "<<endl;
    }
}
int main(){
    Node* root = NULL;
    buildLevelTree(root);
    levelOrderTravrsal(root);
    checkBalanceTree(root);
}