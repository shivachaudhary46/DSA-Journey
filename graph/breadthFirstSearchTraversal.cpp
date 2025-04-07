#include<iostream>
#include<unordered_map>
#include<set>
#include<queue>
using namespace std;


void prepareAdjList(unordered_map<int, set<int> > &adjList, vector<pair<int, int> > edges){
    
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].insert(v);
        adjList[v].insert(u);
    }  
}

void bfs(unordered_map<int, set<int> > &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node){

    queue<int> q;
    q.push(node);

    visited[node] = 1;
    while(!q.empty()){

        int frontNode = q.front();
        q.pop();

        //store the frontnode into ans 
        ans.push_back(frontNode);
        
        //traverse all the  neighbours of frontNode
        for(auto i: adjList[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }

    }
}

vector<int> BFS(int vertex, vector<pair<int, int> > &edges){

    unordered_map<int, set<int> > adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;

    prepareAdjList(adjList, edges);

    //traverse all components of a graph 
    for(int i=0; i<vertex; i++){
        if(!visited[i]){
            bfs(adjList, visited, ans, i);
        }
    }

    return ans;
}

int main(){
    int vertex = 8;
    vector<pair<int, int> > edges;
    edges.push_back(make_pair(0, 1));
    edges.push_back(make_pair(0, 2));
    edges.push_back(make_pair(0, 3));
    edges.push_back(make_pair(1, 4));
    edges.push_back(make_pair(1, 7));
    edges.push_back(make_pair(2, 5));
    edges.push_back(make_pair(3, 6));

    vector<int> ans;
    ans = BFS(vertex, edges);

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<"->";
    }
    cout<<endl;
}