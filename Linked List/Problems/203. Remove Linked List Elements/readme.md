# 203. Remove Linked List Elements

This folder contains the solution to the Leetcode problem **203. Remove Linked List Elements** implemented in C++.

## Problem Description

Given the `head` of a linked list and an integer `val`, remove all the nodes of the linked list that have `Node.val == val`, and return the new head.

---

### Example 1

```
Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]
```

### Example 2

```
Input: head = [], val = 1
Output: []
```

### Example 3

```
Input: head = [7,7,7,7], val = 7
Output: []
```

---

### Constraints

- The number of nodes in the list is in the range `[0, 10^4]`.
- `1 <= Node.val <= 50`
- `0 <= val <= 50`

---

## Basic Concept

The problem involves removing nodes from a linked list that have a specific value. This is a common operation in linked list manipulation.

Key concepts:
1. **Linked List Structure**:
   - A linked list is a linear data structure where each node contains a value and a pointer to the next node.

2. **Node Removal**:
   - To remove a node, the `next` pointer of the previous node is updated to skip the node being removed.

3. **Edge Cases**:
   - Special care is needed for edge cases, such as when the head node needs to be removed or when the list is empty.

4. **Dummy Node**:
   - Using a dummy node simplifies the implementation by handling edge cases uniformly.

---

## Approach 1: Recursive Solution

### Explanation

The recursive approach processes the linked list node by node. For each node:
1. If the node's value equals `val`, skip the node by returning the result of the recursive call on the next node.
2. Otherwise, recursively process the next node and update the `next` pointer of the current node.

---

### Implementation

```cpp
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        if(!head) // Base case: if the list is empty, return NULL
            return NULL;

        if(head->val == val) // If the current node's value equals val, skip it
            return removeElements(head->next, val);
        
        head->next = removeElements(head->next, val); // Recursively process the next node
        return head; // Return the current node
    }
};
```

---

### Example Walkthrough

#### Input: `head = [1,2,6,3,4,5,6]`, `val = 6`

1. Start at the head node (`1`).
2. Node `1` does not equal `6`, so recursively process the next node.
3. Node `2` does not equal `6`, so recursively process the next node.
4. Node `6` equals `6`, so skip it and recursively process the next node.
5. Continue this process until all nodes are processed.
6. Final result: `[1,2,3,4,5]`.

---

### Complexity Analysis

1. **Time Complexity**: `O(n)`
   - Each node is visited exactly once, where `n` is the number of nodes in the linked list.

2. **Space Complexity**: `O(n)`
   - The recursion stack requires space proportional to the number of nodes in the linked list.

---

## Approach 2: Iterative Solution (Optimized)

### Explanation

The iterative approach avoids recursion and processes the linked list using a loop. The steps are:
1. Use a dummy node to handle edge cases where the head node needs to be removed.
2. Traverse the linked list using a pointer (`current`).
3. If the next node's value equals `val`, skip the node by updating the `next` pointer of the current node.
4. Otherwise, move the pointer to the next node.

---

### Implementation

```cpp
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        ListNode* dummy = new ListNode(-1); // Create a dummy node
        dummy->next = head; // Point the dummy node to the head of the list
        ListNode* current = dummy; // Initialize a pointer to traverse the list

        while(current->next) // Traverse the list
        {
            if(current->next->val == val) // If the next node's value equals val
            {
                current->next = current->next->next; // Skip the node
            }
            else
            {
                current = current->next; // Move to the next node
            }
        }

        return dummy->next; // Return the new head of the list
    }
};
```

---

### Example Walkthrough

#### Input: `head = [1,2,6,3,4,5,6]`, `val = 6`

1. Create a dummy node pointing to the head: `dummy -> [1,2,6,3,4,5,6]`.
2. Start at the dummy node.
3. Check the next node (`1`):
   - `1 != 6`, move to the next node.
4. Check the next node (`2`):
   - `2 != 6`, move to the next node.
5. Check the next node (`6`):
   - `6 == 6`, skip the node by updating the `next` pointer.
6. Continue this process until all nodes are processed.
7. Final result: `[1,2,3,4,5]`.

---

### Complexity Analysis

1. **Time Complexity**: `O(n)`
   - Each node is visited exactly once, where `n` is the number of nodes in the linked list.

2. **Space Complexity**: `O(1)`
   - The solution uses a constant amount of extra space.

---

## Applications

1. **Data Cleaning**:
   - Removing specific elements from a linked list is a common operation in data cleaning and preprocessing.

2. **Linked List Manipulation**:
   - Demonstrates techniques for modifying linked lists, such as skipping nodes and handling edge cases.

3. **Memory Management**:
   - Efficiently removing nodes without creating unnecessary copies of the list.

---

## References

- [Leetcode Problem 203](https://leetcode.com/problems/remove-linked-list-elements/)
