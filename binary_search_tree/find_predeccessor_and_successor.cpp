#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};
Node* insertion(Node* &root, int data){

        //base case
        if(root == NULL){
            root = new Node(data);
            return root;
        }

        //recursive calls 
        if(data < root->data){
            root->left = insertion(root->left, data);
        }
        if(data > root->data){
            root->right = insertion(root->right, data);
        }

        return root;
    }

    void takeInput(Node* &root){
        int data;
        cout<<"enter the data : ";

        while(true){ 
            cin>>data;
            if(data == -1) break;
            root = insertion(root, data);
        }
    }

    void levelOrderTravrsal(Node* root){
        if(root == NULL) return;
        //step 1* create queue, push root in queue and push NULL
        queue<Node*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            //step 2: while queue is not empty store front value of queue and pop 
            Node* temp = q.front();
            q.pop();
            if(temp == NULL){
                cout<<endl;
                if(!q.empty()){
                    q.push(NULL);
                }
            }else{
                cout<<temp->data<<" ";
                if(temp -> left){
                    q.push(temp->left);
                }
                if(temp -> right){ 
                    q.push(temp->right);
                }
            }
        }
    }

    Node* minNode(Node* root){
        Node* temp = root;

        while(temp -> left != NULL){
            temp = temp->left;
        }
        return temp;
    }

    Node* maxNode(Node* root){
        Node* temp = root;

        while (temp -> right != NULL){
            temp = temp -> right;
        }
        return temp;
    }

    void preAndSucess(Node* root, Node* &pre, Node* &succ, int target){
       Node* curr = root;

       while(curr != NULL){
        if(curr -> data < target){
            pre = curr;
            curr = curr -> right;
        }
        else if(curr -> data > target){
            succ = curr;
            curr = curr -> left;
        }
        else{
            
            //find the predecessor 
            //value in left 
            if(curr->left != NULL){
                pre = maxNode(curr->left);
            }

            //find the successor 
            //value in the right
            if(curr->right != NULL){
                succ = minNode(curr->right);
            }

            break;
        }
       }
    }

int main(){
    Node* root = NULL;

    takeInput(root);
    cout<<endl;
    levelOrderTravrsal(root);

    int key = 65;

    Node* pre = NULL;
    Node* succ = NULL;

    preAndSucess(root, pre, succ, key);

    if(pre != NULL){
        cout<<"predecessor of the key "<<key<<" is "<<pre->data<<endl;
    }else{
        cout<<"no predecessor of the key "<<endl;
    }
    
    if(succ != NULL){
        cout<<"successor of the key "<<key<<" is "<<succ->data<<endl;
    }else{
        cout<<"no successor of the key "<<endl;
    }

}