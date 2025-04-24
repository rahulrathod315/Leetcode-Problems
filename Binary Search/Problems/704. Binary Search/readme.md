# 704. Binary Search

This folder contains the solution to the Leetcode problem **704. Binary Search** implemented in C++.

## Problem Description

Given a sorted array of integers `nums` and an integer `target`, write a function to search for `target` in `nums`. If `target` exists, return its index. Otherwise, return `-1`.

### Example 1

```
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4.
```

### Example 2

```
Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums, so return -1.
```

### Constraints

- `1 <= nums.length <= 10^4`
- `-10^4 < nums[i], target < 10^4`
- All integers in `nums` are unique.
- `nums` is sorted in ascending order.

---

## Basic Concept

Binary Search is an efficient algorithm for finding an element in a sorted array. It works by repeatedly dividing the search interval in half.

Key concepts:
1. **Sorted Array**:
   - Binary Search requires the input array to be sorted in ascending or descending order.

2. **Divide and Conquer**:
   - The algorithm eliminates half of the search space in each iteration by comparing the middle element with the target.

3. **Efficiency**:
   - Binary Search has a time complexity of `O(log n)`, making it much faster than linear search for large datasets.

4. **Applications**:
   - Used in searching, optimization problems, and finding bounds in sorted arrays.

---

## Approach

The problem can be solved using the **Binary Search** algorithm. Binary Search is an efficient algorithm for finding an element in a sorted array by repeatedly dividing the search interval in half.

### Key Observations

1. **Sorted Array**:
   - Since the array is sorted, we can leverage this property to eliminate half of the search space in each iteration.

2. **Binary Search Logic**:
   - Start with two pointers: `start` (beginning of the array) and `end` (end of the array).
   - Calculate the middle index `mid` as:
     ```
     mid = start + (end - start) / 2
     ```
     This formula avoids overflow when `start` and `end` are large.
   - Compare the middle element `nums[mid]` with the `target`:
     - If `nums[mid] == target`, return `mid`.
     - If `nums[mid] > target`, search in the left half by updating `end = mid - 1`.
     - If `nums[mid] < target`, search in the right half by updating `start = mid + 1`.
   - If the `target` is not found, return `-1`.

---

## Implementation

Here is the implementation of the solution in C++:

```cpp
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int start = 0; // Start of the search range
        int end = nums.size() - 1; // End of the search range

        while(start <= end)
        {
            int mid = start + (end - start) / 2; // Calculate the middle index

            if(nums[mid] == target) // Check if the middle element is the target
                return mid;
            else if(nums[mid] > target) // If the target is smaller, search the left half
                end = mid - 1;
            else // If the target is larger, search the right half
                start = mid + 1;
        }
        return -1; // Target not found
    }
};
```

---

## Explanation of the Code

1. **Initialization**:
   - `start` is the beginning of the search range.
   - `end` is the end of the search range.

2. **Binary Search Loop**:
   - Calculate the middle index `mid` using `start + (end - start) / 2` to avoid overflow.
   - Compare `nums[mid]` with `target`:
     - If `nums[mid] == target`, return `mid` (the index of the target).
     - If `nums[mid] > target`, move the search range to the left by updating `end = mid - 1`.
     - If `nums[mid] < target`, move the search range to the right by updating `start = mid + 1`.

3. **Return Result**:
   - If the loop exits without finding the target, return `-1`.

---

## Complexity Analysis

1. **Time Complexity**: `O(log n)`
   - The binary search algorithm reduces the search space by half in each iteration, resulting in logarithmic time complexity.

2. **Space Complexity**: `O(1)`
   - The solution uses a constant amount of extra space.

---

## Example Walkthrough

### Input: `nums = [-1,0,3,5,9,12]`, `target = 9`

1. Initial range: `start = 0`, `end = 5`.
2. First iteration:
   - `mid = 2`, `nums[mid] = 3`.
   - `3 < 9`, so update `start = 3`.
3. Second iteration:
   - `mid = 4`, `nums[mid] = 9`.
   - `9 == 9`, so return `4`.

Output: `4`.

---

## Applications

- Binary Search is a fundamental algorithm used in many applications, including:
  - Searching in sorted arrays or lists.
  - Finding the lower or upper bound in a range.
  - Solving optimization problems with monotonic functions.

---

## References

- [Leetcode Problem 704](https://leetcode.com/problems/binary-search/)
