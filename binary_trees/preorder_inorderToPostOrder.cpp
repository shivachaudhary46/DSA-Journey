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
    Node* solve(vector<int> &inorder, vector<int> &preorder, int &index,  
        map<int, int> &inOrderMap, int inorderStart, int inorderEnd, int size){
        
        //base case 
        if(index >= size || inorderStart > inorderEnd){
            return NULL;
        }

        //increase the size of the index 
        int element = preorder[index++];
        Node* temp = new Node(element);
        int position = inOrderMap[element];

        temp->left = solve(inorder, preorder, index, inOrderMap, inorderStart, position-1, size);
        temp->right = solve(inorder, preorder, index, inOrderMap, position+1, inorderEnd, size);
        
        return temp;
    }

    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        int preOrderIndex = 0;
        int n = inorder.size();

        map<int, int> inOrderMap;

        inOrderMap = mapping(inorder, n);

        Node* root = solve(inorder, preorder, preOrderIndex, inOrderMap, 0, n-1, n);
        
        return root;
    }
    void postOrderTraversal(Node* root){

        //base case 
        if(root == NULL){
            return;
        }

        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout<<root->data<<" ";
    }
};
   
int main(){
    vector<int> inorder;
    vector<int> preorder;

    // inorder[] = [3, 1, 4, 0, 2, 5]
    inorder.push_back(3);
    inorder.push_back(1);
    inorder.push_back(4);
    inorder.push_back(0);
    inorder.push_back(2);
    inorder.push_back(5);

    // preorder[] = [0, 1, 3, 4, 2, 5]
    preorder.push_back(0);
    preorder.push_back(1);
    preorder.push_back(3);
    preorder.push_back(4);
    preorder.push_back(2);
    preorder.push_back(5);

    //size of the inorder and preorder must be equal
    Node* root = NULL;

    BinaryTree tree;

    root = tree.buildTree(inorder, preorder);

    //the answer must be print in the postorder format
    tree.postOrderTraversal(root);
}