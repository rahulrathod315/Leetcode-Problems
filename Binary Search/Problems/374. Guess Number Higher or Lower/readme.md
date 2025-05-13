# 374. Guess Number Higher or Lower

This folder contains the solution to the Leetcode problem **374. Guess Number Higher or Lower** implemented in C++.

## Problem Description

We are playing the Guess Game. The game is as follows:

I pick a number from `1` to `n`. You have to guess which number I picked.

Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.

You call a pre-defined API `int guess(int num)`, which returns three possible results:

- `-1`: My number is lower.
- `1`: My number is higher.
- `0`: Congrats! You got it!

Return the number that I picked.

### Example 1

```
Input: n = 10, pick = 6
Output: 6
```

### Example 2

```
Input: n = 1, pick = 1
Output: 1
```

### Constraints

- `1 <= n <= 2^31 - 1`
- `1 <= pick <= n`

---

## Basic Concept

The problem can be solved using **Binary Search**. The idea is to minimize the number of calls to the `guess` API by dividing the search space in half during each iteration.

Key concepts:
1. **Binary Search**:
   - Efficiently narrows down the search space by comparing the middle element with the target condition.

2. **API Calls**:
   - The `guess` API is used to determine whether the guessed number is correct, too high, or too low.

---

## Approach 1: Binary Search

### Concept

The idea is to use binary search to minimize the number of API calls. We start with the entire range `[1, n]` and repeatedly divide the range into two halves. At each step, we:

1. Calculate the middle number `mid`.
2. Call the `guess` API with `mid`.
3. If the result is `0`, return `mid` as the correct number.
4. If the result is `-1`, narrow the search range to the left half by updating `end = mid - 1`.
5. If the result is `1`, narrow the search range to the right half by updating `start = mid + 1`.

This process continues until the correct number is found.

### Code

```cpp
class Solution {
public:
    int guessNumber(int n) 
    {
        int start = 1;
        int end = n;

        while(start <= end)
        {
            int mid = start + (end - start) / 2; // Calculate the middle index

            int res = guess(mid); // Call the guess API

            if(res == 0) // Correct guess
                return mid;
            else if(res == -1) // Target is lower
                end = mid - 1;
            else // Target is higher
                start = mid + 1;
        }
        return -1; // This line should never be reached
    }
};
```

### Example Walkthrough

#### Input: `n = 10, pick = 6`

1. Initial range: `start = 1`, `end = 10`.
2. First iteration:
   - `mid = 5`, `guess(5) = 1`.
   - Update `start = 6`.
3. Second iteration:
   - `mid = 8`, `guess(8) = -1`.
   - Update `end = 7`.
4. Third iteration:
   - `mid = 6`, `guess(6) = 0`.
   - Return `6`.

Output: `6`.

### Complexity Analysis

1. **Time Complexity**: `O(log n)`
   - The binary search reduces the search space by half in each iteration.

2. **Space Complexity**: `O(1)`
   - The solution uses a constant amount of extra space.

---

## Optimized Approach: Binary Search with Minimal Variables

### Concept

This approach is similar to the first one but uses fewer variables and simplifies the logic. Instead of maintaining separate `start` and `end` variables, we directly adjust the range based on the result of the `guess` API.

### Code

```cpp
class Solution {
public:
    int guessNumber(int n) 
    {
        int low = 1, high = n;
        while (low < high) {
            int mid = low + (high - low) / 2; // Calculate the middle index
            if (guess(mid) <= 0) // Target is lower or correct
                high = mid;
            else // Target is higher
                low = mid + 1;
        }
        return low; // The correct number
    }
};
```

### Example Walkthrough

#### Input: `n = 10, pick = 6`

1. Initial range: `low = 1`, `high = 10`.
2. First iteration:
   - `mid = 5`, `guess(5) = 1`.
   - Update `low = 6`.
3. Second iteration:
   - `mid = 8`, `guess(8) = -1`.
   - Update `high = 8`.
4. Third iteration:
   - `mid = 6`, `guess(6) = 0`.
   - Update `high = 6`.
5. Exit loop as `low == high`.

Output: `6`.

### Complexity Analysis

1. **Time Complexity**: `O(log n)`
   - The binary search reduces the search space by half in each iteration.

2. **Space Complexity**: `O(1)`
   - The solution uses a constant amount of extra space.

---

## References

- [Leetcode Problem 374](https://leetcode.com/problems/guess-number-higher-or-lower/)