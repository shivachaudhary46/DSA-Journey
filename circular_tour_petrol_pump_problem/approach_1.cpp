#include<iostream>
#include<vector>
using namespace std;

int startStation(vector<int> &gas, vector<int> &cost) {
        // Your code here
        int deficit = 0;
        int balance = 0;
        int start = 0;

        for(int i=0; i<gas.size(); i++){
            balance += gas[i] - cost[i];
            if(balance < 0){
                deficit += balance;
                start = start + 1;
                balance = 0;
            }

        }
        if(balance + deficit >= 0){
                return start;
        }else{
                return -1;
        }
    }
int main(){
    vector<int>gas(5);
    vector<int>distance(5);

    gas.push_back(1);
    gas.push_back(2);
    gas.push_back(3);
    gas.push_back(4);
    gas.push_back(5);

    distance.push_back(3);
    distance.push_back(4);
    distance.push_back(5);
    distance.push_back(1);
    distance.push_back(2);

    cout<<startStation(gas, distance)<<endl;
}