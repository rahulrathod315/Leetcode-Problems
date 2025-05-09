# 103. Binary Tree Zigzag Level Order Traversal

This folder contains the solution to the Leetcode problem **103. Binary Tree Zigzag Level Order Traversal** implemented in C++.

## Problem Description

Given the `root` of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

### Example 1

```
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
```

### Example 2

```
Input: root = [1]
Output: [[1]]
```

### Example 3

```
Input: root = []
Output: []
```

### Constraints

- The number of nodes in the tree is in the range `[0, 2000]`.
- `-100 <= Node.val <= 100`

---

## Basic Concepts

### 1. Binary Tree

A binary tree is a hierarchical data structure in which each node has at most two children, referred to as the left child and the right child.

### 2. Level Order Traversal

Level order traversal visits nodes level by level from top to bottom, typically using a queue (BFS).

### 3. Zigzag Traversal

Zigzag traversal alternates the direction of traversal at each level: left-to-right for one level, then right-to-left for the next, and so on.

---

## Approach 1: BFS with Direction Toggle

This approach uses a queue for level order traversal and a boolean flag to alternate the direction at each level.

### Implementation

```cpp
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        if(!root)   // If root is NULL then return empty vector
            return vector<vector<int>>();

        queue<TreeNode*> q; // Queue for BFS
        bool left_to_right = true; // Direction flag

        q.push(root);
        vector<vector<int> > v;

        while(q.size())
        {
            int total_nodes_in_level = q.size();
            vector<int> temp;

            while(total_nodes_in_level--)
            {
                TreeNode *current_node = q.front();
                q.pop();

                temp.push_back(current_node->val); // Add current node's value
                if(current_node->left)
                    q.push(current_node->left);    // Enqueue left child
                if(current_node->right)
                    q.push(current_node->right);   // Enqueue right child
            }

            if(!left_to_right)
                reverse(temp.begin(), temp.end()); // Reverse for right-to-left
            v.push_back(temp);
            temp.clear();
            left_to_right = !left_to_right; // Toggle direction
        }
        return v;
    }
};
```

### Example Walkthrough

#### Input: `root = [3,9,20,null,null,15,7]`

- Level 1: [3] (left-to-right)
- Level 2: [9, 20] (right-to-left → [20, 9])
- Level 3: [15, 7] (left-to-right)

Output: `[[3], [20, 9], [15, 7]]`

### Complexity Analysis

- **Time Complexity:** `O(n)` (each node is visited once)
- **Space Complexity:** `O(n)` (queue and result storage)

---

## Approach 2: Optimized Double-Ended Queue (Deque) for Zigzag Traversal

This approach uses a deque to efficiently insert node values at either end, avoiding the need to reverse vectors.

### Implementation

```cpp
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);
        bool left_to_right = true;

        while (!q.empty()) {
            int size = q.size();
            deque<int> level; // Use deque for efficient front/back insertion

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();

                if (left_to_right)
                    level.push_back(node->val); // Insert at end
                else
                    level.push_front(node->val); // Insert at front

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            result.push_back(vector<int>(level.begin(), level.end()));
            left_to_right = !left_to_right; // Toggle direction
        }
        return result;
    }
};
```

### Example Walkthrough

#### Input: `root = [3,9,20,null,null,15,7]`

- Level 1: [3] (left-to-right)
- Level 2: [20, 9] (right-to-left, inserted at front)
- Level 3: [15, 7] (left-to-right)

Output: `[[3], [20, 9], [15, 7]]`

### Complexity Analysis

- **Time Complexity:** `O(n)` (each node is visited once)
- **Space Complexity:** `O(n)` (queue and result storage, plus deque per level)

---

## Applications

1. **Tree Visualization**: Zigzag traversal is useful for visually representing hierarchical data in a more readable format.
2. **Interview Problems**: Demonstrates understanding of BFS and data structure manipulation.
3. **Algorithm Design**: Useful in scenarios where alternate level processing is required.

---

## References

- [Leetcode Problem 103](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)
