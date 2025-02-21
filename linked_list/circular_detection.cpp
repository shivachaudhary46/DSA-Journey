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
        cout<<"deleted data :"<<data<<endl;
        if(right != NULL){
            right = NULL;
            delete right;
        }
    }

};
Node* circularDetection(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL || fast->right != NULL){
        slow = slow->right;
        fast = fast->right->right;
    }
    return slow;
}
int main(){
    Node* head = new Node(1);
    head->right = new Node(2);
    head->right->right = new Node(4);
    head->right->right->right = new Node(5);
    head->right->right->right->right = head->right->right;

    Node* circle = circularDetection(head);
    cout<<"-> "<<circle->data<<endl;
}