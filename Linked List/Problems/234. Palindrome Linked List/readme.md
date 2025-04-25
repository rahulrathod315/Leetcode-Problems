# 234. Palindrome Linked List

This folder contains the solution to the Leetcode problem **234. Palindrome Linked List** implemented in C++.

---

## Problem Description

Given the `head` of a singly linked list, return `true` if it is a palindrome or `false` otherwise.

### Example 1

```
Input: head = [1,2,2,1]
Output: true
```

### Example 2

```
Input: head = [1,2]
Output: false
```

### Constraints

- The number of nodes in the list is in the range `[1, 10^5]`.
- `0 <= Node.val <= 9`

---

## Basic Concept

A linked list is a palindrome if the sequence of its values reads the same forward and backward. To solve this problem, we need to check if the linked list satisfies this property.

Key concepts:
1. **Reversing a Linked List**:
   - Reversing the second half of the list is a common technique to compare the two halves.

2. **Two-Pointer Technique**:
   - Using slow and fast pointers helps find the middle of the linked list efficiently.

3. **Recursive and Iterative Approaches**:
   - Recursive solutions use the call stack to traverse the list, while iterative solutions use explicit data structures like stacks or queues.

4. **Space Optimization**:
   - The most optimized approach avoids using extra space by modifying the linked list temporarily.

---

## Approaches

### Approach 1: Reverse the List and Compare

#### Explanation

1. **Reverse the List**:
   - Reverse the linked list to create a copy of the original list in reverse order.

2. **Compare Values**:
   - Compare the values of the original list and the reversed list node by node.

3. **Palindrome Check**:
   - If all values match, the list is a palindrome.

#### Implementation

```cpp
class Solution {
public:
    // Helper function to reverse a linked list
    ListNode* reverse_list(ListNode* head)
    {
        if(!head || !head->next) // Base case: empty list or single node
            return head;
        
        ListNode* last_node = reverse_list(head->next); // Recursively reverse the rest of the list
        head->next->next = head; // Reverse the current node
        head->next = NULL; // Set the next pointer of the current node to NULL

        return last_node; // Return the new head of the reversed list
    }

    bool isPalindrome(ListNode* head) 
    {
        if(!head || !head->next) // Base case: empty list or single node is always a palindrome
            return true;

        stack<int> s; // Stack to store the values of the original list
        ListNode* temp = head;
        string s1 = "", s2 = "";

        // Traverse the list and store values in a string
        while(temp)
        {
            s1 += (char)(temp->val);
            temp = temp->next;
        }

        // Reverse the list
        temp = reverse_list(head);

        // Traverse the reversed list and store values in another string
        while(temp)
        {
            s2 += (char)(temp->val);
            temp = temp->next;
        }

        // Compare the two strings
        return s1 == s2;
    }
};
```

#### Example Walkthrough

**Input**: `head = [1,2,2,1]`

1. Reverse the list:
   - Original: `1 -> 2 -> 2 -> 1`
   - Reversed: `1 -> 2 -> 2 -> 1`

2. Compare the original and reversed lists:
   - `1 == 1`, `2 == 2`, `2 == 2`, `1 == 1`.

3. Output: `true`.

#### Complexity Analysis

1. **Time Complexity**: `O(n)`
   - Reversing the list and comparing the two lists both take linear time.

2. **Space Complexity**: `O(n)`
   - The recursion stack for reversing the list requires linear space.

---

### Approach 2: Convert to String and Check Palindrome

#### Explanation

1. **Convert to String**:
   - Traverse the linked list and store its values in a string.

2. **Check Palindrome**:
   - Use two pointers to check if the string is a palindrome.

#### Implementation

```cpp
class Solution {
public:
    // Helper function to check if a string is a palindrome
    bool check_palindrom(string s)
    {
        int i = 0;
        int j = s.length() - 1;
        
        while(i < j) // Compare characters from both ends
        {
            if(s[i] != s[j]) // If characters don't match, return false
                return false;
            i++;
            j--;
        }
        return true; // If all characters match, return true
    }

    bool isPalindrome(ListNode* head) 
    {
        string s = ""; // String to store the values of the linked list
        
        while(head) // Traverse the linked list
        {
            s += to_string(head->val); // Append each value to the string
            head = head->next;
        }
        
        return check_palindrom(s); // Check if the string is a palindrome
    }
};
```

#### Example Walkthrough

**Input**: `head = [1,2,2,1]`

1. Convert to string: `s = "1221"`.
2. Check palindrome:
   - Compare `s[0]` and `s[3]`: `1 == 1`.
   - Compare `s[1]` and `s[2]`: `2 == 2`.

3. Output: `true`.

#### Complexity Analysis

1. **Time Complexity**: `O(n)`
   - Traversing the list and checking the string both take linear time.

2. **Space Complexity**: `O(n)`
   - The string requires linear space.

---

### Approach 3: Recursive Check with Queue

#### Explanation

1. **Recursive Traversal**:
   - Use recursion to traverse the list and store values in a queue.

2. **Compare Values**:
   - Compare the front of the queue with the current node during the recursive backtracking.

#### Implementation

```cpp
class Solution {
public:
    // Helper function to recursively check if the list is a palindrome
    bool check(ListNode *head, queue<int> &q)
    {
        if(!head) // Base case: empty list
            return true;
        
        q.push(head->val); // Push the current node's value into the queue
        bool result = check(head->next, q); // Recursively check the rest of the list
        
        result = (q.front() == head->val) && result; // Compare the front of the queue with the current node
        q.pop(); // Remove the front of the queue
        return result;
    }

    bool isPalindrome(ListNode* head) 
    {
        if(!head) // Base case: empty list is always a palindrome
            return true;
        
        queue<int> q; // Queue to store the values of the list
        return check(head, q); // Recursively check if the list is a palindrome
    }
};
```

#### Example Walkthrough

**Input**: `head = [1,2,2,1]`

1. Traverse the list and store values in a queue: `q = [1,2,2,1]`.
2. Compare values during backtracking:
   - Compare `q.front() = 1` with `head->val = 1`.
   - Compare `q.front() = 2` with `head->val = 2`.

3. Output: `true`.

#### Complexity Analysis

1. **Time Complexity**: `O(n)`
   - Traversing the list and comparing values both take linear time.

2. **Space Complexity**: `O(n)`
   - The queue requires linear space.

---

### Approach 4: Optimized Two-Pointer Technique

#### Explanation

1. **Find the Middle**:
   - Use slow and fast pointers to find the middle of the list.

2. **Reverse the Second Half**:
   - Reverse the second half of the list.

3. **Compare Halves**:
   - Compare the first half with the reversed second half.

4. **Restore the List**:
   - Reverse the second half again to restore the original list.

#### Implementation

```cpp
class Solution {
public:
    bool isPalindrome(ListNode* head) 
    {
        if(!head || !head->next) // Base case: empty list or single node is always a palindrome
            return true;

        // Step 1: Find the middle of the list
        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half of the list
        ListNode *prev = NULL, *curr = slow->next;
        while(curr)
        {
            ListNode *next_temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_temp;
        }

        // Step 3: Compare the two halves
        ListNode *first_half = head, *second_half = prev;
        while(second_half)
        {
            if(first_half->val != second_half->val)
                return false;
            first_half = first_half->next;
            second_half = second_half->next;
        }

        // Step 4: Restore the second half of the list (optional)
        curr = prev;
        prev = NULL;
        while(curr)
        {
            ListNode *next_temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_temp;
        }

        return true;
    }
};
```

#### Example Walkthrough

**Input**: `head = [1,2,2,1]`

1. Find the middle: `slow = 2`, `fast = 1`.
2. Reverse the second half: `1 -> 2`.
3. Compare halves:
   - `1 == 1`, `2 == 2`.

4. Output: `true`.

#### Complexity Analysis

1. **Time Complexity**: `O(n)`
   - Finding the middle, reversing the list, and comparing halves all take linear time.

2. **Space Complexity**: `O(1)`
   - The solution uses constant extra space.

---

## Applications

1. **Data Validation**:
   - Palindrome checks are used in data validation and error detection.

2. **Linked List Manipulation**:
   - Demonstrates techniques for reversing and traversing linked lists.

3. **Algorithm Design**:
   - Combines multiple techniques like two-pointer and recursion for efficient solutions.

---

## References

- [Leetcode Problem 234](https://leetcode.com/problems/palindrome-linked-list/)
