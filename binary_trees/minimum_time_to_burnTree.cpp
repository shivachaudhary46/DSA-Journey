//minimum time to burn a tree
#include<iostream>
#include<map>
#include<queue>

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
Node* createparentMapping(Node* root, map<Node*, Node*> &mapping, int target){
        Node* res = NULL;

        queue<Node*> q;
        q.push(root);
        mapping[root] = NULL;
        while(!q.empty()){

            Node* front = q.front();
            q.pop();

            if(front->data == target){
                res = front;
            }

            if(front->left){
                mapping[front->left] = front;
                q.push(front->left);
            }

            if(front->right){
                mapping[front->right] = front;
                q.push(front->right);
            }
        }

        return res;
    }
    int minTimeToBurnTree(Node* root, map<Node*, Node*> &nodeToParent){
        map<Node*, bool> visited;
        queue<Node*> q;

        q.push(root);
        visited[root] = true;

        int ans = 0;

        while(!q.empty()){

            //flag 
            bool flag = 0;

            int size = q.size();

            for(int i=0; i<size; i++){
                //process neighbouring nodes 
                Node* front = q.front();
                q.pop();

                if(front->left && !visited[front->left]){
                    flag = 1;
                    visited[front->left] = true;
                    q.push(front->left);
                }

                if(front->right && !visited[front->right]){
                    flag = 1;
                    visited[front->right] = true;
                    q.push(front->right);
                }

                if(nodeToParent[front] && !visited[nodeToParent[front]]){
                    flag = 1;
                    visited[nodeToParent[front]] = true;
                    q.push(nodeToParent[front]);
                }
            }
            if(flag == 1){
                ans++;
            }
        }

        return ans;
    }

    int minTime(Node* root, int target) {
        
        //step 1: create a node to parent mapping 
        map<Node*, Node*> nodeToParent;
        Node* targetNode = createparentMapping(root, nodeToParent, target);
        //step 2: find target nod

        //step 3: insert unique elements in queue and mark them 
        //visited by mapping 
        return minTimeToBurnTree(targetNode, nodeToParent);
    }

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
int main(){
    Node* root = NULL;

    buildLevelTree(root);
    cout<<endl;
    levelOrderTravrsal(root);

    int target = 8;
    cout<<"the minimum time to burn a tree is "<<minTime(root, target)<<endl;
}