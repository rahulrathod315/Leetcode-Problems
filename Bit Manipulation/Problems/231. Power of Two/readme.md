# 231. Power of Two

This folder contains the solution to the Leetcode problem **231. Power of Two** implemented in C++.

## Problem Description

Given an integer `n`, return `true` if it is a power of two. Otherwise, return `false`.

An integer `n` is a power of two if there exists an integer `x` such that `n == 2^x`.

---

### Example 1

```
Input: n = 1
Output: true
Explanation: 2^0 = 1
```

### Example 2

```
Input: n = 16
Output: true
Explanation: 2^4 = 16
```

### Example 3

```
Input: n = 3
Output: false
```

### Constraints

- `-2^31 <= n <= 2^31 - 1`

---

## Approaches

### Approach 1: Recursive Division by 2

#### Explanation

1. **Base Cases**:
   - If `n <= 0`, return `false` because negative numbers and zero cannot be powers of two.
   - If `n <= 2`, return `true` because `1` and `2` are powers of two.

2. **Recursive Check**:
   - If `n` is not divisible by `2`, return `false`.
   - Otherwise, recursively check if `n / 2` is a power of two.

---

#### Implementation

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        if(n <= 0) // Base case: negative numbers and zero are not powers of two
            return false;
        if(n <= 2) // Base case: 1 and 2 are powers of two
            return true;
        if(n % 2 != 0) // If n is not divisible by 2, return false
            return false;
        return isPowerOfTwo(n / 2); // Recursively check for n / 2
    }
};
```

---

#### Example Walkthrough

**Input**: `n = 16`

1. `n = 16`: `16 % 2 == 0`, recursively check `n = 8`.
2. `n = 8`: `8 % 2 == 0`, recursively check `n = 4`.
3. `n = 4`: `4 % 2 == 0`, recursively check `n = 2`.
4. `n = 2`: Base case, return `true`.

**Output**: `true`

---

#### Complexity Analysis

1. **Time Complexity**: `O(log n)`
   - The number is divided by `2` in each recursive call, resulting in logarithmic time complexity.

2. **Space Complexity**: `O(log n)`
   - The recursion stack requires space proportional to the number of recursive calls.

---

### Approach 2: Iterative Division by 2

#### Explanation

1. **Iterative Check**:
   - While `n` is greater than `1`, check if `n` is divisible by `2`.
   - If `n` is not divisible by `2`, return `false`.
   - Otherwise, divide `n` by `2` and continue.

2. **Final Check**:
   - If the loop exits and `n == 1`, return `true`.

---

#### Implementation

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        while(n != 1) // Loop until n becomes 1
        {
            if(n <= 0 || n % 2 != 0) // If n is negative, zero, or not divisible by 2, return false
                return false;
            n = n / 2; // Divide n by 2
        }
        return true; // If n becomes 1, it is a power of two
    }
};
```

---

#### Example Walkthrough

**Input**: `n = 16`

1. `n = 16`: `16 % 2 == 0`, divide `n = 8`.
2. `n = 8`: `8 % 2 == 0`, divide `n = 4`.
3. `n = 4`: `4 % 2 == 0`, divide `n = 2`.
4. `n = 2`: `2 % 2 == 0`, divide `n = 1`.
5. `n = 1`: Exit loop, return `true`.

**Output**: `true`

---

#### Complexity Analysis

1. **Time Complexity**: `O(log n)`
   - The number is divided by `2` in each iteration, resulting in logarithmic time complexity.

2. **Space Complexity**: `O(1)`
   - The solution uses a constant amount of extra space.

---

### Approach 3: Bit Manipulation

#### Explanation

1. **Binary Representation**:
   - A number is a power of two if it has exactly one `1` bit in its binary representation.
   - For example:
     - `1 (2^0) = 0001`
     - `2 (2^1) = 0010`
     - `4 (2^2) = 0100`

2. **Count the Number of `1` Bits**:
   - Use bitwise AND (`n & 1`) to check the least significant bit of `n`.
   - Right shift `n` by `1` (`n = n >> 1`) to process the next bit.
   - Count the number of `1` bits. If the count is `1`, `n` is a power of two.

---

#### Implementation

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        if(n <= 0) // Negative numbers and zero are not powers of two
            return false;
            
        int count = 0; // Variable to count the number of 1 bits
        while(n) // Loop until n becomes 0
        {
            count += n & 1; // Add the least significant bit to the count
            n = n >> 1; // Right shift n to process the next bit
        }
        return count == 1; // Return true if there is exactly one 1 bit
    }
};
```

---

#### Example Walkthrough

**Input**: `n = 16`

1. `n = 16`: `count = 0`, `16 & 1 = 0`, right shift `n = 8`.
2. `n = 8`: `count = 0`, `8 & 1 = 0`, right shift `n = 4`.
3. `n = 4`: `count = 0`, `4 & 1 = 0`, right shift `n = 2`.
4. `n = 2`: `count = 0`, `2 & 1 = 0`, right shift `n = 1`.
5. `n = 1`: `count = 1`, `1 & 1 = 1`, right shift `n = 0`.
6. `n = 0`: Exit loop, `count == 1`.

**Output**: `true`

---

#### Complexity Analysis

1. **Time Complexity**: `O(log n)`
   - The number is right-shifted in each iteration, resulting in logarithmic time complexity.

2. **Space Complexity**: `O(1)`
   - The solution uses a constant amount of extra space.

---

## Applications

1. **Bit Manipulation**:
   - Demonstrates the use of bitwise operations to solve problems efficiently.

2. **Power of Two Checks**:
   - Used in algorithms that require power-of-two constraints, such as memory allocation and hash table sizing.

3. **Mathematical Problems**:
   - Useful in problems involving exponential growth or binary representations.

---

## References

- [Leetcode Problem 231](https://leetcode.com/problems/power-of-two/)
