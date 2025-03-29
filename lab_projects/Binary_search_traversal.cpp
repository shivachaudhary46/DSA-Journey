#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right;

    //constructor
    //node contains data, left pointer and right pointer
    Node(int data){
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }

    //gives us the inorder successor 
    Node *minNode(Node* root ){
        Node* temp = root;
        while( temp != NULL && temp -> left != NULL){
            temp = temp -> left;
        }
        return temp;
    }

    //if root has no element then create new node which will be root
    //recursive left call if the inserted data is smaller than root 
    //call recursiive right if the inserted data is bigger than root
    Node* insertion(Node *root, int data){
        
        if(root == NULL){
            Node* newNode = new Node(data);
            root = newNode;
            return root;
        }

        if(root -> data > data){
            root -> left = insertion(root->left, data);
        }else{
            root -> right = insertion(root->right, data);
        }

        return root;
    }

    //if we are deleting the node in the bst there are three diff cases :
    /* Node has no children(leaf node) : delete it directly 
       Node has one child : replace the node with its child
       Node has two children : find inorder succesor that will bee next root */
    Node* deletion(Node* root, int data){
        if(root == NULL){
            return root;
        }
        
        if (root -> data == data){

            if(root->left  == NULL){
                Node* temp = root->left;
                delete root;
                return temp;
            }
            else if(root -> right == NULL){
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else{
                Node* temp = minNode(root->right);
                root->data = temp->data;
                root->right = deletion(root->right, temp->data);
            }
        }else if(root -> data > data){
            root -> left = deletion(root->left, data);
        }else{
            root -> right = deletion(root -> right, data);
        }
    }

    //this function search the given element in the 
    bool search(Node* root, int element){

        Node* temp = root;
        while(temp != NULL){

            if(temp -> data == element){
                return true;
            }

            if(temp -> data > element){
                temp = temp -> left;
            }
            if(temp -> data < element){
                temp = temp -> right;
            }
        }
        return false;
    }
};
int main(){

}