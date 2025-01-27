#include<iostream>
using namespace std;
//double linked list
class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    //constructor is points where null points point at 
    Node(int d){
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node(){
        int value = this->data;

        //step 4; only delete the next when next is not equal to null
        if(next != NULL){
            this->next = NULL;
            delete next;
        }
        cout<<"deleted value of the node "<<value<<endl;
    }

    void print(Node* head){
        Node* temp = head;
        while(temp != NULL){
            cout<< temp -> data<< " ";
            temp = temp->next;
        }
        cout<<endl;
    }

    int getLength(Node* &head){
        int len = 1;
        Node* temp = head;
        while(temp != NULL){
            temp = temp->next;
            len++;
        }
        return len;
    }

    void insertAtHead(Node* &head, int data){

        //step 1; create new node to store the data
        //where node prev->null and next->null
        Node* temp = new Node(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }

    void insertAtTail(Node* &tail, int data){

        //step 1; create new node to store the data
        //to point at next 
        Node* temp = new Node(data); 
        //tail->next is pointed at temp
        tail->next = temp;
        temp->prev = tail;
        tail = temp;

    }

    void insertAtPosition(Node* &head, Node* &tail, int position, int data){
        //first position prev 
        if(position == 1){
            insertAtHead(head, data);
            return;
        }

        Node* insertAtNode = new Node(data);
        Node* temp = head;
        int cnt = 1;
        while(cnt < position - 1){
            temp = temp->next;
            cnt++;
        }

        insertAtNode->next = temp->next;
        temp->next = insertAtNode;
        insertAtNode->prev = temp;
        temp->next->prev = insertAtNode;

        //last position will always be null so 
        if(temp == NULL){
            insertAtTail(tail, data);
            return;
        }
    }

    void Delete(int position, Node* &head){
        if(position == 1){
            Node* temp = head;
            head = temp->next;
            temp->next->prev = NULL;
            temp->next = NULL;
            delete temp;
        }else{
            Node* prev = NULL;
            Node* curr = head;
            int cnt = 1;

            while(cnt < position){
                prev = curr;
                curr = curr->next;
                cnt++;
            }

            curr->prev = NULL;
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;

        }
    }
};

int main(){
    Node* node1= new Node(10);
    cout<<node1->data<<endl;
    cout<<node1->prev<<endl;
    cout<<node1->next<<endl;

    //head and tail start with 
    Node* head = node1;
    Node* tail = node1;

    node1->insertAtHead(head, 56);
    node1->print(head);

    node1->insertAtHead(head, 90);
    node1->print(head);

    node1->insertAtTail(tail, 67);
    node1->print(head);

    node1->insertAtTail(tail, 87);
    node1->print(head);

    node1->insertAtPosition(head, tail, 2, 50);
    node1->print(head);

    node1->Delete(6, head);
    node1->print(head);

    node1->Delete(1, head);
    node1->print(head);

    node1->Delete(3, head);
    node1->print(head);
    cout<<head -> data<<" "<<tail -> data<<endl;


}