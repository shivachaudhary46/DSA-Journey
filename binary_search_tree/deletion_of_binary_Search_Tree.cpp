#include<iostream>
#include<queue>
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

    ~Node(){
        if(left != NULL) delete left;
        if(right != NULL) delete right;
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

    Node* deletionFromBST(Node* root, int key){
        if(root == NULL){
            return NULL;
        }

        if(root -> data == key){
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }

            if(root->left != NULL && root->right == NULL){
                Node* temp = root->left;
                delete root;
                return temp;
            }

            if(root->right != NULL && root->left == NULL){
                Node* temp = root->right;
                delete root;
                return temp;
            }

            if(root->right != NULL && root->left != NULL){
                int minimum = minNode(root->right)->data;
                root->data = minimum;
                root->right = deletionFromBST(root->right, minimum);
            }
        }
        else if(key > root->data){
            root->right = deletionFromBST(root->right, key);
        }else{
            root->left = deletionFromBST(root->left, key);
        }
    }
int main(){
    Node* root = NULL;

    takeInput(root);
    cout<<endl;
    levelOrderTravrsal(root);

    Node* toDelete = deletionFromBST(root, 7);
    cout<<"deleted  "<<toDelete->data<<endl;

      levelOrderTravrsal(root);
}