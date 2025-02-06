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
Node* insertion(Node* &root, int data){

        //base case
        if(root == NULL){
            root = new Node(data);
            return root;
        }

        //recursive calls 
        if(data < root->data){
            root->left = insertion(root->left, data);
        }
        if(data > root->data){
            root->right = insertion(root->right, data);
        }

        return root;
    }

    void takeInput(Node* &root){
        int data;
        cout<<"enter the data : ";

        while(true){ 
            cin>>data;
            if(data == -1) break;
            root = insertion(root, data);
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

    Node* minNode(Node* root){
        Node* temp = root;

        while(temp -> left != NULL){
            temp = temp->left;
        }
        return temp;
    }

    Node* maxNode(Node* root){
        Node* temp = root;

        while (temp -> right != NULL){
            temp = temp -> right;
        }
        return temp;
    }

int main(){
    Node* root = NULL;

    takeInput(root);
    cout<<endl;
    levelOrderTravrsal(root);

    Node* max = maxNode(root);
    cout<<"max Node of the binary tree is "<<max->data<<endl;

    Node* min = minNode(root);
    cout<<"min Node of the binary tree is "<<min->data<<endl;

}