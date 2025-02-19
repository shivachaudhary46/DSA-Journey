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
Node* merge(Node* head1, Node* head2){
    Node* head = NULL;
    Node* tail =  NULL;

    while(head1 != NULL && head2 != NULL){

        if(head1->data < head2->data){

            if(head == NULL){
                head = head1;
                tail = head1;
                head1 = head1->right;
            }else{
                tail -> right = head1;
                tail = tail -> right;
                head1 = head1->right;
            }
        }else{

            if(head == NULL){
                head = head2;
                tail = head2;
                head2 = head2->right;
            }else{
                tail -> right = head2;
                tail = tail -> right;
                head2 = head2->right;
            }
        }
    }

    while(head1 != NULL){
        tail -> right = head1;
        tail = tail -> right;
        head1 = head1->right;
    }

    while(head2 != NULL){
        tail -> right = head2;
        tail = tail -> right;
        head2 = head2->right;
    }

    return head;
}

int main(){
    //linked list 1 
    Node* head = NULL;
    Node* tail = NULL;

    insertTailNode(tail, 5);
    head = tail;

    insertTailNode(tail, 9);
    insertTailNode(tail, 15);
 
    printTraversal(head);
    
    //linked list 2 
    Node* head1 = NULL;
    Node* tail1 = NULL;

    insertTailNode(tail1, 2);
    head1 = tail1;
    insertTailNode(tail1,6);
    insertHeadNode(tail1, 11);

    printTraversal(head1);

    //merge two linked list 
    Node* merged = merge(head1, head);
    printTraversal(merged);

}