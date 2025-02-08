#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

//convert thee given binary tree to linked list 
void convertIntoSortedDll(Node* root, Node* &head){

    //base case
    if(root == NULL){
        return;
    }

    convertIntoSortedDll(root->right, head);
    root->right = head;

    if(head != NULL){
        head->left = root;
    }
    head = root;

    convertIntoSortedDll(root->left, head);
}

//merge two linked list 
Node* mergeTwoLL(Node* head1, Node* head2){
    Node* head = NULL;
    Node* tail = NULL;

    while (head1 != NULL && head2 != NULL){
        /* code */
        if(head1->data < head2->data){
            if(head == NULL){
                head = head1;
                tail = head1;
                head1 = head1 ->right;
            }else{
                tail -> right = head1;
                head1 -> left = tail;
                tail = head1;
                head1 = head1 -> right;
            }
        }else{
            if(head == NULL){
                head = head2;
                tail = head2;
                head2 = head2 ->right;
            }else{
                tail -> right = head2;
                head2 -> left = tail;
                tail = head2;
                head2 = head2 -> right;
            }
        }
    }

    while(head1 != NULL){
        tail -> right = head1;
        head1 -> left = tail;
        tail = head1;
        head1 = head1 -> right;
    }
    
    while(head2 != NULL){
        tail -> right = head2;
        head2 -> left = tail;
        tail = head2;
        head2 = head2 -> right;
    }

    return head;
}

//convert the merged linkedlist to the binaary tree 
Node* linkedlistToTree(Node* root, int n){

    if( n<=0 || root == NULL){
        return NULL;
    }

    Node* left = linkedlistToTree(root, n/2);

    Node* head = root;
    head->left = left;

    root = root->right;

    head->right = linkedlistToTree(root, n-n/2-1);

    return head;
}
int count(Node* root){

    int count = 0;
    while(root != NULL){
        count++;
        root = root->right;
    }
    return count;
}
Node* mergeTwoLinkedlist(Node* &root1, Node* &root2){

    //convert the given binay tree to linked list 
    Node* head1 = NULL;
    convertIntoSortedDll(root1, head1);
    head1->left = NULL;

    Node* head2 = NULL;
    convertIntoSortedDll(root2, head2);
    head2->left = NULL;

    //merge the linked list 
    Node* merge = mergeTwoLL(head1, head2);

    //convert the merged linked list to the binary tree
    int n = count(merge);
    return linkedlistToTree(merge, n);
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
    Node* root = new Node(10);
     root->left = new Node(4);
     root->left->left = new Node(3);
     root->left->right = new Node(7);

     root->right = new Node(40);
    root->right->right = new Node(55);

    Node* root1 = new Node(20);
    root1->left = new Node(10);
    root1->left->left = new Node(5);
    root1->left->right = new Node(15);
    root1->left->left->left = new Node(3);
    root1->left->left->left = new Node(8);

    root1->right = new Node(30);
    root1->right->left = new Node(25);
    root1->right->right = new Node(40);

    root = mergeTwoLinkedlist(root, root1);

    levelOrderTravrsal(root);

}