#include<iostream>
using namespace std;
//linked list 
class Node{
    public:
        int data;
        Node* next;

    //constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    //destructor 
    ~Node(){

        //updaating the value 
        int value = this->data;

        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
    }

    //update head with new data 
    void insertAtHead(Node* &head, int data){
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }

    //when head goes to null while loop ends 
    void print(Node* &head){
        if(head  == NULL){
            cout<<"linked list is null "<<endl;
            return;
        }
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    void insertAtTail(Node* &tail, int data){

        //create new node  with  tail;
        Node* temp = new Node(data);

        //if tail node is null the new node becomes (head and tail)
        if(tail == NULL) {
            tail = temp;
        }else{
            tail->next = temp;
            tail = temp;
        }
    }

    void insertAtPosition(Node* &head, Node* &tail, int position, int data){
        if(position == 1){
            insertAtHead(head, data);
            return;
        }
          
        //insert at the head of the linked list 
        Node* temp = head;
        int count = 1;
        while(count < position-1){
            temp = temp->next;
            count++;
        }

        //insert at niddle positions 
        Node* insertAtPos = new Node(data);
        insertAtPos->next = temp->next;
        temp->next = insertAtPos; 
        //insert at last positions 
        if(temp->next == NULL){
            insertAtTail(tail, data);
            return;
        } 
    }

    void Delete(int position, Node* &head){
        if(position == 1){
            Node* temp = head;
            head = head->next;
            //memory free start node 
            temp->next = NULL;
            delete temp;
        }else{

            //deleting any middle or last node
            Node* prev = NULL;
            Node* curr = head;
            int cnt=1;
            while(cnt < position){
                prev = curr;
                curr = curr->next;
                cnt++;
            }
            prev->next = curr->next;
            //memory free spacing 
            curr->next = NULL;
            delete curr;
        }
    }
   
};
int main(){
    Node* node1 = new Node(10);
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl; //first address of the node is
    //NULL 
    cout<<endl;
    Node* head = node1;
    // //10 node address is pointed to the  null and 5 node is 
    // //pointed to 10 which is pointed by head 
    // node1->insertAtHead(head, 5);
    // node1->print(head);

    // //34 is head and its node is located at the 10 node address 
    // node1->insertAtHead(head, 34);
    // node1->print(head);

    cout<<"printing the linked list according to tail; "<<endl;
    Node* tail = node1;
    node1->insertAtTail(tail, 24);
    node1->print(head);
    cout<<endl;

    //tail node rakhye suppose tara head according print garey whyy ????????????????????
    node1->insertAtTail(tail, 45);
    node1->print(head);

    //1 based indexing mode 
    node1->insertAtPosition(head, tail, 2, 6);
    node1->print(head);

    node1->insertAtPosition(head, tail, 1, 5);
    node1->print(head);

    //last node ma chai insert hudena second last node ma 
    //chai insert vhayo so 
    //insert at tail node 
    node1->insertAtPosition(head, tail, 5, 4);
    node1->print(head);

    node1->insertAtPosition(head, tail, 6, 78);
    node1->print(head);

    node1->Delete(5, head);
    node1->print(head);

    node1->Delete(6, head);
    node1->print(head);

    node1->print(head);

    // node1->Delete(0, head); 
    node1->Delete(1, head);
    node1->print(head);


    node1->Delete(1, head);
    node1->print(head);

}