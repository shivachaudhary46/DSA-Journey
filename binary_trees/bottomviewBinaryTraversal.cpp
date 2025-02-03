#include<iostream>
#include<map>
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
void buildTreeByLevel(Node* &root){
    cout<<"enter the root data: ";
    int data;
    cin>>data;

    root = new Node(data);

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        int leftData;
        cout<<"enter the left data for node "<<temp->data<<" : ";
        cin>>leftData;
        if(leftData != -1){
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        int rightData;
        cout<<"enter the right data for node "<<temp->data<<" : ";
        cin>>rightData;
        if(rightData != -1){
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}
void levelOrderTraversal(Node* root){
    if(root == NULL){
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

vector<int> bottomView(Node* root){
    vector<int> ans;

        if(root == NULL){
            return ans;
        }
        map<int, int> topNode;
        queue<pair<Node*, int> > q;
        q.push(make_pair(root, 0));

        while (!q.empty()){
            /* code */
            pair<Node*, int> temp = q.front();
            Node* frontNode = temp.first;
            int hd = temp.second; //horizontal distance
            q.pop();

                topNode[hd] = frontNode->data;

            if(frontNode->left){
                q.push(make_pair(frontNode->left, hd-1));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right, hd+1));
            }

        }

        for(auto i: topNode){
            ans.push_back(i.second);
        }

        return ans;
}
int main(){
    Node* root = NULL;

    buildTreeByLevel(root);
    levelOrderTraversal(root);
    
    vector<int> ans = bottomView(root);
    cout<<"the bottom view of the binary tree : ";
    for(int i=0; i<ans.size(); i++){
        cout<<ans.at(i)<<" ";
    }
    cout<<endl;
}