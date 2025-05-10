# 278. First Bad Version

This folder contains the solution to the Leetcode problem **278. First Bad Version** implemented in C++.

## Problem Description

You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have `n` versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API `bool isBadVersion(version)` which returns whether `version` is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

### Example 1

```
Input: n = 5, bad = 4
Output: 4
Explanation:
call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true
Then 4 is the first bad version.
```

### Constraints

- `1 <= bad <= n <= 2^31 - 1`

---

## Basic Concept

The problem can be solved using **Binary Search**. The idea is to minimize the number of API calls by dividing the search space in half during each iteration.

Key concepts:
1. **Binary Search**:
   - Efficiently narrows down the search space by comparing the middle element with the target condition.

2. **API Calls**:
   - The `isBadVersion` API is used to determine whether a version is bad. The goal is to minimize the number of calls to this API.

---

## Approach 1: Binary Search

### Code

```cpp
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) 
    {
        int i = 1; // Start of the search range
        int j = n; // End of the search range
        int answer = -1; // Variable to store the result

        while(i <= j)
        {
            int mid = i + (j - i) / 2; // Calculate the middle index

            if(isBadVersion(mid)) // Check if the middle version is bad
            {
                answer = mid; // Update the answer
                j = mid - 1; // Move the search range to the left
                continue;
            }
            i = mid + 1; // Move the search range to the right
        }
        return answer; // Return the first bad version
    }
};
```

### Example Walkthrough

#### Input: `n = 5, bad = 4`

1. Initial range: `i = 1`, `j = 5`, `answer = -1`.
2. First iteration:
   - `mid = 3`, `isBadVersion(3) = false`.
   - Update `i = 4`.
3. Second iteration:
   - `mid = 4`, `isBadVersion(4) = true`.
   - Update `answer = 4`, `j = 3`.
4. Exit loop as `i > j`.

Output: `4`.

### Complexity Analysis

1. **Time Complexity**: `O(log n)`
   - The binary search reduces the search space by half in each iteration.

2. **Space Complexity**: `O(1)`
   - The solution uses a constant amount of extra space.

---

## Optimized Approach: Binary Search with Early Exit

### Code

```cpp
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) 
    {
        int low = 1, high = n;
        while (low < high) {
            int mid = low + (high - low) / 2; // Calculate the middle index
            if (isBadVersion(mid)) {
                high = mid; // Narrow down to the left half
            } else {
                low = mid + 1; // Narrow down to the right half
            }
        }
        return low; // The first bad version
    }
};
```

### Example Walkthrough

#### Input: `n = 5, bad = 4`

1. Initial range: `low = 1`, `high = 5`.
2. First iteration:
   - `mid = 3`, `isBadVersion(3) = false`.
   - Update `low = 4`.
3. Second iteration:
   - `mid = 4`, `isBadVersion(4) = true`.
   - Update `high = 4`.
4. Exit loop as `low == high`.

Output: `4`.

### Complexity Analysis

1. **Time Complexity**: `O(log n)`
   - The binary search reduces the search space by half in each iteration.

2. **Space Complexity**: `O(1)`
   - The solution uses a constant amount of extra space.

---

## References

- [Leetcode Problem 278](https://leetcode.com/problems/first-bad-version/)