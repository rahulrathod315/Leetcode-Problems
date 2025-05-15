# 81. Search in Rotated Sorted Array II

This folder contains the solution to the Leetcode problem **81. Search in Rotated Sorted Array II** implemented in C++.

## Problem Description

There is an integer array `nums` sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, `nums` is rotated at an unknown pivot index `k` (0 <= k < nums.length) such that the resulting array is `[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]` (0-indexed).

For example, `[0,1,2,4,4,4,5,6,6,7]` might be rotated at pivot index `5` and become `[4,5,6,6,7,0,1,2,4,4]`.

Given the array `nums` after the rotation and an integer `target`, return `true` if `target` is in `nums`, or `false` if it is not in `nums`.

You must decrease the overall operation complexity as much as possible.

### Example 1

```
Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
```

### Example 2

```
Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
```

### Constraints

- `1 <= nums.length <= 5000`
- `-10^4 <= nums[i] <= 10^4`
- `nums` is sorted and rotated at some pivot.

---

## Basic Concept

The problem can be solved using **Binary Search**. The key challenge is to handle duplicates in the rotated array. The idea is to use binary search while skipping duplicate elements to avoid ambiguity in determining the sorted half.

Key concepts:
1. **Binary Search**:
   - Efficiently narrows down the search space by comparing the middle element with the target.

2. **Handling Duplicates**:
   - If duplicates are present, the algorithm skips them by incrementing the `start` pointer and decrementing the `end` pointer when `nums[start] == nums[mid] == nums[end]`.

---

## Approach 1: Modified Binary Search

### Concept

1. **Binary Search with Duplicate Handling**:
   - At each step, calculate the middle index `mid`.
   - If `nums[mid] == target`, return `true`.
   - If `nums[start] == nums[mid] == nums[end]`, increment `start` and decrement `end` to skip duplicates.
   - Otherwise, determine which half of the array is sorted:
     - If the left half is sorted (`nums[start] <= nums[mid]`), check if the target lies within this range. If yes, narrow the search to the left half; otherwise, search in the right half.
     - If the right half is sorted (`nums[mid] <= nums[end]`), check if the target lies within this range. If yes, narrow the search to the right half; otherwise, search in the left half.

### Code

```cpp
class Solution {
public:
    bool search(vector<int>& nums, int target) 
    {
        int start = 0;
        int end = nums.size() - 1;

        while(start <= end)
        {
            int mid = start + (end - start) / 2; // Calculate the middle index

            if(nums[mid] == target) // Check if the middle element is the target
                return true;

            // Handle duplicates by skipping them
            if(nums[mid] == nums[start] && nums[mid] == nums[end])
            {
                start++;
                end--;
            }
            else if(nums[start] <= nums[mid]) // Left half is sorted
            {
                if(target >= nums[start] && target < nums[mid])
                    end = mid - 1; // Narrow the search range to the left half
                else
                    start = mid + 1; // Narrow the search range to the right half
            }
            else if(nums[end] >= nums[mid]) // Right half is sorted
            {
                if(target <= nums[end] && target > nums[mid])
                    start = mid + 1; // Narrow the search range to the right half
                else
                    end = mid - 1; // Narrow the search range to the left half
            }
        }
        return false; // Target not found
    }
};
```

### Example Walkthrough

#### Input: `nums = [2,5,6,0,0,1,2]`, `target = 0`

1. Initial range: `start = 0`, `end = 6`.
2. First iteration:
   - `mid = 3`, `nums[mid] = 0`.
   - `nums[mid] == target`, return `true`.

Output: `true`.

### Complexity Analysis

1. **Time Complexity**: `O(log n)` in the best case (when there are no duplicates) and `O(n)` in the worst case (when duplicates are present).

2. **Space Complexity**: `O(1)`
   - The solution uses a constant amount of extra space.

## References

- [Leetcode Problem 81](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/)