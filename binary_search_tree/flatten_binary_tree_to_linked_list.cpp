#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Inorder Traversal to store BST elements in a sorted array
void inorderTraversal(Node* root, vector<int>& BSTinorder) {
    if (root == NULL) return;

    inorderTraversal(root->left, BSTinorder);
    BSTinorder.push_back(root->data);
    inorderTraversal(root->right, BSTinorder);
}

// Flatten BST into a right-skewed linked list
Node* flatten(Node* root) {
    vector<int> BSTinorder;
    
    // Step 1: Convert BST into an inorder (sorted) vector
    inorderTraversal(root, BSTinorder);

    // Step 2: Convert vector into a right-skewed linked list
    if (BSTinorder.empty()) return NULL; // Edge case: empty tree

    Node* newroot = new Node(BSTinorder[0]);
    Node* curr = newroot;

    for (int i = 1; i < BSTinorder.size(); i++) {
        Node* temp = new Node(BSTinorder[i]);
        curr->left = NULL; // Ensuring left pointers remain NULL
        curr->right = temp;
        curr = temp;
    }

    return newroot; // Return new flattened BST root
}

// Function to print right-skewed list
void printFlattenedTree(Node* root) {
    while (root) {
        cout << root->data << " -> ";
        root = root->right;
    }
    cout << "NULL" << endl;
}

// Driver Code
int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    cout << "Flattened BST: ";
    Node* newRoot = flatten(root);
    printFlattenedTree(newRoot);

    return 0;
}
