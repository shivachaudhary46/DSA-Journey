#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
class graph{

    public:
    unordered_map<int, list<int> > adj;

    void addEdge(int u, int v, bool direction){

        //direction = 0 -> undirected graph 
        //direction = 1 -> directed graaph 

        adj[u].push_back(v);

        if(direction != true){
            adj[v].push_back(u);
        }
    }

    void printAdj(){
        for(auto i: adj){
            cout<<i.first<<"-> ";
            for(auto j: i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};
int main(){
    graph g;
    g.addEdge(3, 4, 0);
    g.addEdge(3, 7, 0);
    g.addEdge(7, 1, 0);
    g.addEdge(1, 5, 0);
    g.addEdge(4, 5, 0);
    g.addEdge(4, 1, 0);
    g.addEdge(3, 1, 0);

    g.printAdj();
}