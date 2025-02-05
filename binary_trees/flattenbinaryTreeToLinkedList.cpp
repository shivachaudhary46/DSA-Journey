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

    void flattenBinaryTreeLinkedList(Node* &root){
        Node* curr = root;

        while(curr != NULL){
            if(curr->left){
                Node* pred = curr->left;

                while(pred->right){
                    pred = pred->right;
                }
                pred->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;

            }
            curr = curr->right;
        }
    }
    void printNode(Node* head){
        Node* temp = head;
        
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->right;
        }
        cout<<endl;
    }
int main(){
    Node* root = NULL;
    buildLevelTree(root);;

    levelOrderTravrsal(root);

    cout<<"flatten a binary tree to linked list  : ";
    flattenBinaryTreeLinkedList(root);
    printNode(root);
}