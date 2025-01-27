//floyd fulkerson cycle finding algorithn
#include<iostream>
using namespace std;

//traverse the node using two pointers
//slow pointer is moved one node at time
//fast pointer is moved two node at time
//there will come one node where both slow and fast pointer
//meet at same time thn linkd list exist 
//if linked list does not exist means it doesnn`t have a loop

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    Node* floydCycle(Node* head){
        Node* fast = head->next;
        Node* slow = head;

        //empty list condition
        //make sure if ll is empty return true
        if(head == NULL ) return NULL;

        //one node
        if(head->next == NULL) return;

        //
        while(slow==NULL && fast==NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                return slow;
            }
        }
        return;        
    }

    Node* intersectionPointCycle(Node* head){

        Node* fast = floydCycle(head);

        Node* slow = head;

        while(fast != slow){
            fast = fast -> next;
            slow = slow -> next;
        }

        return slow;
    }

    void traversal(Node* head){
        Node* temp = head;
        while(temp != head){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};
int main(){
    Node* node1 = new Node(10);

    Node* head = node1;
    head->next = new Node(15);
    head->next->next = new Node(60);
    head->next->next->next = new Node(67);
    head->next->next->next->next = new Node(30);
    head->next->next->next->next->next = head->next->next;

    node1->traversal(head);
    cout<<node1->floydCycle(head)<<endl;
    cout<<node1->intersectionPointCycle(head)<<endl;
}