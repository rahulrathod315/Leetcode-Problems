# 326. Power of Three

This folder contains the solution to the Leetcode problem **326. Power of Three** implemented in C++.

## Problem Description

Given an integer `n`, return `true` if it is a power of three. Otherwise, return `false`.

An integer `n` is a power of three if there exists an integer `x` such that `n == 3^x`.

---

### Example 1

```
Input: n = 27
Output: true
Explanation: 27 = 3^3
```

### Example 2

```
Input: n = 0
Output: false
Explanation: 0 is not a power of three.
```

### Example 3

```
Input: n = 9
Output: true
Explanation: 9 = 3^2
```

### Example 4

```
Input: n = 45
Output: false
Explanation: 45 is not a power of three.
```

### Constraints

- `-2^31 <= n <= 2^31 - 1`

---

## Basic Concept

To determine if a number `n` is a power of three, we need to check if it can be expressed as `3^x` for some integer `x`. This means:

1. **Positive Numbers Only**:
   - Negative numbers and zero cannot be powers of three because `3^x` is always positive for any integer `x`.

2. **Divisibility by 3**:
   - A power of three is divisible by `3` repeatedly until it becomes `1`. For example:
     - `27` is divisible by `3` → `27 / 3 = 9`.
     - `9` is divisible by `3` → `9 / 3 = 3`.
     - `3` is divisible by `3` → `3 / 3 = 1`.

3. **Binary Representation**:
   - Unlike powers of two, powers of three do not have a specific pattern in binary representation. Therefore, we rely on mathematical checks like divisibility or recursion.

---

## Approaches

### Approach 1: Recursive Approach

#### Explanation

1. **Base Cases**:
   - If `n <= 0`, return `false` because negative numbers and zero cannot be powers of three.
   - If `n == 1`, return `true` because `3^0 = 1`.

2. **Recursive Check**:
   - If `n % 3 != 0`, return `false` because `n` is not divisible by 3.
   - Otherwise, recursively check if `n / 3` is a power of three.

---

#### Implementation

```cpp
class Solution {
public:
    bool isPowerOfThree(int n) 
    {
        if(n <= 0) // Base case: negative numbers and zero are not powers of three
            return false;
        
        if(n == 1) // Base case: 3^0 = 1
            return true;
        
        if(n % 3 != 0) // If n is not divisible by 3, it is not a power of three
            return false;
        
        return isPowerOfThree(n / 3); // Recursively check for n / 3
    }
};
```

---

#### Example Walkthrough

**Input**: `n = 27`

1. `n = 27`: `27 % 3 == 0`, recursively check `n = 9`.
2. `n = 9`: `9 % 3 == 0`, recursively check `n = 3`.
3. `n = 3`: `3 % 3 == 0`, recursively check `n = 1`.
4. `n = 1`: Base case, return `true`.

**Output**: `true`

---

#### Complexity Analysis

1. **Time Complexity**: `O(log3(n))`
   - The number is divided by `3` in each recursive call, resulting in logarithmic time complexity to the base 3.

2. **Space Complexity**: `O(log3(n))`
   - The recursion stack requires space proportional to the number of recursive calls.

---

### Approach 2: Iterative Approach

#### Explanation

1. **Base Case**:
   - If `n <= 0`, return `false` because negative numbers and zero cannot be powers of three.

2. **Iterative Check**:
   - While `n != 1`, check if `n % 3 != 0`. If true, return `false`.
   - Otherwise, divide `n` by 3 and continue.

3. **Return True**:
   - If the loop completes and `n == 1`, return `true`.

---

#### Implementation

```cpp
class Solution {
public:
    bool isPowerOfThree(int n) 
    {
        if(n <= 0) // Base case: negative numbers and zero are not powers of three
            return false;
        
        while(n != 1) // Continue until n becomes 1
        {
            if(n % 3 != 0) // If n is not divisible by 3, it is not a power of three
                return false;
            n = n / 3; // Divide n by 3
        }
        return true; // If loop completes, n is a power of three
    }
};
```

---

#### Example Walkthrough

**Input**: `n = 27`

1. `n = 27`: `27 % 3 == 0`, divide `n = 9`.
2. `n = 9`: `9 % 3 == 0`, divide `n = 3`.
3. `n = 3`: `3 % 3 == 0`, divide `n = 1`.
4. `n = 1`: Exit loop, return `true`.

**Output**: `true`

---

#### Complexity Analysis

1. **Time Complexity**: `O(log3(n))`
   - The number is divided by `3` in each iteration, resulting in logarithmic time complexity to the base 3.

2. **Space Complexity**: `O(1)`
   - The solution uses a constant amount of extra space.

---

## Applications

1. **Mathematical Problems**:
   - Checking powers of three is useful in number theory and mathematical puzzles.

2. **Data Validation**:
   - Used in scenarios where data needs to conform to specific patterns, such as powers of three.

3. **Algorithm Design**:
   - Helps in designing algorithms that rely on exponential growth or decay.

---

## References

- [Leetcode Problem 326](https://leetcode.com/problems/power-of-three/)
