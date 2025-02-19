#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* right;

    Node(int data){
        this->data = data;
        this->right = NULL;
    }

    ~Node(){
        cout<<"deleted data : "<<data<<endl;
        if(right != NULL){
            delete right;
        }
    }
};
//insetion of the node 
void insertTailNode(Node* &tail, int element){
    Node* temp = new Node(element);
    if(tail == NULL){
        tail = temp;
    }else{
        tail -> right = temp;
        tail = temp;
    }
}
void insertHeadNode(Node* &head, int element){
     Node* temp = new Node(element);
    if(head == NULL){
        head = temp;
    }else{
        temp->right = head;
        head = temp;
    }
}

void insertAtPosition(Node* &head, int element , int position ){
    Node* temp = head;
    int count=0;

    while(count < position-1){
        temp = temp -> right;
        count++;
    }

    Node* newNode = new Node(element);
    newNode->right = temp->right;
    temp->right = newNode;
}
void printTraversal(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ->  ";
        temp = temp->right;
    }
    cout<<"NULL"<<endl;
}

void deleteNode(int position, Node* &head){
    //deletion of the node if position is 1 
    if(position == 1){
        Node* temp = head;
        head = head->right;

        temp -> right = NULL;
        delete temp;
    }else{

        int count = 0;
        Node* prev = NULL;
        Node* curr = head;

        while(count < position){
            prev = curr;
            curr = curr -> right;
            count++;
        }

        prev -> right = curr -> right;
        curr -> right = NULL;
        delete curr;
    }
}
int main(){
    Node* head = NULL;
    Node* tail = NULL;

    insertTailNode(tail, 67);
    head = tail;

    insertTailNode(tail, 123);
    insertTailNode(tail, 56);
    insertTailNode(tail, 23);

    printTraversal(head);

    insertHeadNode(head, 12);
    insertHeadNode(head, 11);

    printTraversal(head);

    insertAtPosition(head, 45, 3);
    insertAtPosition(head, 100, 5);

    printTraversal(head);

    deleteNode(6, head);
    deleteNode(3, head);

    printTraversal(head);
}