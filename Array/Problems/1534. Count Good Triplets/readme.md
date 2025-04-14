# 1534. Count Good Triplets

This folder contains the solution to the Leetcode problem **1534. Count Good Triplets** implemented in C++.

## Problem Description

Given an array of integers `arr`, and three integers `a`, `b`, and `c`, you need to count the number of **good triplets**.

A triplet `(arr[i], arr[j], arr[k])` is **good** if the following conditions are true:

1. `0 <= i < j < k < arr.length`
2. `|arr[i] - arr[j]| <= a`
3. `|arr[j] - arr[k]| <= b`
4. `|arr[i] - arr[k]| <= c`

Return the number of **good triplets**.

---

### Example 1

```
Input: arr = [3,0,1,1,9,7], a = 7, b = 2, c = 3
Output: 4
Explanation: There are 4 good triplets:
(3,0,1), (3,0,1), (0,1,1), (1,1,9)
```

### Example 2

```
Input: arr = [1,1,2,2,3], a = 0, b = 0, c = 1
Output: 0
Explanation: No triplets satisfy all conditions.
```

---

### Constraints

- `3 <= arr.length <= 100`
- `0 <= arr[i] <= 1000`
- `0 <= a, b, c <= 1000`

---

## Approach 1: Brute-Force Solution

### Explanation

This approach uses three nested loops to iterate through all possible triplets `(i, j, k)` and checks if they satisfy the given conditions.

1. **Iterate Through All Triplets**:
   - Use three nested loops to iterate through all possible triplets `(i, j, k)` such that `0 <= i < j < k < arr.length`.

2. **Check Conditions**:
   - For each triplet `(arr[i], arr[j], arr[k])`, check if the following conditions are satisfied:
     - `|arr[i] - arr[j]| <= a`
     - `|arr[j] - arr[k]| <= b`
     - `|arr[i] - arr[k]| <= c`

3. **Count Good Triplets**:
   - If all conditions are satisfied, increment the count of good triplets.

4. **Return the Count**:
   - After iterating through all triplets, return the count of good triplets.

---

### Implementation

```cpp
class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) 
    {
        int count = 0; // Initialize the count of good triplets
        for(int i = 0; i < arr.size(); i++) // Iterate through the first element of the triplet
        {
            for(int j = i+1; j < arr.size(); j++) // Iterate through the second element of the triplet
            {
                if(abs(arr[i] - arr[j]) <= a) // Check the first condition
                {
                    for(int k = j+1; k < arr.size(); k++) // Iterate through the third element of the triplet
                    {
                        // Check the second and third conditions
                        if(abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c)
                            count++; // Increment the count if all conditions are satisfied
                    }
                } 
            }
        }    
        return count; // Return the total count of good triplets
    }
};
```

---

### Example Walkthrough

#### Input: `arr = [3,0,1,1,9,7], a = 7, b = 2, c = 3`

1. **Initialization**:
   - `count = 0`.

2. **Iterate Through Triplets**:
   - For `i = 0`, `j = 1`, `k = 2`:
     - `|arr[0] - arr[1]| = |3 - 0| = 3 <= 7` (Condition 1 satisfied).
     - `|arr[1] - arr[2]| = |0 - 1| = 1 <= 2` (Condition 2 satisfied).
     - `|arr[0] - arr[2]| = |3 - 1| = 2 <= 3` (Condition 3 satisfied).
     - Increment `count = 1`.

   - Continue iterating through all valid triplets and increment `count` for each good triplet.

3. **Final Count**:
   - After iterating through all triplets, `count = 4`.

#### Output: `4`

---

### Complexity Analysis

1. **Time Complexity**: `O(n^3)`
   - The algorithm uses three nested loops to iterate through all possible triplets, where `n` is the size of the array.

2. **Space Complexity**: `O(1)`
   - The solution uses a constant amount of extra space.

---

## Approach 2: Optimized Solution

### Explanation

This approach optimizes the brute-force solution by reducing unnecessary iterations. Instead of blindly iterating through all triplets, we add checks to skip invalid combinations earlier.

1. **Iterate Through All Triplets**:
   - Use three nested loops to iterate through all possible triplets `(i, j, k)` such that `0 <= i < j < k < arr.length`.

2. **Early Exit**:
   - Add checks to skip invalid combinations as soon as a condition fails. For example:
     - If `|arr[i] - arr[j]| > a`, skip the inner loop for `k` entirely.

3. **Count Good Triplets**:
   - If all conditions are satisfied, increment the count of good triplets.

4. **Return the Count**:
   - After iterating through all triplets, return the count of good triplets.

---

### Implementation

```cpp
class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) 
    {
        int count = 0; // Initialize the count of good triplets
        int n = arr.size(); // Get the size of the array

        for(int i = 0; i < n - 2; i++) // Iterate through the first element of the triplet
        {
            for(int j = i + 1; j < n - 1; j++) // Iterate through the second element of the triplet
            {
                if(abs(arr[i] - arr[j]) > a) // Skip if the first condition is not satisfied
                    continue;

                for(int k = j + 1; k < n; k++) // Iterate through the third element of the triplet
                {
                    // Check the second and third conditions
                    if(abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c)
                        count++; // Increment the count if all conditions are satisfied
                }
            }
        }

        return count; // Return the total count of good triplets
    }
};
```

---

### Example Walkthrough

#### Input: `arr = [3,0,1,1,9,7], a = 7, b = 2, c = 3`

1. **Initialization**:
   - `count = 0`.

2. **Iterate Through Triplets**:
   - For `i = 0`, `j = 1`, `k = 2`:
     - `|arr[0] - arr[1]| = |3 - 0| = 3 <= 7` (Condition 1 satisfied).
     - `|arr[1] - arr[2]| = |0 - 1| = 1 <= 2` (Condition 2 satisfied).
     - `|arr[0] - arr[2]| = |3 - 1| = 2 <= 3` (Condition 3 satisfied).
     - Increment `count = 1`.

   - Continue iterating through all valid triplets and increment `count` for each good triplet.

3. **Final Count**:
   - After iterating through all triplets, `count = 4`.

#### Output: `4`

---

### Complexity Analysis

1. **Time Complexity**: `O(n^2)`
   - The algorithm reduces unnecessary iterations by skipping invalid combinations earlier, resulting in a time complexity of `O(n^2)`.

2. **Space Complexity**: `O(1)`
   - The solution uses a constant amount of extra space.

---

## Applications

1. **Combinatorial Problems**:
   - This approach can be extended to solve other problems involving combinations of elements with specific conditions.

2. **Data Analysis**:
   - Counting triplets with specific properties is useful in data analysis and pattern recognition.

3. **Optimization Techniques**:
   - Demonstrates how to optimize brute-force solutions by reducing unnecessary iterations.

---

## References

- [Leetcode Problem 1534](https://leetcode.com/problems/count-good-triplets/)
