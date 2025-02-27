#include<iostream>
#include<stack>
#include<cctype>  // for isalnum function
using namespace std;

int precedence(char ch) {
    if(ch == '^') {
        return 3;
    } else if(ch == '/' || ch == '*') {
        return 2;
    } else if(ch == '-' || ch == '+') {
        return 1;
    } else {
        return -1; // for other characters
    }
}

void reverse(string &str) {
    int s = 0;
    int e = str.size() - 1;
    while(s < e) {
        swap(str[s], str[e]);
        s++;
        e--;
    }
}

string infixToPrefix(string arr) {
    int len = arr.size();
    string ans = "";
    stack<char> s;

    reverse(arr);  // Reverse the infix expression first

    for(int i = 0; i < len; i++) {
        char ch = arr[i];

        // If the character is an operand (alphanumeric), add it to the result
        if(isalnum(ch)) {
            ans.push_back(ch);
        } else if(ch == ')') {
            s.push(ch);  // Push ')' to the stack
        } else if(ch == '(') {
            // Pop and add all operators from the stack to result until ')' is encountered
            while(s.top() != ')' && !s.empty()) {
                char val = s.top();
                s.pop();
                ans.push_back(val);
            }
            s.pop();  // Pop the '(' from the stack
        } else {
            // Operator encountered, pop higher precedence operators and add to result
            while(!s.empty() && precedence(ch) < precedence(s.top())) {
                char val = s.top();
                s.pop();
                ans.push_back(val);
            }
            s.push(ch);  // Push the current operator to the stack
        }
    }

    // Pop any remaining operators from the stack and add to result
    while(!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }

    reverse(ans);  // Reverse the result to get the correct prefix expression
    return ans;
}

int main() {
    string arr = "A*B-(C+D*(E-F))";
    string ans = infixToPrefix(arr);
    
    cout << "Prefix Expression: ";
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
