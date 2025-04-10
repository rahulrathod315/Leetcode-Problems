# 872. Leaf-Similar Trees

This folder contains the solution to the Leetcode problem **872. Leaf-Similar Trees** implemented in C++.

## Problem Description

Consider all the leaves of a binary tree, from left to right order, as forming a **leaf value sequence**.

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return `true` if and only if the two given trees with roots `root1` and `root2` are leaf-similar.

### Example 1

```
Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
Output: true
```

### Example 2

```
Input: root1 = [1,2,3], root2 = [1,3,2]
Output: false
```

### Constraints

- The number of nodes in each tree will be in the range `[1, 200]`.
- The values of the nodes of both trees will be in the range `[0, 200]`.

---

## Approach

The problem can be solved by performing an **inorder traversal** of both trees and collecting the leaf nodes in a sequence. Then, compare the two sequences to determine if they are identical.

### Key Observations

1. **Leaf Nodes**:
   - A node is a leaf if it has no left or right child.

2. **Inorder Traversal**:
   - Traverse the tree in a depth-first manner and collect the values of the leaf nodes.

3. **Comparison**:
   - Compare the two sequences of leaf nodes to check if they are identical.

---

## Implementation

Here is the implementation of the solution in C++:

```cpp
// Helper function to perform inorder traversal and collect leaf nodes
void leafInorder(TreeNode *root, vector<int> &v)
{
    if(!root) // Base case: if the node is null, return
        return;

    leafInorder(root->left, v); // Traverse the left subtree
    if(!root->left && !root->right) // If the node is a leaf, add its value to the vector
        v.push_back(root->val);
    leafInorder(root->right, v); // Traverse the right subtree
}

// Main function to check if two trees are leaf-similar
bool leafSimilar(TreeNode* root1, TreeNode* root2) 
{
    vector<int> v1, v2; // Vectors to store the leaf sequences of the two trees

    leafInorder(root1, v1); // Collect leaf nodes of the first tree
    leafInorder(root2, v2); // Collect leaf nodes of the second tree
    
    return v1 == v2; // Compare the two leaf sequences
}
```

---

## Explanation of the Code

1. **Helper Function**:
   - `leafInorder` performs an inorder traversal of the tree and collects the values of the leaf nodes in a vector.

2. **Leaf Collection**:
   - For each tree, call `leafInorder` to collect the leaf nodes in a sequence.

3. **Comparison**:
   - Compare the two sequences of leaf nodes using the `==` operator.

---

## Complexity Analysis

1. **Time Complexity**: `O(n + m)`
   - `n` is the number of nodes in `root1`, and `m` is the number of nodes in `root2`.
   - Each node is visited once during the traversal.

2. **Space Complexity**: `O(h1 + h2)`
   - `h1` and `h2` are the heights of the two trees.
   - The recursion stack requires space proportional to the height of the tree.

---

## Example Walkthrough

### Input: 
`root1 = [3,5,1,6,2,9,8,null,null,7,4]`,  
`root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]`

1. **Leaf Sequence of `root1`**:
   - Perform an inorder traversal: `[6, 7, 4, 9, 8]`.

2. **Leaf Sequence of `root2`**:
   - Perform an inorder traversal: `[6, 7, 4, 9, 8]`.

3. **Comparison**:
   - The two sequences are identical, so the trees are leaf-similar.

Output: `true`.

---

## Applications

1. **Tree Comparison**:
   - This approach can be extended to compare other properties of trees, such as structure or node values.

2. **Data Validation**:
   - Used in scenarios where the leaf structure of two datasets needs to be validated.

3. **Binary Tree Problems**:
   - Demonstrates the use of depth-first traversal for solving tree-related problems.

---

## References

- [Leetcode Problem 872](https://leetcode.com/problems/leaf-similar-trees/)
