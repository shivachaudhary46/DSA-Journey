#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 

int precedence(char s) {
    if (s == '^') {
        return 3; // Highest precedence
    } else if (s == '*' || s == '/') {
        return 2;
    } else if (s == '+' || s == '-') {
        return 1;
    } else {
        return -1; // For operands or non-operators
    }
}

void reverse(char *s, int len){
    for(int i=0; i<len/2; i++){
        char temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
}

void infixToPrefix(char* s) {
    int len = strlen(s);
    char str[len + 1]; // Output (prefix expression)
    int j = 0; // Index for str
    char stack[len]; // Stack for operators
    int top = -1; // Stack pointer
    
    //step 1: reverse the input expression 
    reverse(s, len);

    for (int i = 0; i < len ; i++) {
        char c = s[i];

        // Step 2: If the char is an operand, add it to the result string
        //from right side to left side 
        if (isalnum(c)) {
            str[j++] = c;
        }
        // Step 3: If '(', push it onto the stack
        else if (c == ')') {
            stack[++top] = c;
        }
        // Step 4: If ')', pop from the stack until '(' is found
        else if (c == '(') {
            while (top != -1 && stack[top] != ')') {
                str[j++] = stack[top--];
            }
            top--; // Pop the '(' last bracket from the stack
        }
        // Step 5: If an operator, pop operators with higher precedence 
        else {
            while (top != -1 && precedence(c) < precedence(stack[top])) {
                str[j++] = stack[top--];
            }
            stack[++top] = c; //push current operator
        }
    }
    // Step 6: Pop any remaining operators from the stack
    while (top != -1) {
        str[j++] = stack[top--];
    }

    //last element in stack is null 
    str[j] = '\0';

     //step 7: reverse string 
    reverse(str, j);

    // Print the resulting postfix expression
    printf("Prefix expression: %s\n", str);
}

int main() {
    char str[] = "a+b*(c^d-e)^(f+g*h)-i";
    int n = strlen(str);

    printf("Infix expression: %s\n", str);
    infixToPrefix(str);
    return 0;
}
