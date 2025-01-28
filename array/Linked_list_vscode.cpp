/*linked list */
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

};
void insertHead(Node* &head, int data){
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}
void insertTail(Node* &tail, int data){
    Node *temp = new Node(data);
    if(tail == NULL){ //if the list is empty 
        tail = temp; //asign the new node to tail
        return;
    }
    tail->next = temp; //link the current tail node to the new node
    tail = temp; //move the tail pointer to new node
}
void insertPostion(Node* &head, int position, int data){
    Node* temp = head;
    int count = 1;

    while(count < position -1){
        temp = temp->next;
        count++;
    }

    //creating new node with the next is null
    Node* nodeAt = new Node(data);
    temp->next = nodeAt;
    nodeAt->next = temp->next;
}
void print(Node* &head){
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" "; //acess the data of the head or tail pointer 
        temp = temp->next; //move the tail pointer to the new node 
    }
}
int main(){
    Node* node1 = new Node(10);

    Node *head = node1;
    Node *tail = node1;

    // insertHead(head, 12);
    // insertHead(head, 13);
    // insertHead(head, 14);
    // print(head);

    insertTail(tail, 10);
    insertTail(tail, 9);
    insertTail(tail, 8);
    insertTail(tail, 7);
    print(head);

    // insertPostion(head, 3, 100);
    // print(head);
}