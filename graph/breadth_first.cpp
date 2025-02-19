#include<iostream>
#include<queue>
#include<list>
#include<unordered_map>
using namespace std;
void printAdjacency(unordered_map<int, list<int> > &adjList, vector<pair<int, int> > &edge){
    for(int i=0; i<edge.size(); i++){
        int u = edge[i].first;
        int v = edge[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}
void bfs(unordered_map<int, list<int> > adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node){
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        
        ans.push_back(frontNode);

        for(const auto i:adjList[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }

    }
    return ans;
}
void BFS(vector<pair<int, int> > &edge){
    unordered_map<int, list<int> > adjList; 
    vector<int> ans;
    unordered_map<int, bool> visited;

    for(int i=0; i<vertex; i++){
        if(!visited[i]){
            bfs(adjList,  visited, ans, n);
        }
    }
}
int main(){

}