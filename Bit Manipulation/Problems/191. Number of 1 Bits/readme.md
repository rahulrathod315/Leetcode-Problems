# 191. Number of 1 Bits

This folder contains the solution to the Leetcode problem **191. Number of 1 Bits** implemented in C++.

## Problem Description

Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

### Example 1

```
Input: n = 00000000000000000000000000001011
Output: 3
Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.
```

### Example 2

```
Input: n = 00000000000000000000000010000000
Output: 1
Explanation: The input binary string 00000000000000000000000010000000 has a total of one '1' bit.
```

### Example 3

```
Input: n = 11111111111111111111111111111101
Output: 31
Explanation: The input binary string 11111111111111111111111111111101 has a total of thirty-one '1' bits.
```

### Constraints

- The input must be a **binary string** of length `32`.

---

## Approach

### Explanation

The problem can be solved using bit manipulation. The idea is to repeatedly check the least significant bit of the number and count how many times it is `1`. This can be achieved using the following steps:

1. **Check the Least Significant Bit**:
   - Use the bitwise AND operation (`n & 1`) to check if the least significant bit of `n` is `1`.
   - If it is `1`, increment the count.

2. **Right Shift the Number**:
   - Use the right shift operator (`n >> 1`) to discard the least significant bit and move to the next bit.

3. **Repeat Until `n` Becomes 0**:
   - Continue the process until all bits of `n` have been processed.

---

### Implementation

```cpp
class Solution {
public:
    int hammingWeight(int n) 
    {
        int count = 0; // Initialize the count of '1' bits
        while(n) // Loop until n becomes 0
        {
            count += (n & 1); // Check if the least significant bit is 1
            n = n >> 1; // Right shift n to process the next bit
        }    
        return count; // Return the total count of '1' bits
    }
};
```

---

### Example Walkthrough

#### Input: `n = 00000000000000000000000000001011`

1. **Initialization**:
   - `count = 0`.

2. **First Iteration**:
   - `n = 00000000000000000000000000001011`.
   - `n & 1 = 1` (least significant bit is `1`).
   - Increment `count` to `1`.
   - Right shift `n`: `n = 00000000000000000000000000000101`.

3. **Second Iteration**:
   - `n = 00000000000000000000000000000101`.
   - `n & 1 = 1` (least significant bit is `1`).
   - Increment `count` to `2`.
   - Right shift `n`: `n = 00000000000000000000000000000010`.

4. **Third Iteration**:
   - `n = 00000000000000000000000000000010`.
   - `n & 1 = 0` (least significant bit is `0`).
   - `count` remains `2`.
   - Right shift `n`: `n = 00000000000000000000000000000001`.

5. **Fourth Iteration**:
   - `n = 00000000000000000000000000000001`.
   - `n & 1 = 1` (least significant bit is `1`).
   - Increment `count` to `3`.
   - Right shift `n`: `n = 00000000000000000000000000000000`.

6. **Termination**:
   - `n = 0`, exit the loop.
   - Final `count = 3`.

Output: `3`.

---

### Complexity Analysis

1. **Time Complexity**: `O(32)` (or `O(1)`):
   - The loop runs at most 32 times, as the input is a 32-bit integer.

2. **Space Complexity**: `O(1)`:
   - The solution uses a constant amount of extra space.

---

## Applications

1. **Bit Manipulation**:
   - This problem demonstrates the use of bitwise operations to efficiently solve problems involving binary representations.

2. **Hamming Weight**:
   - The Hamming weight is used in error detection and correction algorithms, such as Hamming codes.

3. **Cryptography**:
   - Counting the number of `1` bits is used in cryptographic algorithms to measure randomness or entropy.

---

## References

- [Leetcode Problem 191](https://leetcode.com/problems/number-of-1-bits/)
