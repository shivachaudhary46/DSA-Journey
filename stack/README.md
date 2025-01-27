stack data structure

stack is linear data structure which follows LIFO (last in first out) principle. It implies that the element inserted at first will be removed at first.

it behaves like stack of plates, think of this way the last plate added to stack is removed at first 

![alt text](stack.webp)

types of stack 
1. fixed size stack\
static stack is also known as fixed size stack. As, name suggest it is implemented statically means it cannot grow or shrink at run time. if stack is full and more elements are pushed into stack then it is overflowed. if stack is empty and pop function carry out then stack is overflowed 

1. dynamic size stack\
dynamic size stack is implemented dynamically. As, name suggest it can grow or shrink at runtime. it is implemented using pointer and stores address at heap memory which is pointed by pointer.

basic operations in stack 
- push()
- pop()
- isEmpty()
- isFull()
- size()

Push Operation on Stack\
Algorithm for Push Operation:
- Before pushing the element to the stack, we check if the stack is full .
- If the stack is full (top == size-1) , then Stack Overflows and we cannot insert the element to the stack.
- Otherwise, we increment the value of top by 1 (top = top + 1) and the new value is inserted at top position .
- The elements can be pushed into the stack till we reach the maxsize of the stack.

Pop Operation on Stack\
Algorithm for Pop Operation
- Before removing elements in stack, we check whether the stack is empty ot not 
- If the stack is empty (top == -1), then stack underflows and we cannot remove elements from stack
- If not, decrement the value of top by -1 (top = top -1 )
- The elements can be popped into the stack till we reach the (top    == -1)

Top or Peek Operation on Stack\
Algorithm for Top Operation:
-Before returning the top element from the stack, we check if the stack is empty.
-If the stack is empty (top == -1), we simply print “Stack is empty”.
Otherwise, we return the element stored at index = top .

isEmpty Operation in Stack Data Structure\
Algorithm for isEmpty Operation:
-Check for the value of top in stack.
-If (top == -1), then the stack is empty so return true .
-Otherwise, the stack is not empty so return false .

isFull Operation in Stack Data Structure\
Algorithm for isFull Operation:

Check for the value of top in stack.
If (top == capacity-1), then the stack is full so return true.
Otherwise, the stack is not full so return false.