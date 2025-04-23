# 559. Maximum Depth of N-ary Tree

This folder contains the solution to the Leetcode problem **559. Maximum Depth of N-ary Tree** implemented in C++.

## Problem Description

Given a root of an N-ary tree, return its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

An N-ary tree is a tree in which each node has no more than `N` children.

---

### Example 1

```
Input: root = [1,null,3,2,4,null,5,6]
Output: 3
```

### Example 2

```
Input: root = []
Output: 0
```

### Constraints

- The total number of nodes is in the range `[0, 10^4]`.
- The depth of the tree is less than or equal to `1000`.

---

## Approach 1: Recursive Depth-First Search (DFS)

### Explanation

This approach uses recursion to traverse the tree and calculate the maximum depth.

1. **Base Case**:
   - If the root is `null`, the depth is `0`.

2. **Leaf Node**:
   - If the node has no children, the depth is `1`.

3. **Recursive Case**:
   - For each child of the current node, recursively calculate the depth.
   - The maximum depth of the tree is the maximum depth among all children plus `1` (for the current node).

---

### Implementation

```cpp
class Solution {
public:
    int maxDepth(Node* root) 
    {
        if(!root) // Base case: if the root is null, return 0
            return 0;
        
        if(root->children.size() == 0) // If the node has no children, return 1
            return 1;

        int maximum = 0; // Variable to store the maximum depth
        
        for(auto ch : root->children) // Traverse all children
        {
            maximum = max(maximum, maxDepth(ch)); // Recursively calculate the depth
        }
        return maximum + 1; // Add 1 for the current node
    }
};
```

---

### Example Walkthrough

#### Input: `root = [1,null,3,2,4,null,5,6]`

1. Start at the root node (`1`).
2. Traverse the children of `1`:
   - For child `3`, traverse its children:
     - For child `5`, return `1` (leaf node).
     - For child `6`, return `1` (leaf node).
     - Maximum depth of `3` is `2`.
   - For child `2`, return `1` (leaf node).
   - For child `4`, return `1` (leaf node).
3. Maximum depth of the tree is `3`.

---

### Complexity Analysis

1. **Time Complexity**: `O(n)`
   - Each node is visited exactly once, where `n` is the total number of nodes in the tree.

2. **Space Complexity**: `O(h)`
   - The recursion stack requires space proportional to the height of the tree, where `h` is the height of the tree.

---

## Applications

1. **Tree Traversal**:
   - Calculating the depth of a tree is a fundamental operation in tree traversal.

2. **Hierarchy Analysis**:
   - Used in analyzing hierarchical structures, such as organizational charts or file systems.

3. **Game Development**:
   - Depth calculations are used in game trees for decision-making.

---

## References

- [Leetcode Problem 559](https://leetcode.com/problems/maximum-depth-of-n-ary-tree/)
