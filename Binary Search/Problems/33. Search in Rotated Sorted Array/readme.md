# 33. Search in Rotated Sorted Array

This folder contains the solution to the Leetcode problem **33. Search in Rotated Sorted Array** implemented in C++.

## Problem Description

There is an integer array `nums` sorted in ascending order (with **distinct** values).

Prior to being passed to your function, `nums` is possibly rotated at an unknown pivot index `k` (1 <= k < nums.length) such that the resulting array is `[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]` (0-indexed).

For example, `[0,1,2,4,5,6,7]` might be rotated at pivot index `3` and become `[4,5,6,7,0,1,2]`.

Given the array `nums` after the possible rotation and an integer `target`, return the index of `target` if it is in `nums`, or `-1` if it is not in `nums`.

You must write an algorithm with `O(log n)` runtime complexity.

### Example 1

```
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
```

### Example 2

```
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
```

### Constraints

- `1 <= nums.length <= 5000`
- `-10^4 <= nums[i] <= 10^4`
- All values of `nums` are unique.
- `nums` is guaranteed to be rotated at some pivot.

---

## Basic Concept

The problem can be solved using **Binary Search**. The key challenge is to handle the rotation in the array. The idea is to first find the pivot (the smallest element in the array) and then perform binary search in the appropriate half of the array.

Key concepts:
1. **Binary Search**:
   - Efficiently narrows down the search space by comparing the middle element with the target.

2. **Rotation Handling**:
   - The array is divided into two sorted halves at the pivot. By identifying the pivot, we can determine which half to search in.

3. **Rotation Count**:
   - The number of times the array is rotated is equal to the index of the pivot (smallest element). For example, if the array `[4,5,6,7,0,1,2]` is rotated 4 times, the pivot `0` is at index `4`.

---

## Approach 1: Find Pivot and Binary Search

### Concept

1. **Find the Pivot**:
   - The pivot is the smallest element in the rotated array. It can be found using binary search by comparing the middle element with its neighbors.
   - If the middle element is smaller than both its previous and next elements, it is the pivot.
   - If the middle element is greater than the first element, the pivot lies in the right half.
   - Otherwise, the pivot lies in the left half.

2. **Binary Search**:
   - Once the pivot is found, the array is divided into two sorted halves.
   - Perform binary search in the appropriate half based on the target value.

### Code

```cpp
class Solution {
public:
    // Function to find the index of the pivot (smallest element)
    int findRotationCount(vector<int> &nums)
    {
        int start = 0;
        int end = nums.size() - 1;
        int n = end - start + 1; // Total number of elements

        while(start <= end)
        {
            int mid = start + (end - start) / 2; // Calculate the middle index
            int pre = (mid - 1 + n) % n; // Previous element (circular indexing)
            int next = (mid + 1) % n; // Next element (circular indexing)

            // Check if the middle element is the pivot
            if(nums[mid] < nums[pre] && nums[mid] < nums[next])
                return mid; // Pivot found

            // If the left half is sorted, pivot must be in the right half
            else if(nums[0] <= nums[mid])
                start = mid + 1;

            // Otherwise, pivot must be in the left half
            else
                end = mid - 1;
        }
        return 0; // Default case (array is not rotated)
    }

    // Standard binary search function
    int binarySearch(vector<int> &nums, int start, int end, int target)
    {
        while(start <= end)
        {
            int mid = start + (end - start) / 2; // Calculate the middle index

            if(nums[mid] == target) // Target found
                return mid;
            else if(nums[mid] < target) // Target is in the right half
                start = mid + 1;
            else // Target is in the left half
                end = mid - 1;
        }
        return -1; // Target not found
    }

    // Main function to search for the target in the rotated array
    int search(vector<int>& nums, int target) 
    {
        int rotation_count = findRotationCount(nums); // Find the pivot index

        // If the array is not rotated, perform binary search on the entire array
        if(rotation_count == 0)
            return binarySearch(nums, 0, nums.size() - 1, target);

        // If the target lies in the right half (from pivot to end)
        else if(target >= nums[rotation_count] && target <= nums[nums.size() - 1])
            return binarySearch(nums, rotation_count, nums.size() - 1, target);

        // Otherwise, search in the left half (from start to pivot-1)
        return binarySearch(nums, 0, rotation_count - 1, target);
    }
};
```

### Example Walkthrough

#### Input: `nums = [4,5,6,7,0,1,2]`, `target = 0`

1. **Find Pivot**:
   - Initial range: `start = 0`, `end = 6`.
   - First iteration: `mid = 3`, `nums[mid] = 7`.
     - `nums[mid] > nums[0]`, so update `start = 4`.
   - Second iteration: `mid = 5`, `nums[mid] = 1`.
     - `nums[mid] < nums[mid-1]`, so pivot is `5`.

2. **Binary Search**:
   - Target `0` lies in the left half (`[0,1,2]`).
   - Perform binary search in range `4-6`.
   - Return index `4`.

Output: `4`.

### Complexity Analysis

1. **Time Complexity**: `O(log n)`
   - Finding the pivot takes `O(log n)`.
   - Binary search takes `O(log n)`.

2. **Space Complexity**: `O(1)`
   - The solution uses a constant amount of extra space.

---

## Optimized Approach: Single Pass Binary Search

### Concept

Instead of finding the pivot and then performing binary search, we can modify the binary search logic to handle the rotation directly. At each step, we determine which half of the array is sorted and decide where to search next.

### Code

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int start = 0, end = nums.size() - 1;

        while(start <= end)
        {
            int mid = start + (end - start) / 2;

            if(nums[mid] == target)
                return mid;

            // Check if the left half is sorted
            if(nums[start] <= nums[mid])
            {
                if(target >= nums[start] && target < nums[mid])
                    end = mid - 1;
                else
                    start = mid + 1;
            }
            else // Right half is sorted
            {
                if(target > nums[mid] && target <= nums[end])
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }
        return -1;
    }
};
```

### Complexity Analysis

1. **Time Complexity**: `O(log n)`
   - The binary search logic ensures logarithmic time complexity.

2. **Space Complexity**: `O(1)`
   - The solution uses a constant amount of extra space.

---

## References

- [Leetcode Problem 33](https://leetcode.com/problems/search-in-rotated-sorted-array/)