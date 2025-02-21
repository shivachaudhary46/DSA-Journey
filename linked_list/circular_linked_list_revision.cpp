#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    ~Node(){
        cout<<"deleted data : "<<data<<endl;
        if(next != NULL){
            delete next;
        }
    }
};
bool isCircular(Node* head){

    //if head is equal to null
    if(head == NULL){
        cout<<"linked list is empty"<<endl;
    }

    Node* curr = head->next;
    while(curr != head && curr != NULL){
        curr = curr -> next;
    }

    if(curr == head){
        return 1;
    }else{
        return 0;
    }
}
void traversal(Node* head){
    if(head == NULL){
        cout<<"circular linked list is empty"<<endl;
    }

    //assum that there is no 
    Node* temp = head->next;
    do{
        cout<<temp->data<<" -> ";
        temp = temp -> next;
    }while (temp != head->next);
    
    cout<<endl;
}
void insertAtElement(Node* &head, int element, int data){
    Node* newNode = new Node(data);

    //if the head is null then the linked the head pointer to its own]
    if(head == NULL){
        head = newNode;
        head->next = newNode;
    }
    //if the head is not null then
    else{

        bool found = false;
        Node* temp = head->next;
        do{

            if(element == temp->data){
                found = true;
                break;
            }
            temp = temp->next;
        }while(temp != head->next);

        if(found){
            newNode->next = temp->next;
            temp->next=newNode;
        }else{
            cout<<"element node does not found in circular linked list"<<endl;
        }
    }
}
int getLength(Node* head){
    int count=0;
    Node* temp = head->next;
    do{
        count++;
        temp = temp->next;
    }while(temp != head->next);

    return count;
}
void insertAtPosition(Node* head, int position, int data){
    Node* newNode = new Node(data);

    //step 1: if the head is null then point to itself 
    if(head == NULL){
        head = newNode;
        head->next = newNode;
    }
    //step 2: if the position found insert at that position
    else{

        bool found = false;
        int count = 0;
        int length = getLength(head);
        Node* temp = head;

        //step 3: if the count is equal to the position then 
        //found = true; 
        do{
            if(count == position-1){
                found = true;
                break;
            }
            temp = temp -> next;
            count++;
        }while(count % length != 0);

        //step 4: insert the newnode at position 
        if(found){
            newNode->next = temp->next;
            temp->next = newNode;
        }else{
            cout<<" position out of the bounds "<<endl;
        }

    }
}
void deletionNodeAtelement(Node* head, int element){
    Node* prev = NULL;
    Node* curr = head;
    

    if(head == NULL){
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }else{
        bool found = false;
        do{
            if(element == curr->data){
                found = true;
                break;
            }
            prev = curr;
            curr = curr -> next;
        }while(curr != head);
    
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
    
}
void deleteAtPosition(Node* head, int position){
    Node* prev = NULL;
    Node* curr = head;

    if(position == 1){
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }else{
        bool found = false;
        int count = 0;
        int length = getLength(head);
        do{
            if(count == position){
                found = true;
                break;
            }
            count++;
            prev = curr;
            curr = curr -> next;
        }while(count % length != 0);

        if(found){
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
        }else{
            cout<<"position does not found"<<endl;
        }
    }
}
int main(){
    Node* head = new Node(1);
    head -> next = new Node(5);
    head -> next -> next = new Node(8);
    head -> next -> next -> next = new Node(12);
    head -> next -> next -> next -> next= head;

    if(isCircular(head)){
        cout<<"linked list is circular"<<endl;
    }else{
        cout<<"linked list is not circular"<<endl;
    }

    traversal(head);
    insertAtElement(head, 8, 14);

    traversal(head);
    cout<<"length of the first circular linked list : "<<getLength(head)<<endl;

    Node* head1 = NULL;
    insertAtElement(head1, 1, 12);
    traversal(head1);

    insertAtElement(head1, 12, 3);
    insertAtElement(head1, 12, 6);
    insertAtElement(head1, 12, 18);
    traversal(head1);

    insertAtPosition(head1, 3, 5);
    traversal(head1);

    deletionNodeAtelement(head1, 18);
    traversal(head1);

    deleteAtPosition(head1, 2);
    traversal(head1);
}
