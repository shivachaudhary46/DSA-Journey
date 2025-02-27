#include<iostream>
using namespace std;
//check precedence 
int precedence(char ch){
    if(ch == '^'){
        return 3;
    }else if(ch == '*' || ch == '/'){
        return 2;
    }else if(ch == '-' || ch == '+'){
        return 1;
    }else{
        return -1;
    }
}
string infixToPostfix(string arr){
    string ans = "";
    int len = arr.size();
    stack<char> s;

    for(int i=0; i<len; i++){
        char ch = arr[i];

        if(isalnum(ch)){
            ans.push_back(ch);
        }
        else if(ch == '('){
            s.push(ch);
        }
        else if(ch == ')' && !s.empty()){
            
            while(s.top() != '(' && !s.empty()){
                char val = s.top();
                s.pop();
                ans.push_back(val);
            }
            s.pop();
        }
        else{
            while(!s.empty() && precedence(ch) <= precedence(s.top())){
                char val = s.top();
                s.pop();
                ans.push_back(val);
            }
            s.push(ch);
        }
    }
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }

    return ans; 
}
int main(){
    string ans = "A*B-(C+D*(E-F))";
    string res = infixToPostfix(ans);

    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
}