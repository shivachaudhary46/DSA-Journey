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

    vector<int> topView(Node* root){
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

            if(topNode.find(hd) == topNode.end()){
                topNode[hd] = frontNode->data;
            }

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
    buildLevelTree(root);
    levelOrderTravrsal(root);

    vector<int> ans = topView(root);
    cout<<"top view of the binary tree : ";
    int s = ans.size();
    for(int i=0; i<s; i++){
        cout<<ans[i]<<" ";
    }
}