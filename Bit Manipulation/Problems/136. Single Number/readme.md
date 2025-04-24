# 136. Single Number

This folder contains the solution to the Leetcode problem **136. Single Number** implemented in C++.

## Problem Description

Given a **non-empty** array of integers `nums`, every element appears **twice** except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

### Example 1

```
Input: nums = [2,2,1]
Output: 1
```

### Example 2

```
Input: nums = [4,1,2,1,2]
Output: 4
```

### Example 3

```
Input: nums = [1]
Output: 1
```

### Constraints

- `1 <= nums.length <= 3 * 10^4`
- `-3 * 10^4 <= nums[i] <= 3 * 10^4`
- Each element in the array appears twice except for one element which appears only once.

---

## Basic Concept

The problem of finding the single number in an array where every other number appears twice is a classic application of bitwise operations.

Key concepts:
1. **Properties of XOR**:
   - `a ^ a = 0` (any number XORed with itself is `0`).
   - `a ^ 0 = a` (any number XORed with `0` remains unchanged).
   - XOR is commutative and associative, meaning the order of operations does not matter.

2. **Eliminating Duplicates**:
   - By XORing all the numbers in the array, the duplicate numbers cancel out, leaving only the unique number.

3. **Efficiency**:
   - This approach requires only a single pass through the array and uses constant space, making it highly efficient.

4. **Applications**:
   - Used in error detection, cryptography, and problems involving unique elements.

---

## Approach

The problem can be solved using the **XOR (Exclusive OR)** operation. XOR has the following properties:

1. `a ^ a = 0` (any number XORed with itself is 0).
2. `a ^ 0 = a` (any number XORed with 0 remains unchanged).
3. XOR is **commutative** and **associative**, meaning the order of operations does not matter.

Using these properties, if we XOR all the numbers in the array, the numbers that appear twice will cancel each other out, leaving only the number that appears once.

---

## Implementation

Here is the implementation of the solution in C++:

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int result = 0; // Initialize result to 0
        for(auto i : nums) // Iterate through all numbers in the array
            result ^= i; // XOR each number with result
        return result; // Return the single number
    }
};
```

---

## Explanation of the Code

1. **Initialization**:
   - Initialize `result` to `0`.

2. **Iterate Through the Array**:
   - For each number `i` in the array `nums`, XOR it with `result`.
   - Numbers that appear twice will cancel each other out due to the XOR operation.

3. **Return the Result**:
   - After processing all numbers, `result` will contain the single number.

---

## Complexity Analysis

1. **Time Complexity**: `O(n)`
   - The algorithm iterates through the array once, where `n` is the size of the array.

2. **Space Complexity**: `O(1)`
   - The solution uses only a constant amount of extra space.

---

## Example Walkthrough

### Input: `nums = [4,1,2,1,2]`

1. Initialize `result = 0`.
2. XOR each number with `result`:
   - `result = 0 ^ 4 = 4`
   - `result = 4 ^ 1 = 5`
   - `result = 5 ^ 2 = 7`
   - `result = 7 ^ 1 = 6`
   - `result = 6 ^ 2 = 4`
3. Final `result = 4`.

Output: `4`.

---

## Applications

1. **Finding Unique Elements**:
   - This approach is useful for finding unique elements in arrays where all other elements appear in pairs.

2. **Bit Manipulation**:
   - Demonstrates the power of XOR in solving problems efficiently with constant space.

3. **Error Detection**:
   - XOR is widely used in error detection algorithms like checksums.

---

## References

- [Leetcode Problem 136](https://leetcode.com/problems/single-number/)
