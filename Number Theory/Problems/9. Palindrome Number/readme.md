# 9. Palindrome Number

This folder contains the solution to the Leetcode problem **9. Palindrome Number** implemented in C++.

## Problem Description

Given an integer `x`, return `true` if `x` is a palindrome, and `false` otherwise.

An integer is a palindrome when it reads the same backward as forward. For example, `121` is a palindrome while `123` is not.

### Example 1

```
Input: x = 121
Output: true
```

### Example 2

```
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore, it is not a palindrome.
```

### Example 3

```
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore, it is not a palindrome.
```

### Constraints

- `-2^31 <= x <= 2^31 - 1`

---

## Approach

The problem can be solved using multiple approaches. Below are the detailed explanations and implementations.

---

### Approach 1: Convert Integer to String

#### Explanation

1. **Convert Integer to String**:
   - Convert the integer `x` to a string representation using `to_string(x)`.

2. **Two-Pointer Comparison**:
   - Use two pointers:
     - `i` starts at the beginning of the string.
     - `j` starts at the end of the string.
   - Compare the characters at `i` and `j`:
     - If they are equal, move `i` forward and `j` backward.
     - If they are not equal, return `false`.

3. **Palindrome Check**:
   - If all characters match, the number is a palindrome.

#### Implementation

```cpp
class Solution {
public:
    bool isPalindrome(int x) 
    {
        string s = to_string(x); // Convert integer to string
        int i = 0;
        int j = s.length() - 1;

        while(i < j) // Compare characters from both ends
        {
            if(s[i++] != s[j--]) // If characters don't match, return false
                return false;
        }
        return true; // If all characters match, return true
    }
};
```

#### Example Walkthrough

**Input**: `x = 121`

1. Convert `x` to string: `"121"`.
2. Compare characters:
   - `'1' == '1'`
   - `'2' == '2'`
3. All characters match, so the output is `true`.

#### Complexity Analysis

1. **Time Complexity**: `O(n)`
   - Converting the integer to a string takes `O(n)` time, where `n` is the number of digits in `x`.
   - Comparing characters using two pointers also takes `O(n)` time.

2. **Space Complexity**: `O(n)`
   - The string representation of the number requires `O(n)` space.

---

### Approach 2: Reverse the Number

#### Explanation

1. **Negative Numbers**:
   - If `x` is negative, it cannot be a palindrome because the negative sign will not match when reversed.

2. **Reverse the Digits**:
   - Extract the digits of `x` one by one and construct the reversed number:
     - Use `x % 10` to get the last digit.
     - Use `x / 10` to remove the last digit.
     - Multiply the reversed number by `10` and add the extracted digit.

3. **Compare Original and Reversed Numbers**:
   - If the reversed number equals the original number, `x` is a palindrome.

#### Implementation

```cpp
class Solution {
public:
    bool isPalindrome(int x) 
    {
        if(x < 0) // Negative numbers cannot be palindromes
            return false;

        long long rev = 0; // Variable to store the reversed number
        long long original = x; // Store the original number

        while(x) // Reverse the digits of the number
        {
            rev = (rev * 10) + (x % 10);
            x = x / 10;
        }

        return rev == original; // Check if the reversed number equals the original
    }
};
```

#### Example Walkthrough

**Input**: `x = 121`

1. Reverse `x`:
   - Start with `rev = 0`.
   - Extract digits and reverse:
     - `rev = 1`, `x = 12`
     - `rev = 12`, `x = 1`
     - `rev = 121`, `x = 0`
2. Compare reversed number with original: `121 == 121`.
3. Output is `true`.

#### Complexity Analysis

1. **Time Complexity**: `O(n)`
   - Reversing the digits of the number takes `O(n)` time, where `n` is the number of digits in `x`.

2. **Space Complexity**: `O(1)`
   - The solution uses a constant amount of extra space.

---

### Approach 3: Optimized Reverse Half of the Number

#### Explanation

1. **Negative Numbers and Trailing Zeros**:
   - If `x` is negative or ends with `0` (but is not `0` itself), it cannot be a palindrome.

2. **Reverse Half of the Digits**:
   - Instead of reversing the entire number, reverse only half of the digits:
     - Use `x % 10` to extract the last digit.
     - Use `x / 10` to remove the last digit.
     - Multiply the reversed half by `10` and add the extracted digit.

3. **Compare Halves**:
   - Stop reversing when the reversed half is greater than or equal to the remaining half.
   - Compare the reversed half with the remaining half:
     - If they are equal, `x` is a palindrome.
     - If the reversed half divided by `10` equals the remaining half, `x` is also a palindrome (handles odd-length numbers).

#### Implementation

```cpp
class Solution {
public:
    bool isPalindrome(int x) 
    {
        if(x < 0 || (x % 10 == 0 && x != 0)) // Negative numbers and numbers ending with 0 are not palindromes
            return false;

        int rev = 0; // Variable to store the reversed half of the number

        while(x > rev) // Reverse only half of the digits
        {
            rev = (rev * 10) + (x % 10);
            x = x / 10;
        }

        // Check if the reversed half equals the remaining half
        return x == rev || x == rev / 10;
    }
};
```

#### Example Walkthrough

**Input**: `x = 121`

1. Reverse half of `x`:
   - Start with `rev = 0`.
   - Extract digits and reverse:
     - `rev = 1`, `x = 12`
     - `rev = 12`, `x = 1`
2. Compare reversed half with remaining half:
   - `x == rev` or `x == rev / 10` → `1 == 1`.
3. Output is `true`.

#### Complexity Analysis

1. **Time Complexity**: `O(n)`
   - Reversing half of the digits takes `O(n)` time, where `n` is the number of digits in `x`.

2. **Space Complexity**: `O(1)`
   - The solution uses a constant amount of extra space.

---

## Applications

1. **Number Theory**:
   - Palindrome numbers are used in mathematical problems and puzzles.

2. **Data Validation**:
   - Palindrome checks are used in data validation and error detection.

3. **String Manipulation**:
   - Demonstrates techniques for working with strings and numbers.

---

## References

- [Leetcode Problem 9](https://leetcode.com/problems/palindrome-number/)
