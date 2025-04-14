# 268. Missing Number

This folder contains the solution to the Leetcode problem **268. Missing Number** implemented in C++.

## Problem Description

Given an array `nums` containing `n` distinct numbers in the range `[0, n]`, return the only number in the range that is missing from the array.

### Example 1

```
Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
```

### Example 2

```
Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.
```

### Example 3

```
Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.
```

### Constraints

- `n == nums.length`
- `1 <= n <= 10^4`
- `0 <= nums[i] <= n`
- All the numbers of `nums` are unique.

---

## Approaches

### Approach 1: Using a Boolean Flags Array

#### Explanation

1. Create a boolean array `flags` of size `n` initialized to `false`.
2. Traverse the input array `nums` and mark the corresponding indices in `flags` as `true`.
3. Traverse the `flags` array to find the first index that is still `false`. This index is the missing number.
4. If no index is found, return `n` (the missing number is the largest number in the range).

---

#### Implementation

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        // Create a boolean array to track the presence of numbers
        vector<bool> flags(nums.size(), 0);

        // Mark the indices corresponding to the numbers in nums
        for(auto i : nums)
            flags[i] = 1;

        // Find the first index that is not marked
        for(int i = 0; i < flags.size(); i++)
            if(!flags[i])
                return i;

        // If all indices are marked, the missing number is n
        return nums.size();
    }
};
```

---

#### Example Walkthrough

##### Input: `nums = [3,0,1]`

1. **Initialization**:
   - `flags = [false, false, false, false]`.

2. **Marking Flags**:
   - For `nums[0] = 3`: `flags = [false, false, false, true]`.
   - For `nums[1] = 0`: `flags = [true, false, false, true]`.
   - For `nums[2] = 1`: `flags = [true, true, false, true]`.

3. **Finding Missing Number**:
   - Traverse `flags`:
     - `flags[0] = true` → Continue.
     - `flags[1] = true` → Continue.
     - `flags[2] = false` → Missing number is `2`.

#### Output: `2`

---

#### Complexity Analysis

1. **Time Complexity**: `O(n)`
   - Traversing the input array and the `flags` array both take linear time.

2. **Space Complexity**: `O(n)`
   - Additional space is used for the `flags` array.

---

### Approach 2: XOR-Based Solution

#### Explanation

1. Use the XOR operation to find the missing number.
2. XOR all the elements in the input array `nums` to get `xor_array`.
3. XOR all the numbers from `0` to `n` to get `xor_all`.
4. The missing number is `xor_all ^ xor_array` because the XOR operation cancels out all the numbers that appear in both `nums` and the range `[0, n]`.

---

#### Implementation

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int xor_array = 0; // XOR of all elements in nums
        int xor_all = 0;   // XOR of all numbers from 0 to n

        // XOR all elements in nums
        for(auto i : nums)
            xor_array ^= i;

        // XOR all numbers from 0 to n
        for(int i = 0; i <= nums.size(); i++)
            xor_all ^= i;

        // The missing number is the XOR of xor_all and xor_array
        return xor_all ^ xor_array;
    }
};
```

---

#### Example Walkthrough

##### Input: `nums = [3,0,1]`

1. **Initialization**:
   - `xor_array = 0`, `xor_all = 0`.

2. **XOR of Array Elements**:
   - For `nums[0] = 3`: `xor_array = 0 ^ 3 = 3`.
   - For `nums[1] = 0`: `xor_array = 3 ^ 0 = 3`.
   - For `nums[2] = 1`: `xor_array = 3 ^ 1 = 2`.

3. **XOR of Range `[0, n]`**:
   - For `i = 0`: `xor_all = 0 ^ 0 = 0`.
   - For `i = 1`: `xor_all = 0 ^ 1 = 1`.
   - For `i = 2`: `xor_all = 1 ^ 2 = 3`.
   - For `i = 3`: `xor_all = 3 ^ 3 = 0`.

4. **Result**:
   - `missing_number = xor_all ^ xor_array = 0 ^ 2 = 2`.

#### Output: `2`

---

#### Complexity Analysis

1. **Time Complexity**: `O(n)`
   - Traversing the input array and the range `[0, n]` both take linear time.

2. **Space Complexity**: `O(1)`
   - No additional space is used.

---

## Applications

1. **Data Validation**:
   - This problem is useful in scenarios where data integrity needs to be verified, such as detecting missing records in a sequence.

2. **Error Detection**:
   - XOR-based solutions are commonly used in error detection and correction algorithms.

3. **Competitive Programming**:
   - The XOR-based approach is efficient and commonly used in competitive programming for similar problems.

---

## References

- [Leetcode Problem 268](https://leetcode.com/problems/missing-number/)
