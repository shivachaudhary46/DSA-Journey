//breath first traversal 
#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
using namespace std;

void adjacency_list(unordered_map<int, set<int> > &adjacency, vector<pair<int, int> > edges){
    for(int i = 0; i<edges.size(); i++){

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
    adjacency_list(adjacency, edges);
    print(adjacency);
}