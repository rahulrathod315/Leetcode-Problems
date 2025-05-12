# 35. Search Insert Position

This folder contains the solution to the Leetcode problem **35. Search Insert Position** implemented in C++.

## Problem Description

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with `O(log n)` runtime complexity.

### Example 1

```
Input: nums = [1,3,5,6], target = 5
Output: 2
```

### Example 2

```
Input: nums = [1,3,5,6], target = 2
Output: 1
```

### Constraints

- `1 <= nums.length <= 10^4`
- `-10^4 <= nums[i] <= 10^4`
- `nums` contains distinct values sorted in ascending order.
- `-10^4 <= target <= 10^4`

---

## Basic Concept

The problem can be solved using **Binary Search**. The idea is to minimize the number of comparisons by dividing the search space in half during each iteration.

Key concepts:
1. **Binary Search**:
   - Efficiently narrows down the search space by comparing the middle element with the target value.

2. **Insertion Point**:
   - If the target is not found, the algorithm determines the position where the target should be inserted to maintain the sorted order.

---

## Approach 1: Binary Search with Result Variable

### Code

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int start = 0;
        int end = nums.size() - 1;

        int mid;
        int result = -1; // Variable to store the insertion index

        while(start <= end)
        {
            mid = (start + end) / 2; // Calculate the middle index

            if(nums[mid] == target) // Check if the middle element is the target
                return mid;
            else if(nums[mid] < target) // Target is in the right half
            {
                result = mid + 1; // Update the insertion index
                start = mid + 1;
            }
            else // Target is in the left half
            {
                result = mid; // Update the insertion index
                end = mid - 1;
            }
        }

        return result; // Return the insertion index
    }
};
```

### Example Walkthrough

#### Input: `nums = [1,3,5,6], target = 2`

1. Initial range: `start = 0`, `end = 3`, `result = -1`.
2. First iteration:
   - `mid = 1`, `nums[mid] = 3`.
   - `target < nums[mid]`, update `result = 1`, `end = 0`.
3. Second iteration:
   - `mid = 0`, `nums[mid] = 1`.
   - `target > nums[mid]`, update `result = 1`, `start = 1`.
4. Exit loop as `start > end`.

Output: `1`.

### Complexity Analysis

1. **Time Complexity**: `O(log n)`
   - The binary search reduces the search space by half in each iteration.

2. **Space Complexity**: `O(1)`
   - The solution uses a constant amount of extra space.

---

## Approach 2: Binary Search with Early Return

### Code

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int start = 0;
        int end = nums.size() - 1;

        while(start <= end)
        {
            int mid = start + (end - start) / 2; // Calculate the middle index

            if(nums[mid] == target) // Check if the middle element is the target
                return mid;
            else if(nums[mid] < target) // Target is in the right half
                start = mid + 1;
            else // Target is in the left half
                end = mid - 1;
        }

        return start; // Return the insertion index
    }
};
```

### Example Walkthrough

#### Input: `nums = [1,3,5,6], target = 2`

1. Initial range: `start = 0`, `end = 3`.
2. First iteration:
   - `mid = 1`, `nums[mid] = 3`.
   - `target < nums[mid]`, update `end = 0`.
3. Second iteration:
   - `mid = 0`, `nums[mid] = 1`.
   - `target > nums[mid]`, update `start = 1`.
4. Exit loop as `start > end`.

Output: `1`.

### Complexity Analysis

1. **Time Complexity**: `O(log n)`
   - The binary search reduces the search space by half in each iteration.

2. **Space Complexity**: `O(1)`
   - The solution uses a constant amount of extra space.

---

## Optimized Approach: Binary Search with Minimal Variables

### Code

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int low = 0, high = nums.size();
        while (low < high) {
            int mid = low + (high - low) / 2; // Calculate the middle index
            if (nums[mid] < target)
                low = mid + 1; // Narrow down to the right half
            else
                high = mid; // Narrow down to the left half
        }
        return low; // The insertion index
    }
};
```

### Example Walkthrough

#### Input: `nums = [1,3,5,6], target = 2`

1. Initial range: `low = 0`, `high = 4`.
2. First iteration:
   - `mid = 2`, `nums[mid] = 5`.
   - `target < nums[mid]`, update `high = 2`.
3. Second iteration:
   - `mid = 1`, `nums[mid] = 3`.
   - `target < nums[mid]`, update `high = 1`.
4. Third iteration:
   - `mid = 0`, `nums[mid] = 1`.
   - `target > nums[mid]`, update `low = 1`.
5. Exit loop as `low == high`.

Output: `1`.

### Complexity Analysis

1. **Time Complexity**: `O(log n)`
   - The binary search reduces the search space by half in each iteration.

2. **Space Complexity**: `O(1)`
   - The solution uses a constant amount of extra space.

---

## References

- [Leetcode Problem 35](https://leetcode.com/problems/search-insert-position/)