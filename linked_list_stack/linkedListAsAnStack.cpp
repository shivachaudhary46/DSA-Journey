#include<iostream>
using namespace std;
//in a linked list size cannot be defined because 
class Node{
    public:
    int data;
    Node* next;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    
    ~Node(){
        int val = this->data;
        if(this->next != NULL){
            next = NULL;
            delete next;
        }

        cout<<"node for the value "<< val<< " has been deleted "<<endl;
        cout<<"memory freed "<<endl;
    }
    void push(Node* &top, int element){
        //push in the top of element 
        Node* newNode = new Node(element);

        //if top Node is empty then top and tail will be same pointed 
        //to newNode
        if(top == NULL){
            top = newNode;
            return;
        }else{
            newNode -> next = top; 
            top = newNode;
        }
    }

    void traversal(Node* top){
        if(top == NULL){
            cout<<"linked list as an stack is NULL"<<endl;
        }

        //traverse upto end when top is NULL 
        while(top != NULL){
            cout<<top->data<<endl;
            top = top -> next;
        }

    }

    void pop(Node* &top){

        //check whether the stack is empty or not 
        //if stack is empty no need to pop element 
        if(top == NULL){
            cout<<"stack is empty";
        }else{
             
            Node *temp = top;

            //update top element to next node before deleting previous 
            //node so link is not severed 
            top = top->next; 
            delete temp;
        }
    }

    //top of the element is peek in our code case 
    int peek(Node* top){
        if(top == NULL){
            cout<<"linked list is NULL "<<endl;
            return -1;
        }else{
            // cout<<"linked current top value is "<<endl;
            return top->data;
        }

    }
};
int main(){
    Node* node1 = new Node(45);
    Node* top = node1;
    
    node1->push(top, 45);
    node1->push(top, 56);

    node1->traversal(top);

    node1->pop(top);

    node1->traversal(top);

    //top element in the data 
    // cout<<top->data<<endl;

    cout<<"linked list curr top value is "<<node1->peek(top);

}