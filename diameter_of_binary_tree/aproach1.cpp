#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
    void BuildlevelOrderTree(Node* &root){
        cout<<"enter the data: ";
        int data;
        cin>>data;

        root = new Node(data);

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            Node* temp = q.front();
            q.pop();

            cout<<"enter the integer for left element "<<temp->data<<" : ";
            int leftData;
            cin>>leftData;
            if(leftData != -1){
                temp -> left = new Node(leftData);
                q.push(temp->left);
            }

            cout<<"enter the integer for right element "<<temp->data<<" : ";
            int rightData;
            cin>>rightData;
            if(rightData != -1){
                temp -> right = new Node(rightData);
                q.push(temp->right);
            }
        }
    }

    void levelOrderTraversal(Node* root ){
        if(root == NULL ){
            return;
        }

        queue<Node*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            Node* temp = q.front();
            q.pop();

            if(temp == NULL){
                cout<<endl;
                if(!q.empty()){
                    q.push(NULL);
                }
            }else{
                cout<<temp->data<< " " ;
                if(temp->left){
                    q.push(temp->left);
                }

                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
    }
    pair<int, int> diameter_of_tree(Node* root){
        if(root == NULL){
            pair<int, int> p;
            p = make_pair(0, 0);
            return p;
        }

        pair<int, int> leftans = diameter_of_tree(root -> left);
        pair<int, int> rightans = diameter_of_tree(root -> right);

        int h1 = leftans.first;
        int h2 = rightans.first;
        int h3 = leftans.second + 1 + rightans.second;

        pair<int, int> ans;
        ans.first = max(h1, max(h2, h3));
        ans.second = max(h1, h2) + 1;

        return ans;
    }

    int diameterTree(Node* &root){
        pair<int, int> ans = diameter_of_tree(root);
        return ans.first;
    }

int main(){
    Node* root = NULL;

    BuildlevelOrderTree(root);
    levelOrderTraversal(root);
    cout<<"largest diameter in tree "<<diameterTree(root)<<endl;

}