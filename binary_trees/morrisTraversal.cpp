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
void buildLevelTree(Node* &root){
        cout<<"enter  the data ";
        int data;
        cin>>data;

        //root is null:
        root = new Node(data);

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            Node* temp = q.front();
            q.pop();

            cout<<"enter the value for left of "<<temp->data<<" : ";
            int leftData;
            cin>>leftData;
            if(leftData != -1){
                temp -> left = new Node(leftData);
                q.push(temp->left);
            }

            cout<<"enter the value for right of "<<temp->data<<" : ";
            int rightData;
            cin>>rightData;
            if(rightData != -1){
                temp -> right = new Node(rightData);
                q.push(temp -> right);
            }
        }
    }

    vector<int> morrisTraversal(Node* root){
        Node* curr = root;
        vector<int> ans;

        while(curr != NULL){
            if(curr->left == NULL){
                ans.push_back(curr->data);
                curr = curr->right;
            }
            else{

                Node* prev = curr->left;
                while (prev->right != NULL && prev->right != curr){
                    /* code */
                    prev = prev->right;
                }

                if(prev->right == NULL){
                    prev->right = curr;
                    curr = curr->left;
                }
                else{
                    prev->right = NULL;
                    ans.push_back(curr->data);
                    curr = curr->right;
                }
                
            }
        }
        return ans;
    }

int main(){
    Node* root = NULL;
    buildLevelTree(root);

    cout<<"morris traversal : "<<endl;
    vector<int> ans = morrisTraversal(root);

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}