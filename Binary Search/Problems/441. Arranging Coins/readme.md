# 441. Arranging Coins

This folder contains the solution to the Leetcode problem **441. Arranging Coins** implemented in C++.

## Problem Description

You have `n` coins and you want to build a staircase with these coins. The staircase consists of rows, where the `i-th` row contains exactly `i` coins. The last row of the staircase **may be incomplete**.

Given the integer `n`, return the total number of **complete rows** of the staircase you can build.

### Example 1

```
Input: n = 5
Output: 2
Explanation:
The staircase will look like this:
¤
¤ ¤
¤ ¤
The 3rd row is incomplete, so we return 2.
```

### Example 2

```
Input: n = 8
Output: 3
Explanation:
The staircase will look like this:
¤
¤ ¤
¤ ¤ ¤
¤
The 4th row is incomplete, so we return 3.
```

### Constraints

- `0 <= n <= 2^31 - 1`

---

## Approach

The problem can be solved using **Binary Search**. The idea is to find the maximum number of complete rows `k` such that the sum of the first `k` natural numbers (`k * (k + 1) / 2`) is less than or equal to `n`.

### Key Observations

1. The sum of the first `k` natural numbers is given by the formula:
   ```
   S = k * (k + 1) / 2
   ```
   This represents the total number of coins required to form `k` complete rows.

2. We need to find the largest `k` such that:
   ```
   k * (k + 1) / 2 <= n
   ```

3. Since the sum grows quadratically, we can use **Binary Search** to efficiently find the value of `k`.

---

## Implementation

Here is the implementation of the solution in C++:

```cpp
#include <iostream>

using namespace std;

class Solution {
    public:
        int arrangeCoins(int n) 
        {
            long long i = 1; // Start of the binary search range
            long long j = n; // End of the binary search range
            long long result = 1; // Variable to store the result
            
            while(i <= j)
            {
                long long mid = i + (j - i) / 2; // Calculate the middle point
                
                // Check if the sum of the first 'mid' rows exceeds 'n'
                if((mid * (mid + 1) / 2) > n)
                {
                    j = mid - 1; // Move the search range to the left
                }
                else
                {
                    result = mid; // Update the result
                    i = mid + 1; // Move the search range to the right
                }
            }
            return result;
        }
};
```

---

## Explanation of the Code

1. **Initialization**:
   - `i` is the start of the binary search range (1).
   - `j` is the end of the binary search range (`n`).
   - `result` is used to store the maximum number of complete rows.

2. **Binary Search**:
   - Calculate the middle point `mid` using `i + (j - i) / 2` to avoid overflow.
   - Compute the sum of the first `mid` rows using the formula `mid * (mid + 1) / 2`.
   - If the sum exceeds `n`, move the search range to the left (`j = mid - 1`).
   - Otherwise, update `result` to `mid` and move the search range to the right (`i = mid + 1`).

3. **Return the Result**:
   - After the binary search completes, `result` contains the maximum number of complete rows.

---

## Complexity Analysis

1. **Time Complexity**: `O(log n)`
   - The binary search reduces the search space by half in each iteration.

2. **Space Complexity**: `O(1)`
   - The solution uses a constant amount of extra space.

---

## Example Walkthrough

### Input: `n = 8`

1. Initial range: `i = 1`, `j = 8`, `result = 1`.
2. First iteration:
   - `mid = 4`, `sum = 4 * (4 + 1) / 2 = 10`.
   - `10 > 8`, so update `j = 3`.
3. Second iteration:
   - `mid = 2`, `sum = 2 * (2 + 1) / 2 = 3`.
   - `3 <= 8`, so update `result = 2`, `i = 3`.
4. Third iteration:
   - `mid = 3`, `sum = 3 * (3 + 1) / 2 = 6`.
   - `6 <= 8`, so update `result = 3`, `i = 4`.
5. Exit loop as `i > j`.

Output: `3`.

---

## Applications

- This problem demonstrates the use of **Binary Search** for solving mathematical problems efficiently.
- It can be extended to other problems involving quadratic growth or similar constraints.

---

## References

- [Leetcode Problem 441](https://leetcode.com/problems/arranging-coins/)
