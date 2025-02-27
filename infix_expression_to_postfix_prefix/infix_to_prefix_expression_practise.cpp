#include<iostream>
using namespace std;
int precedence(char ch){
    if(ch == '^'){
        return 3;
    }else if(ch == '/' || ch == '*'){
        return 2;
    }else if(ch == '-' || ch == '+'){
        return 1;
    }else{
        return -1;
    }
}
void reverse(string &str){
    int s = 0; 
    int e = str.size()-1;

    while(s<e){
        swap(str[s], str[e]);
        s++;
        e--;
    }
}
string infixToPrefix(string arr){

    int len = arr.size();
    string ans = "";
    stack<char> s;


    for(int i=0; i<len; i++){
        char ch = arr[i];

        if(isalnum(ch)){
            ans.push_back(ch);
        }else if(ch == ')'){
            s.push(ch);
        }else if(ch == '('){

            while(s.top() != ')' && !s.empty()){
                char val = s.top();
                s.pop();
                ans.push_back(val);
            }
            s.pop();
        }else{

            while(!s.empty() && precedence(ch) < precedence(s.top())){
                char val = s.top();
                s.pop();
                ans.push_back(val);
            }
            s.push(ch);
        }

        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
    }

    reverse(ans);
    return ans;
}
int main(){
    string arr = "A*B-(C+D*(E-F))";
    reverse(arr);
    string ans = infixToPrefix(arr);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}