/*linked list - */
#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node *next;
		
		Node(int data){
			this->data = data;
			this->next = NULL;
		}
};
void insertNextHead(Node* &head, int data){
	Node* temp = new Node(data);
	temp->next = head;
	head = temp;
}
void printNode(Node* &head){
	Node* temp = head;
	
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}
void insertNextTail(Node* &tail, int data){
	Node* temp = new Node(data);
	tail->next = temp;
	tail = temp;	
}
void insertAtPosition(Node* &head, int position, int data){
	Node* temp = head;
	int count =1;
	
	while(count < position-1){
		temp = temp->next;
		count++;
	}
	
	//creating a node for d
	Node* nodeAtPos = new Node(data);
	temp->next = nodeAtPos;
	nodeAtPos->next = temp->next;
}
int main(){
	Node* node1=new Node(12);
	//data of the class node
//	cout<<node1->data<<endl;
	//next is the reference of next node
//	cout<<node1->next<<endl;
	
	//now, head value is node1;
	Node* head = node1;
	printNode(head);
	insertNextHead(head, 34);
	printNode(head);
	insertNextHead(head, 89);
	printNode(head);
	
	
	cout<<endl;
	/*node->next null, node->data 10
	Node* node2=new Node(10);
	Node* tail = node2;
	insertNextTail(tail, 13);
	printNode(tail);
	insertNextTail(tail, 15);
	printNode(tail);
	*/
	Node* node2 = new Node(10);
	Node* tail = node2;
	insertNextTail(tail, 90);
	printNode(tail);
	insertNextTail(tail, 23);
	printNode(tail);
	insertNextTail(tail, 12);
	printNode(tail);
}
