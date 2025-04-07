# 110. Balanced Binary Tree

This folder contains the solution to the Leetcode problem **110. Balanced Binary Tree** implemented in C++.

## Problem Description

Given a binary tree, determine if it is **height-balanced**.

A binary tree is height-balanced if:
- The left and right subtrees of every node differ in height by no more than `1`.

### Example 1

```
Input: root = [3,9,20,null,null,15,7]
Output: true
Explanation: The tree is balanced because:
    - The left subtree has height 1 (node 9).
    - The right subtree has height 2 (nodes 20 -> 15, 20 -> 7).
    - The difference in height is 1, which satisfies the condition.
```

### Example 2

```
Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Explanation: The tree is not balanced because:
    - The left subtree has height 3 (nodes 1 -> 2 -> 3 -> 4).
    - The right subtree has height 1 (node 2).
    - The difference in height is 2, which violates the condition.
```

### Example 3

```
Input: root = []
Output: true
Explanation: An empty tree is balanced by definition.
```

### Constraints

- The number of nodes in the tree is in the range `[0, 5000]`.
- `-10^4 <= Node.val <= 10^4`.

---

## Approach 1: Recursive Height Calculation

### Explanation

This approach calculates the height of the tree for each node recursively and checks if the difference in height between the left and right subtrees is at most `1`.

1. **Height Calculation**:
   - The height of a node is the maximum height of its left and right subtrees plus `1`.

2. **Balance Check**:
   - For each node, check if the left and right subtrees are balanced and if the height difference is at most `1`.

### Implementation

```cpp
class Solution {
public:
    // Helper function to calculate the height of a tree
    int height(TreeNode *root)
    {
        if(!root) // Base case: empty tree has height 0
            return 0;
        
        if(!root->left && !root->right) // Base case: leaf node has height 1
            return 1;

        // Recursively calculate the height of the left and right subtrees
        return max(height(root->left), height(root->right)) + 1;
    }

    // Function to check if the tree is balanced
    bool isBalanced(TreeNode* root) 
    {
        if(!root) // Base case: an empty tree is balanced
            return true;
        
        if(!root->left && !root->right) // Base case: a single node is balanced
            return true;

        // Recursively check if the left and right subtrees are balanced
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        // Check the balance condition for the current node
        if(left && right && abs(height(root->left) - height(root->right)) <= 1)
            return true;
        return false;
    }
};
```

### Complexity Analysis

1. **Time Complexity**: `O(n^2)`
   - For each node, the `height` function is called, which itself traverses the tree. This results in quadratic time complexity.

2. **Space Complexity**: `O(h)`
   - The recursion stack requires space proportional to the height of the tree, where `h` is the height of the tree.

---

## Approach 2: Height Caching with a Hash Map

### Explanation

This approach optimizes the height calculation by storing the height of each node in a hash map. This avoids recalculating the height multiple times.

1. **Height Calculation**:
   - Use a helper function `calculateHeight` to compute and store the height of each node in a hash map.

2. **Balance Check**:
   - Use the precomputed heights from the hash map to check if the tree is balanced.

### Implementation

```cpp
class Solution {
private:
    unordered_map<TreeNode*, int> height_map; // Hash map to store the height of each node

public:
    // Helper function to calculate the height of a tree and store it in the hash map
    int calculateHeight(TreeNode *root)
    {
        if(!root) // Base case: empty tree has height 0
            return 0;
        
        if(!root->left && !root->right) // Base case: leaf node has height 1
        {
            height_map[root] = 1; // Store the height in the hash map
            return 1;
        }
            
        // Recursively calculate the height of the left and right subtrees
        int height = max(calculateHeight(root->left), calculateHeight(root->right)) + 1;
        height_map[root] = height; // Store the height in the hash map
        return height;
    }

    // Helper function to check if the tree is balanced using the hash map
    bool checkBalanced(TreeNode* root)
    {
        if(!root) // Base case: an empty tree is balanced
            return true;
        
        if(!root->left && !root->right) // Base case: a single node is balanced
            return true;
        
        // Recursively check if the left and right subtrees are balanced
        bool left = checkBalanced(root->left);
        bool right = checkBalanced(root->right);
        
        // Check the balance condition for the current node using the hash map
        if(left && right && abs(height_map[root->left] - height_map[root->right]) <= 1)
            return true;
        return false;
    }

    // Main function to check if the tree is balanced
    bool isBalanced(TreeNode* root) 
    {
        if(!root) // Base case: an empty tree is balanced
            return true;
        
        if(!root->left && !root->right) // Base case: a single node is balanced
            return true;

        calculateHeight(root); // Calculate and store the height of each node
        return checkBalanced(root); // Check if the tree is balanced
    }
};
```

### Complexity Analysis

1. **Time Complexity**: `O(n)`
   - The height of each node is calculated once and stored in the hash map. The balance check also traverses the tree once.

2. **Space Complexity**: `O(n)`
   - The hash map stores the height of each node, and the recursion stack requires space proportional to the height of the tree.

---

## Approach 3: Optimized Single Traversal

### Explanation

This approach combines the height calculation and balance check into a single traversal. It uses a helper function `checkHeight` that returns `-1` if the tree is unbalanced and the height of the tree otherwise.

1. **Single Traversal**:
   - For each node, calculate the height of the left and right subtrees.
   - If the height difference is greater than `1`, return `-1` to indicate that the tree is unbalanced.

2. **Early Termination**:
   - If a subtree is unbalanced, propagate `-1` upwards to avoid unnecessary calculations.

### Implementation

```cpp
class Solution {
public:
    // Helper function to calculate height and check balance in a single traversal
    int checkHeight(TreeNode* root) {
        if (!root) return 0; // Base case: empty tree has height 0

        // Recursively calculate the height of the left subtree
        int leftHeight = checkHeight(root->left);
        if (leftHeight == -1) return -1; // If left subtree is unbalanced, propagate -1

        // Recursively calculate the height of the right subtree
        int rightHeight = checkHeight(root->right);
        if (rightHeight == -1) return -1; // If right subtree is unbalanced, propagate -1

        // Check the balance condition for the current node
        if (abs(leftHeight - rightHeight) > 1)
            return -1; // If unbalanced, propagate -1

        // Return the height of the current node
        return max(leftHeight, rightHeight) + 1;
    }

    // Main function to check if the tree is balanced
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1; // If the result is -1, the tree is unbalanced
    }
};
```

### Complexity Analysis

1. **Time Complexity**: `O(n)`
   - Each node is visited once, and the height is calculated in the same traversal.

2. **Space Complexity**: `O(h)`
   - The recursion stack requires space proportional to the height of the tree.

---

## Applications

1. **Tree Validation**:
   - Checking if a tree is balanced is a common operation in tree-based data structures like AVL trees.

2. **Algorithm Design**:
   - Balanced trees are used in algorithms that require efficient search, insertion, and deletion operations.

3. **Real-World Systems**:
   - Balanced trees are used in databases and file systems to ensure efficient data access.

---

## References

- [Leetcode Problem 110](https://leetcode.com/problems/balanced-binary-tree/)
