#include<iostream>
using namespace std;
//circular linked list 
class Node{
    public:
    int data;
    Node* next;

    //constructor to initialize
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    //destructor to delete the value 
    ~Node(){

        int val = this->data;
        if(this->next != NULL){
            this->next = NULL;
        }
        cout<<"deleted Node "<<val<<endl;
    }

    //return true if circular linked list is present
    bool isCircular(Node* &tail){
        Node* curr = tail;

        //curr node traverse upto tail or null 
        while(curr != tail && curr != NULL){
            curr = curr->next;
        }

        if(curr == tail){
            return 1;
        }else{
            return 0;
        }
    }

    //insert After element 
    //wil only insert if that data is present in the linked list 
    void insertAtNode(Node* &tail, int element, int data){

        //when linked list is null 
        if(tail == NULL){
            Node* newNode = new Node(data);
            newNode->next = newNode;
            tail = newNode;
            return ;
        }else{

            //when linked list has certain list
            //search for the value to insert after data 
            bool found = false;

            Node* curr = tail->next;
            while(curr != tail){

                if(curr->data == element){
                    found = true;
                    break;
                }
                curr = curr->next;
            }

            if(found){

                //assume that data has been found at the curr node
                Node* newNode = new Node(data);
                newNode->next = curr->next;
                curr->next = newNode; 
            } else {
                cout<<"no insertion need to made cause "<<element<<" element is not pressent."<<endl;
            }
        }
    }

    //deletion node
    void deleteNode(Node* &tail, int position){
        //if tail -> next == NULL or (!tail-next)
        if(tail->next == NULL){
            delete tail;
            tail = NULL;
        }

        //this function delete node if position is greater than 0
        //deleting the node 
        if(tail == NULL){
            cout<<"circular linked list is empty !!!";    
            return;    
        }else{
            bool found = false;
            int count = 0;
            Node* prev = NULL;
            Node* curr = tail;

            do{
                if(count == position){
                    found = true;
                    break;
                }

                prev = curr;
                curr = curr->next;
                count++;
            }while(curr != tail);

            //if found delete element
            if(found){
                Node* temp = curr;
                prev->next = curr->next;
                delete temp;
            }else{
                cout<<"given position not found "<<position<<endl;
            }
        }

        
    }

    //circular linked list traversal 
    void circularTraversal(Node* &tail){
        if(tail == NULL){
            cout<<"linked list is empty !!!";
        }

        // if(isCircular(tail)){
            Node* curr = tail->next;

            //assume that circular linked list is present 
            do{
                cout<<curr->data<<" ";
                curr = curr->next;
            }while(curr != tail->next);
        // }else{
        //     cout<<" circular linked list is not present !!!";
        // }
        cout<<endl;
    }
};
int main(){
    Node* node1 = new Node(14);
    Node* tail = node1;

    node1->next = new Node(25);
    node1->next->next = new Node(4);
    node1->next->next->next = new Node(5);
    node1->next->next->next->next = new Node(6);
    node1->next->next->next->next = node1;

    node1->circularTraversal(tail);

    bool isCircularList = node1->isCircular(tail);
    cout<<"does linked list is circular --- "<<(isCircularList ? "true" : "false")<<endl;

    node1->insertAtNode(tail, 5, 12);

    node1->circularTraversal(tail);

    node1->insertAtNode(tail, 4, 12);

    node1->circularTraversal(tail);

    node1->deleteNode(tail, 0);

    node1->circularTraversal(tail);
}