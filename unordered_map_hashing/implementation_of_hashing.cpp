#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
    
    //creation of the unordered map
    unordered_map<string, int> m;

    //insertion
    //1
    pair<string, int> p = make_pair("my", 10);
    m.insert(p);

    //2 
    pair<string, int> p2("name", 12);
    m.insert(p2);

    //3 
    m["shiva"] = 45;

    m["shiva"] = 60;

    //search 
    cout<<m["shiva"]<<endl;
    cout<<m["chaudhary"]<<endl; //unknown key will initate value with 0

    cout<<m.at("name")<<endl;  //can access with this

    //size 
    cout<<"size of the unordered map "<<m.size()<<endl;

    //to check presence
    cout << "to check if key is present "<<m.count("shiva")<<endl;

    //erase
    m.erase("name");

    cout<<"size of the unordered map "<<m.size()<<endl;

    for(auto i: m){
        cout<<"first : "<<i.first<<" | second : "<<i.second<<endl;
    }

    cout<<endl;

    unordered_map<string, int> :: iterator it = m.begin();

    while(it != m.end()){
        cout<<"first : "<<it->first<<" | second : "<<it->second<<endl;
        it++;
    }

    cout<<endl;
}
