//depth first search traversal 
#include<iostream>
#include<unordered_map>
#include<set>
#include<vector>

using namespace std;
void adjacency_list(vector< pair<int, int> > &edges, unordered_map<int, set<int> > &adjacency){

    for(int i=0; i<edges.size(); i++){

        int a = edges[i].first;
        int b = edges[i].second;

        adjacency[a].insert(b);
        adjacency[b].insert(a);
    }
}
void print(unordered_map<int, set<int> > adjacency){
    int s = adjacency.size();
    for(auto &[key, neighbours] : adjacency){
        cout<<key<<"-> ";
        for(auto neighbor: neighbours){
            cout<<neighbor<<", ";
        }
        cout<<endl;
    }
}
int main(){
    vector<pair<int, int> > edges;
    edges.push_back(make_pair(0, 1)); 
    edges.push_back(make_pair(0, 2));
    edges.push_back(make_pair(0, 3));

    edges.push_back(make_pair(1, 4));
    edges.push_back(make_pair(1, 7));
    edges.push_back(make_pair(2, 5));
    edges.push_back(make_pair(3, 6));

    unordered_map<int, set<int> > adjacency;
    adjacency_list(edges, adjacency);

    print(adjacency);
}