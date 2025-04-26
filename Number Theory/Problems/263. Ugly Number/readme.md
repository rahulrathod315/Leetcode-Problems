# 263. Ugly Number

This folder contains the solution to the Leetcode problem **263. Ugly Number** implemented in C++.

---

## Problem Description

An **ugly number** is a positive integer whose prime factors are limited to `2`, `3`, and `5`.

Given an integer `n`, return `true` if `n` is an **ugly number**.

### Example 1

```
Input: n = 6
Output: true
Explanation: 6 = 2 × 3
```

### Example 2

```
Input: n = 1
Output: true
Explanation: 1 has no prime factors, so it is considered an ugly number.
```

### Example 3

```
Input: n = 14
Output: false
Explanation: 14 is not ugly since it includes the prime factor 7.
```

### Constraints

- `-2^31 <= n <= 2^31 - 1`

---

## Basic Concepts

### Prime Factorization

Prime factorization is the process of breaking down a number into its prime factors. For example:
- `6 = 2 × 3`
- `14 = 2 × 7`

In this problem, a number is considered **ugly** if its prime factors are limited to `2`, `3`, and `5`.

### Key Observations

1. If `n` is divisible by `2`, `3`, or `5`, we can repeatedly divide `n` by these numbers until it becomes `1`.
2. If `n` becomes `1`, it is an ugly number. Otherwise, it is not.

---

## Approach 1: Iterative Division

### Explanation

1. If `n` is less than or equal to `0`, return `false` since negative numbers and `0` are not considered ugly.
2. While `n` is not equal to `1`:
   - Check if `n` is divisible by `2`, `3`, or `5`.
   - If not, return `false`.
   - Otherwise, divide `n` by the appropriate factor (`2`, `3`, or `5`).
3. If the loop completes and `n` becomes `1`, return `true`.

### Implementation

```cpp
class Solution {
public:
    bool isUgly(int n) 
    {
        if(n <= 0) // Negative numbers and 0 are not ugly
            return false;

        while(n != 1) // Continue until n becomes 1
        {
            if(n % 2 != 0 && n % 3 != 0 && n % 5 != 0) // If n is not divisible by 2, 3, or 5
                return false;
            if(n % 2 == 0) // Divide by 2 if divisible
                n = n / 2;
            else if(n % 3 == 0) // Divide by 3 if divisible
                n = n / 3;
            else // Divide by 5 if divisible
                n = n / 5;
        }
        return true; // If n becomes 1, it is an ugly number
    }
};
```

### Example Walkthrough

#### Input: `n = 6`

1. `n = 6`: Divisible by `2`, divide by `2` → `n = 3`.
2. `n = 3`: Divisible by `3`, divide by `3` → `n = 1`.
3. `n = 1`: Return `true`.

#### Input: `n = 14`

1. `n = 14`: Divisible by `2`, divide by `2` → `n = 7`.
2. `n = 7`: Not divisible by `2`, `3`, or `5`. Return `false`.

### Complexity Analysis

1. **Time Complexity**: `O(log n)`
   - The number is repeatedly divided by `2`, `3`, or `5` until it becomes `1`.
2. **Space Complexity**: `O(1)`
   - No additional space is used.

---

## Approach 2: Optimized Iterative Division

### Explanation

This approach is similar to Approach 1 but uses a loop to divide `n` by `2`, `3`, and `5` in sequence. This reduces redundancy in the code.

1. If `n` is less than or equal to `0`, return `false`.
2. For each factor (`2`, `3`, `5`):
   - While `n` is divisible by the factor, divide `n` by the factor.
3. After the loop, check if `n` is equal to `1`. If yes, return `true`; otherwise, return `false`.

### Implementation

```cpp
class Solution {
public:
    bool isUgly(int n) 
    {
        if(n <= 0) // Negative numbers and 0 are not ugly
            return false;

        // Divide n by 2, 3, and 5 as long as it is divisible
        for(int factor : {2, 3, 5})
        {
            while(n % factor == 0)
                n /= factor;
        }

        // If n becomes 1, it is an ugly number
        return n == 1;
    }
};
```

### Example Walkthrough

#### Input: `n = 6`

1. `n = 6`: Divisible by `2`, divide by `2` → `n = 3`.
2. `n = 3`: Divisible by `3`, divide by `3` → `n = 1`.
3. `n = 1`: Return `true`.

#### Input: `n = 14`

1. `n = 14`: Divisible by `2`, divide by `2` → `n = 7`.
2. `n = 7`: Not divisible by `2`, `3`, or `5`. Return `false`.

### Complexity Analysis

1. **Time Complexity**: `O(log n)`
   - The number is repeatedly divided by `2`, `3`, or `5` until it becomes `1`.
2. **Space Complexity**: `O(1)`
   - No additional space is used.

---

## Applications

1. **Number Theory**:
   - Understanding prime factorization and divisibility.
2. **Mathematical Problems**:
   - Useful in problems involving factors and divisors.
3. **Data Validation**:
   - Can be used to validate numbers based on specific criteria.

---

## References

- [Leetcode Problem 263](https://leetcode.com/problems/ugly-number/)
