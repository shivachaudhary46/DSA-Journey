# Reverse a Queue

Given a queue `q` containing integer elements, your task is to reverse the queue.

### Problem Description

You are given a queue with integer elements. The task is to reverse the order of the elements in the queue.

### Example 1

**Input:**

q[] = [4, 3, 1, 10, 2, 6]

makefile
Copy

**Output:**

[6, 2, 10, 1, 3, 4]

**Explanation:**

After reversing the given elements of the queue, the resultant queue will be:

[6, 2, 10, 1, 3, 4]


### Approach

1. Use a stack or recursion to reverse the queue elements.
2. The stack can help store elements temporarily while popping and pushing them back to achieve the reversed order.
3. If recursion is used, keep dequeueing elements, reverse the rest of the queue, and then enqueue the element backwards

### expected time complexity is O(n) because O(n)+O(n) = 2O(n) =  O(n).
space complexity:  O(n)
