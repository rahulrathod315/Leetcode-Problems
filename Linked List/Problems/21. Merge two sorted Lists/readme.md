# 21. Merge Two Sorted Lists

This folder contains the solution to the Leetcode problem **21. Merge Two Sorted Lists** implemented in C++.

## Problem Description

You are given the heads of two sorted linked lists `list1` and `list2`. Merge the two lists into one sorted linked list and return the head of the merged list.

The merged list should be made by splicing together the nodes of the first two lists.

### Example 1

```
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
```

### Example 2

```
Input: list1 = [], list2 = []
Output: []
```

### Example 3

```
Input: list1 = [], list2 = [0]
Output: [0]
```

### Constraints

- The number of nodes in both lists is in the range `[0, 50]`.
- `-100 <= Node.val <= 100`
- Both `list1` and `list2` are sorted in **non-decreasing order**.

---

## Approach

The problem can be solved using two approaches: **recursion** and **iteration**.

### Recursive Approach

The recursive approach compares the values of the current nodes of the two lists and recursively merges the remaining nodes.

#### Implementation

```cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        if(!list1) // Base case: if list1 is empty, return list2
            return list2;
        
        if(!list2) // Base case: if list2 is empty, return list1
            return list1;

        if(list1->val < list2->val) // Compare the values of the current nodes
        {
            list1->next = mergeTwoLists(list1->next, list2); // Recursively merge the rest
            return list1;
        }
        else
        {
            list2->next = mergeTwoLists(list1, list2->next); // Recursively merge the rest
            return list2;
        }
    }
};
```

---

### Iterative Approach

The iterative approach uses a loop to merge the two lists node by node.

#### Implementation

```cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        if(!list1) // If list1 is empty, return list2
            return list2;
        
        if(!list2) // If list2 is empty, return list1
            return list1;

        ListNode *result = nullptr; // Pointer to track the current node in the merged list
        ListNode *head = nullptr;   // Pointer to store the head of the merged list

        while(list1 && list2) // Loop until one of the lists is exhausted
        {
            if(list1->val < list2->val) // If list1's value is smaller
            {
                if(!result) // If this is the first node in the merged list
                {
                    result = list1; // Initialize result with list1
                    head = result;  // Set head to the first node
                } 
                else
                    result->next = list1; // Append list1's node to the merged list
                
                result = list1; // Move result to the next node
                list1 = list1->next; // Move list1 to the next node
            }
            else // If list2's value is smaller or equal
            {
                if(!result) // If this is the first node in the merged list
                {
                    result = list2; // Initialize result with list2
                    head = result;  // Set head to the first node
                }
                else
                    result->next = list2; // Append list2's node to the merged list

                result = list2; // Move result to the next node
                list2 = list2->next; // Move list2 to the next node
            }
        }

        if(list1) // If list1 still has nodes left, append them
            result->next = list1;
        
        if(list2) // If list2 still has nodes left, append them
            result->next = list2;

        return head; // Return the head of the merged list
    }
};
```

---

## Complexity Analysis

### Recursive Approach

1. **Time Complexity**: `O(n + m)`
   - `n` is the number of nodes in `list1`, and `m` is the number of nodes in `list2`.
   - Each node is visited exactly once.

2. **Space Complexity**: `O(n + m)`
   - The recursion stack requires space proportional to the total number of nodes in both lists.

### Iterative Approach

1. **Time Complexity**: `O(n + m)`
   - Each node is visited exactly once.

2. **Space Complexity**: `O(1)`
   - The iterative approach uses constant extra space.

---

## Example Walkthrough

### Input: `list1 = [1,2,4]`, `list2 = [1,3,4]`

#### Recursive Approach

1. Compare `list1->val = 1` and `list2->val = 1`.
   - Both are equal, so choose `list1` and recursively merge `list1->next` and `list2`.
2. Compare `list1->val = 2` and `list2->val = 1`.
   - `list2->val` is smaller, so choose `list2` and recursively merge `list1` and `list2->next`.
3. Continue this process until all nodes are merged.

Output: `[1,1,2,3,4,4]`.

#### Iterative Approach

1. Initialize `result` and `head` as `nullptr`.
2. Compare `list1->val = 1` and `list2->val = 1`.
   - Append `list1` to the merged list and move `list1` forward.
3. Compare `list1->val = 2` and `list2->val = 1`.
   - Append `list2` to the merged list and move `list2` forward.
4. Continue this process until all nodes are merged.

Output: `[1,1,2,3,4,4]`.

---

## Applications

1. **Merge Sort**:
   - Merging two sorted lists is a key step in the **Merge Sort** algorithm, which is widely used in sorting large datasets.

2. **Data Integration**:
   - In applications where data is stored in sorted linked lists (e.g., database systems), merging sorted lists is a common operation.

3. **Streaming Data**:
   - When processing real-time data streams that are sorted, merging sorted lists can help combine multiple streams into a single sorted stream.

4. **File Merging**:
   - In external sorting (used for large files that cannot fit into memory), merging sorted chunks of data is a critical operation.

5. **Version Control Systems**:
   - Merging sorted lists is conceptually similar to merging changes in version control systems like Git, where changes are applied in a sorted order.

---

## References

- [Leetcode Problem 21](https://leetcode.com/problems/merge-two-sorted-lists/)
