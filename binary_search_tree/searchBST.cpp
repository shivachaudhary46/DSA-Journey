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

    bool Search(Node* root, int data){
        Node* temp = root;
        while(temp->data != -1){
            if(temp->data == data){
                return true;
            }

            if(data < temp->data){
                temp = temp -> left;
            }
            if(data > temp->data){
                temp = temp -> right;
            }
        }
        return false;
    }


int main(){
    Node* root = NULL;

    takeInput(root);
    cout<<endl;
    if(Search(root, 5)){
        cout<<"given element is present "<<endl;
    }else{
        cout<<"element is not present "<<endl;
    }
}