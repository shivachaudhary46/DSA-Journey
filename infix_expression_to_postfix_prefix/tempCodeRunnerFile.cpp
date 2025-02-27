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
    stack<int> s;

    for(int i=0; i<len; i++){
        char ch = arr[i];

        if(isalnum(ch)){
            ans.push_back(ch);
        }
        else if(ch == '('){
            s.push(ch);
        }
        else if(ch == ')' && !s.empty()){
            
            while(s.top() != '('){
                ans.push_back(s.top());
                s.pop();
            }