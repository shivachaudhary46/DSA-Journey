//merge linked list 
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};
Node* getMid(Node* head){
    Node* fast = head;
    Node* slow = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;

}
Node* merge(Node* left, Node* right){
    if(left == NULL){
        return right;
    }

    if(right == NULL){
        return left;
    }

    Node* ans = new Node(-1);
    Node* temp = ans;

    while(right != NULL && left != NULL){
        if(left->data < right->data){
            temp->next = left;
            temp = left;
            left = left -> next;
        }else{
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while(left != NULL){
        temp->next = left;
        temp = left;
        left = left -> next;
    }

    while(right != NULL){
        temp->next = right;
        temp = right;
        right = right -> next;
    }

    ans = ans -> next;
    return ans;
}
Node* mergeSortLL(Node* head){

    //base step of recursion function 
    if(head == NULL || head->next == NULL){
        return head;
    }

    //step 1; break the ll  in  two halvs 
    Node* mid = getMid(head);
    Node* right = mid->next;
    Node* left = head;

    mid->next = NULL;

    //step 2; sort the each ll 
    left = mergeSortLL(left);
    right = mergeSortLL(right);

    //step 3; merge the sorted ll
    return merge(left, right);

}
 
    //traverse of linked list and print its element 
    void traversal(Node* head){

        //if head is empty sshow ll iss empty 
        if(head == NULL){
            cout<<"ll is empty "<<endl;
        }

        Node* curr  = head;

        while(curr != NULL){
            cout<<curr->data<<" ";
            curr = curr->next;
        }

    }
int main(){
    Node* node1 = new Node(10);

    Node* head = node1;
    head->next = new Node(2);
    head->next->next = new Node(60);
    head->next->next->next = new Node(67);
    head->next->next->next->next = new Node(30);
    head->next->next->next->next->next = new Node(90);

    Node* ans = mergeSortLL(head);
    traversal(ans);
}