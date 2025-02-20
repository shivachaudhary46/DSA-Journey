#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    
    //Note: left = prev and right = next
    Node(int data){
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }

    ~Node(){
        cout<<"deleted data :"<<data<<endl;
        if(right != NULL){
            delete right;
        }
    }
};
void insertAtHead(Node* &head, int element){
    Node* temp = new Node(element);

    if(head == NULL){
        head = temp;
    }else{
        temp -> right = head;
        head-> left = temp;
        head = temp;
    }
}
void insertAtTail(Node* &tail, int element){
    Node* newNode = new Node(element);

    if(tail == NULL){
        tail = newNode;
    }else{
        tail -> right = newNode;
        newNode -> left = tail;
        tail = newNode;
    }
}
int getLength(Node* head){
    Node* temp = head;
    int length = 0;

    while(temp != NULL){
        temp = temp -> right;
        length = length + 1;
    }

    return length;
}
void insertAtPosition(Node* &head, Node* &tail, int position, int element){
    //if head is null or position is equal to 1
    int length = getLength(head);
    if(head == NULL || position == 1){
        insertAtHead(head, element);
    }
    Node* prev = NULL;
    Node* curr = head;
    int count = 0;
    while(count < position-1){
        prev = curr;
        curr = curr -> right;
        count++;
    }

    Node* newNode = new Node(element);
    newNode -> right = curr;
    newNode->left = prev;
    if(curr != NULL){

        curr->left = newNode;
    }
    prev->right = newNode;

    if(length == position){
        insertAtTail(tail, element);
    }
}
void print(Node* head){

    while(head != NULL){
        cout<<head->data<<" -> ";
        head = head -> right;
    }

    cout<<endl;
}
void deleteAtPosition(Node* &head, int position){
    if(head == NULL){
        cout<<"list is empty!!!"<<endl;
        return;
    }

    if(position == 1){
        Node *temp = head;
        head = head -> right;
        if(head !=  NULL){
            head->left = NULL;
        }
        delete temp;
        return;
    }

    int count = 1;
    Node* prev = NULL;
    Node* curr = head;
    while(count < position && curr != NULL){
        prev = curr;
        curr = curr -> right;
        count++;
    }

    // If the position is out of bounds (curr will be NULL)
    if (curr == NULL) {
        cout << "Position out of bounds!" << endl;
        return;
    }

    // If we're deleting the last node
    if (curr->right == NULL) {
        prev->right = NULL;
    } else {
        // For middle or non-tail nodes, fix the links
        prev->right = curr->right;
        curr->right->left = prev;
    }

    // Delete the node
    delete curr;
}
int main(){
    Node* head = NULL;
    Node* tail = NULL;


    insertAtTail(tail, 3);
    head = tail;
    insertAtTail(tail, 5);
    insertAtTail(tail, 7);
    print(head);

    insertAtPosition(head, tail, 3, 4);
    insertAtPosition(head, tail, 4, 8);
    print(head);

    cout<<getLength(head)<<endl;

    deleteAtPosition(head, 3);
    print(head);
}