#include<iostream>
#include<unordered_map>
#include<set>
#include<vector>

using namespace std;

void prepareAdjList(unordered_map<int, set<int> > &adjList, vector<pair<int, int> > edges){
    
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].insert(v);
        adjList[v].insert(u);
    }  
}

void dfs(unordered_map<int, set<int> > &adjlist, unordered_map<int, bool> &visited, vector<int> &component, int node){
    
    component.push_back(node);
    visited[node] = true;
    for(auto i: adjlist[node]){

        if(!visited[i]){
            dfs(adjlist, visited, component, i);
        }
    }
}

vector<vector<int> > depthFirstSearch(int vertex, vector<pair<int, int> > &edges){

    unordered_map<int, set<int> > adjlist;
    unordered_map<int, bool> visited;
    vector<vector<int> > ans;

    //preparing the adjacent list 
    prepareAdjList(adjlist, edges);

    //traverse all the components 
    for(int i=0; i<vertex; i++){
        if(!visited[i]){
            vector<int> component;
            dfs(adjlist, visited, component, i);
            ans.push_back(component);
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

    vector<vector<int> > ans;
    ans = depthFirstSearch(vertex, edges);

    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl; 
    }
    cout<<endl;
}