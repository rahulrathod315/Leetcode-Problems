# 66. Plus One

This folder contains the solution to the Leetcode problem **66. Plus One** implemented in C++.

---

## Problem Description

You are given a **large integer** represented as an integer array `digits`, where each `digits[i]` is the `i-th` digit of the integer. The digits are stored such that the most significant digit is at the head of the array, and each element in the array contains a single digit.

You need to increment the large integer by one and return the resulting array of digits.

### Example 1

```
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123. Incrementing by one gives 124.
```

### Example 2

```
Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321. Incrementing by one gives 4322.
```

### Example 3

```
Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9. Incrementing by one gives 10.
```

### Constraints

- `1 <= digits.length <= 100`
- `0 <= digits[i] <= 9`
- `digits` does not contain any leading zeros except for the number `0` itself.

---

## Basic Concepts

### Carry Propagation

When incrementing a number, if the last digit becomes `10`, it results in a carry that propagates to the next digit. For example:
- Incrementing `129` results in `130` because the carry propagates from the last digit to the second-to-last digit.

### Array Representation of Numbers

The problem involves manipulating numbers represented as arrays. Each digit is stored in a separate index, and operations like addition and carry propagation must be performed manually.

---

## Approach 1: Iterative Carry Propagation

### Explanation

This approach iterates through the array from the least significant digit (rightmost) to the most significant digit (leftmost). It adds `1` to the last digit and propagates the carry if necessary.

1. Start with a carry of `1` (to represent the increment).
2. Traverse the array from right to left:
   - Add the carry to the current digit.
   - If the result is `10`, set the current digit to `0` and propagate the carry.
   - If the result is less than `10`, set the carry to `0` and stop further propagation.
3. If there is still a carry after processing all digits, insert `1` at the beginning of the array.

---

### Implementation

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int carry = 1; // Initialize carry as 1 (for the increment)

        // Traverse the array from the last digit to the first
        for(int i = digits.size() - 1; i >= 0; i--)
        {
            digits[i] += carry; // Add the carry to the current digit
            if(digits[i] != 10) // If no carry is generated, stop
            {
                carry = 0;
                break;
            }
            digits[i] = 0; // If carry is generated, set the current digit to 0
        }

        // If there is still a carry, insert 1 at the beginning
        if(carry)
            digits.insert(digits.begin(), carry);
        
        return digits; // Return the updated array
    }
};
```

---

### Example Walkthrough

#### Input: `digits = [9, 9, 9]`

1. **Initialization**:
   - `carry = 1`.

2. **First Iteration**:
   - Add `carry` to `digits[2]`: `digits[2] = 9 + 1 = 10`.
   - Set `digits[2] = 0` and propagate the carry.

3. **Second Iteration**:
   - Add `carry` to `digits[1]`: `digits[1] = 9 + 1 = 10`.
   - Set `digits[1] = 0` and propagate the carry.

4. **Third Iteration**:
   - Add `carry` to `digits[0]`: `digits[0] = 9 + 1 = 10`.
   - Set `digits[0] = 0` and propagate the carry.

5. **Final Step**:
   - Insert `1` at the beginning: `digits = [1, 0, 0, 0]`.

**Output**: `[1, 0, 0, 0]`

---

### Complexity Analysis

1. **Time Complexity**: `O(n)`
   - The array is traversed once from right to left.

2. **Space Complexity**: `O(1)`
   - The solution modifies the input array in place and uses constant extra space.

---

## Approach 2: Optimized Approach Using Reverse Traversal

### Explanation

This approach is similar to Approach 1 but avoids unnecessary operations by stopping as soon as the carry becomes `0`. It directly modifies the array in place.

1. Start with a carry of `1`.
2. Traverse the array from right to left:
   - Add the carry to the current digit.
   - If the result is less than `10`, set the carry to `0` and stop further processing.
   - Otherwise, set the current digit to `0` and continue.
3. If there is still a carry after processing all digits, insert `1` at the beginning.

---

### Implementation

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int carry = 1; // Initialize carry as 1 (for the increment)

        // Traverse the array from the last digit to the first
        for(int i = digits.size() - 1; i >= 0; i--)
        {
            digits[i] += carry; // Add the carry to the current digit
            carry = digits[i] / 10; // Update carry
            digits[i] %= 10; // Update the current digit

            if(carry == 0) // If no carry is left, stop
                break;
        }

        // If there is still a carry, insert 1 at the beginning
        if(carry)
            digits.insert(digits.begin(), 1);
        
        return digits; // Return the updated array
    }
};
```

---

### Example Walkthrough

#### Input: `digits = [4, 3, 2, 9]`

1. **Initialization**:
   - `carry = 1`.

2. **First Iteration**:
   - Add `carry` to `digits[3]`: `digits[3] = 9 + 1 = 10`.
   - Set `digits[3] = 0` and propagate the carry.

3. **Second Iteration**:
   - Add `carry` to `digits[2]`: `digits[2] = 2 + 1 = 3`.
   - Set `carry = 0` and stop further processing.

4. **Final Step**:
   - No carry remains, so the array is unchanged.

**Output**: `[4, 3, 3, 0]`

---

### Complexity Analysis

1. **Time Complexity**: `O(n)`
   - The array is traversed once from right to left.

2. **Space Complexity**: `O(1)`
   - The solution modifies the input array in place and uses constant extra space.

---

## Applications

1. **Number Representation**:
   - This problem demonstrates how to manipulate numbers represented as arrays.

2. **Carry Propagation**:
   - The concept of carry propagation is fundamental in addition and subtraction operations.

3. **Array Manipulation**:
   - Useful for problems involving digit-wise operations on numbers.

---

## References

- [Leetcode Problem 66](https://leetcode.com/problems/plus-one/)
