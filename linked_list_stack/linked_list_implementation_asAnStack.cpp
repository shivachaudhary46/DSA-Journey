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
        cout<<"memory freed of the : "<<data<<" data "<<endl;
        if(right != NULL){
            right = NULL;
            delete right;
        }
    }

};
void push(Node* &top, int element){
        Node* newNode = new Node(element);

        if(top == NULL){

            top = newNode;
        }else{

            newNode->right = top;
            top = newNode;
        }
    }
    int top(Node* top){

        if(top == NULL){
            return -1;
        }else{
            return top->data;
        }
    }
    void pop(Node* &top){

        if(top == NULL){
            cout<<"stack is underflow "<<endl;
            return;
        }else{
            Node* temp = top;
            top = top->right;
            delete temp;
        }
    }

int main(){
    Node* head = NULL;
    push(head, 12);
    cout<<"top of the stack "<<top(head)<<endl;

    push(head, 13);
    push(head, 23);
    push(head, 45);
    push(head, 67);

    cout<<"top of the stack "<<top(head)<<endl;

    pop(head);
    cout<<"top of the stack "<<top(head)<<endl;

    //in last desctructor called hunxa ni ta if pop grada kheri right ko null garena 
    //bhane ta destructor le palai pilo sabai delete garddinxa ni ta
}