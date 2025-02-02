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
bool isIdenticalFast(Node* r1, Node* r2){
    if(r1 == NULL && r2 == NULL){
        return true;
    }
    if(r1 != NULL && r2 == NULL){
        return false;
    }
    if(r1 == NULL && r2 != NULL){
        return false;
    }

    bool leftans = isIdenticalFast(r1->left, r2->left);
    bool rightans = isIdenticalFast(r1->right, r2->right);

    bool isIdentical = r1->data == r2->data;

    if(leftans && rightans && isIdentical){
        return true;
    }else{
        return false;
    }
}
void isIdenticalTree(Node* r1, Node* r2){
    if(isIdenticalFast(r1, r2)){
        cout<<"tree 1 and tree 2 is identical"<<endl;
    }else{
        cout<<"tree 1 and tree 2 is not identical"<<endl;
    }
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
    Node* root1 = NULL;
    Node* root2 = NULL;
    buildLevelTree(root1);
    buildLevelTree(root2);

    isIdenticalTree(root1, root2);
}