#include<iostream>
#include<map>
using namespace std;
class Node {
    
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

class BinaryTree{
    public:
     //function to map the inorder
    map<int, int> mapping(vector<int> inorder, int size){
        map<int, int> createMap;

        for(int i=0; i<size; i++){
            createMap[inorder[i]] = i;
        }

        return createMap;
    }

    // Function to build the tree from given inorder and preorder traversals
    Node* solve(vector<int> &inorder, vector<int> &postorder, int &index,  
        map<int, int> &inOrderMap, int inorderStart, int inorderEnd, int size){
        
        //base case 
        if(index < 0 || inorderStart > inorderEnd){
            return NULL;
        }

        //increase the size of the index 
        int element = postorder[index--];
        Node* temp = new Node(element);
        int position = inOrderMap[element];

        temp->right = solve(inorder, postorder, index, inOrderMap, position+1, inorderEnd, size);
        temp->left = solve(inorder, postorder, index, inOrderMap, inorderStart, position-1, size);
        
        return temp;
    }

    Node *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int n = inorder.size();

        int postOrderIndex = n-1;

        map<int, int> inOrderMap;

        inOrderMap = mapping(inorder, n);

        Node* root = solve(inorder, postorder, postOrderIndex, inOrderMap, 0, n-1, n);
        
        return root;
    }
    void preOrderTraversal(Node* root){

        //base case 
        if(root == NULL){
            return;
        }

        cout<<root->data<<" ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
};
   
int main(){
    vector<int> inorder;
    vector<int> postorder;

    // inorder[] = [4, 8, 2, 5, 1, 6, 3, 7],
    inorder.push_back(4);
    inorder.push_back(8);
    inorder.push_back(2);
    inorder.push_back(5);
    inorder.push_back(1);
    inorder.push_back(6);
    inorder.push_back(3);
    inorder.push_back(7);

    // postorder[] = [8, 4, 5, 2, 6, 7, 3, 1]
    postorder.push_back(8);
    postorder.push_back(4);
    postorder.push_back(5);
    postorder.push_back(2);
    postorder.push_back(6);
    postorder.push_back(7);
    postorder.push_back(3);
    postorder.push_back(1);

    //size of the inorder and preorder must be equal
    Node* root = NULL;

    BinaryTree tree;

    root = tree.buildTree(inorder, postorder);

    //the answer must be print in the postorder format
    tree.preOrderTraversal(root);
}