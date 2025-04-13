# 94. Binary Tree Inorder Traversal

This folder contains the solution to the Leetcode problem **94. Binary Tree Inorder Traversal** implemented in C++.

## Problem Description

Given the `root` of a binary tree, return the **inorder traversal** of its nodes' values.

### Example 1

```
Input: root = [1,null,2,3]
Output: [1,3,2]
```

### Example 2

```
Input: root = []
Output: []
```

### Example 3

```
Input: root = [1]
Output: [1]
```

### Constraints

- The number of nodes in the tree is in the range `[0, 100]`.
- `-100 <= Node.val <= 100`

---

## Approach 1: Recursive Inorder Traversal

### Explanation

In an **inorder traversal**, the nodes are visited in the following order:
1. Traverse the left subtree.
2. Visit the root node.
3. Traverse the right subtree.

This approach uses recursion to traverse the tree in the above order.

---

### Implementation

```cpp
class Solution {
public:
    // Helper function to perform recursive inorder traversal
    void inorder(TreeNode *root, vector<int> &v)
    {
        if(!root) // Base case: if the node is null, return
            return;
        
        // Traverse the left subtree
        inorder(root->left, v);
        
        // Visit the root node
        v.push_back(root->val);
        
        // Traverse the right subtree
        inorder(root->right, v);
    }

    // Main function to return the inorder traversal
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> result; // Vector to store the result
        inorder(root, result); // Perform recursive traversal
        return result; // Return the result
    }
};
```

---

### Example Walkthrough

#### Input: `root = [1,null,2,3]`

1. Start at the root node (`1`).
2. Traverse the left subtree of `1` (null).
3. Visit the root node (`1`) → Add `1` to the result.
4. Traverse the right subtree of `1`:
   - Visit the root node (`2`).
   - Traverse the left subtree of `2`:
     - Visit the root node (`3`) → Add `3` to the result.
   - Add `2` to the result.
5. Final result: `[1,3,2]`.

---

### Complexity Analysis

1. **Time Complexity**: `O(n)`
   - Each node is visited exactly once, where `n` is the number of nodes in the tree.

2. **Space Complexity**: `O(h)`
   - The recursion stack requires space proportional to the height of the tree, where `h` is the height of the tree.

---

## Approach 2: Iterative Inorder Traversal

### Explanation

The iterative approach uses a stack to simulate the recursive behavior of inorder traversal. The steps are as follows:
1. Use a stack to keep track of nodes.
2. Push all the left nodes onto the stack until a null node is reached.
3. Pop a node from the stack, visit it, and move to its right subtree.
4. Repeat until the stack is empty and all nodes are visited.

---

### Implementation

```cpp
class Solution {
public:
    // Main function to return the inorder traversal
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> result; // Vector to store the result
        stack<TreeNode*> s; // Stack to keep track of nodes
        TreeNode* current = root; // Pointer to the current node

        while(current || !s.empty())
        {
            // Push all left nodes onto the stack
            while(current)
            {
                s.push(current);
                current = current->left;
            }

            // Pop a node from the stack
            current = s.top();
            s.pop();

            // Visit the node
            result.push_back(current->val);

            // Move to the right subtree
            current = current->right;
        }

        return result; // Return the result
    }
};
```

---

### Example Walkthrough

#### Input: `root = [1,null,2,3]`

1. Initialize `stack = []`, `result = []`, `current = root (1)`.
2. Push `1` onto the stack → `stack = [1]`, `current = null`.
3. Pop `1` from the stack → `stack = []`, `result = [1]`, `current = 2`.
4. Push `2` onto the stack → `stack = [2]`, `current = 3`.
5. Push `3` onto the stack → `stack = [2,3]`, `current = null`.
6. Pop `3` from the stack → `stack = [2]`, `result = [1,3]`, `current = null`.
7. Pop `2` from the stack → `stack = []`, `result = [1,3,2]`, `current = null`.
8. Final result: `[1,3,2]`.

---

### Complexity Analysis

1. **Time Complexity**: `O(n)`
   - Each node is visited exactly once, where `n` is the number of nodes in the tree.

2. **Space Complexity**: `O(h)`
   - The stack requires space proportional to the height of the tree, where `h` is the height of the tree.

---

## Applications

1. **Tree Traversal**:
   - Inorder traversal is commonly used to retrieve the elements of a binary search tree (BST) in sorted order.

2. **Expression Trees**:
   - Inorder traversal is used to evaluate or print infix expressions in expression trees.

3. **Algorithm Design**:
   - Understanding tree traversal techniques is fundamental for solving many tree-related problems.

---

## References

- [Leetcode Problem 94](https://leetcode.com/problems/binary-tree-inorder-traversal/)
