#include<iostream> 
#include<queue>
#include<list>
#include<unordered_map>
using namespace std;

    void prepareAdjList(unordered_map<int, list<int> > &adjlist, vector<pair<int, int> > & edges){
        for(int i=0; i<edges.size(); i++){
            int u = edges[i].first;
            int v = edges[i].second;

            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }
    }
    void bfs(unordered_map<int, list<int> > adjlist, vector<int> ans, unordered_map<int, bool> visited, int node){

        queue<int> q;
        q.push(node);

        visited[node] = 1;

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();

            ans.push_back(frontNode);

            for(auto i:adjlist[frontNode]){

                if(!visited[i]){
                    q.push(i);

                    visited[i] = 1;
                }
            }
        }
    }
    vector<int> BFS(int vertex, vector<pair<int, int> > &edges){
        unordered_map<int, list<int> > adjlist;
        unordered_map<int, bool> visited;
        vector<int> ans;
        
        //prerpare adj list
        prepareAdjList(adjlist, edges);

        //traversal 
        for(int i=0; i<vertex; i++){
                    if(!visited[i]){
                        bfs(adjlist, ans, visited, i);
                    }
        }

        return ans;
    }
    
int main(){
    vector<int> ans;

    vector<pair<int, int> > edges;
    edges.push_back(make_pair(3, 4));
    edges.push_back(make_pair(3, 7));
    edges.push_back(make_pair(7, 1));
    edges.push_back(make_pair(1, 5));
    edges.push_back(make_pair(4, 5));
    edges.push_back(make_pair(4, 1));
    edges.push_back(make_pair(3, 1));

    int vertex = 0;

    for(auto &edge: edges){
        vertex = max(edge.first, edge.second);
    }
    vertex ++;

    
    ans = BFS(vertex, edges);

    for(int i=0; i<ans.size(); i++){
        cout<<i<<" ";
    }
}