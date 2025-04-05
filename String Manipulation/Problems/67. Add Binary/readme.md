# 67. Add Binary

This folder contains the solution to the Leetcode problem **67. Add Binary** implemented in C++.

## Problem Description

Given two binary strings `a` and `b`, return their sum as a binary string.

### Example 1

```
Input: a = "11", b = "1"
Output: "100"
```

### Example 2

```
Input: a = "1010", b = "1011"
Output: "10101"
```

### Constraints

- `1 <= a.length, b.length <= 10^4`
- `a` and `b` consist only of `'0'` or `'1'`.
- Each string does not contain leading zeros except for the string `"0"`.

---

## Approach

The problem can be solved using multiple approaches:

---

### Approach 1: Converting Binary Strings to Integers

#### Explanation

This approach involves converting the binary strings to integers, performing the addition, and then converting the result back to a binary string.

1. **Binary to Integer Conversion**:
   - Traverse the binary string and calculate the integer value using the formula:
     ```
     result = (result * 2) + (current_bit)
     ```

2. **Integer to Binary Conversion**:
   - Use modulo and division to extract binary digits from the integer:
     ```
     result = (num % 2) + result
     ```

3. **Addition**:
   - Add the two integers and convert the result back to a binary string.

#### Implementation

```cpp
// filepath: /Users/rahulrathod/Personal Work/Leetcode-Problems/String Manipulation/Problems/67. Add Binary/solution_approach1.cpp
class Solution {
public:
    int binaryToInt(string binaryNum)
    {
        long long result = 0;
        for(auto ch : binaryNum)
            result = (result * 2) + (ch - '0');
        return result;
    }

    string intToBinaryString(int num)
    {
        string result = "";

        while(num)
        {
            result = to_string(num % 2) + result;
            num = num / 2;
        }
        return result == "" ? "0" : result;
    }

    string addBinary(string a, string b) 
    {
        int sum = binaryToInt(a) + binaryToInt(b);
        return intToBinaryString(sum);
    }
};
```

#### Example Walkthrough

##### Input: `a = "11"`, `b = "1"`

1. Convert `a` to integer: `binaryToInt("11") = 3`.
2. Convert `b` to integer: `binaryToInt("1") = 1`.
3. Add the integers: `3 + 1 = 4`.
4. Convert the result back to binary: `intToBinaryString(4) = "100"`.

Output: `"100"`.

#### Complexity Analysis

1. **Time Complexity**: `O(n + m)`
   - `n` is the length of `a`, and `m` is the length of `b`.
   - Conversion from binary to integer and vice versa takes linear time.

2. **Space Complexity**: `O(max(n, m))`
   - The result string requires space proportional to the length of the longer string.

---

### Approach 2: Direct Binary Addition with String Modification

#### Explanation

To handle large inputs, the addition is performed directly on the binary strings without converting them to integers. This approach uses bitwise operations and a carry to compute the sum.

1. **Padding**:
   - Pad the shorter string with leading zeros to make both strings of equal length.

2. **Bitwise Addition**:
   - Traverse the strings from the least significant bit to the most significant bit.
   - Use XOR (`^`) for addition and AND (`&`) for carry.

3. **Carry Handling**:
   - If there is a carry left after processing all bits, append it to the result.

#### Implementation

```cpp
// filepath: /Users/rahulrathod/Personal Work/Leetcode-Problems/String Manipulation/Problems/67. Add Binary/solution_approach2.cpp
class Solution {
public:
    string addBinary(string a, string b) 
    {
        string result = "";
        bool sum = 0;
        bool carry = 0;

        // Pad the shorter string with leading zeros
        if(a.length() > b.length())
        {
            b = string(a.length() - b.length(), '0') + b;
        }
        else
        {
            a = string(b.length() - a.length(), '0') + a;
        }

        // Perform addition from the least significant bit to the most significant bit
        while(a.length() > 0)
        {
            bool x = (a[a.length() - 1] == '1');
            bool y = (b[b.length() - 1] == '1');

            if(carry == 0)
            {
                sum = x ^ y;
                carry = x & y;
            }
            else
            {
                sum = !(x ^ y);
                carry = x | y;
            }

            result = to_string(sum) + result;

            a.pop_back();
            b.pop_back();
        }

        // If there is a carry left, add it to the result
        if(carry)
            result = to_string(carry) + result;

        return result;
    }
};
```

#### Example Walkthrough

##### Input: `a = "1010"`, `b = "1011"`

1. Pad the strings: `a = "1010"`, `b = "1011"`.
2. Traverse from the end:
   - Add `0 + 1 + carry(0) = 1`, result = `"1"`, carry = `0`.
   - Add `1 + 1 + carry(0) = 0`, result = `"01"`, carry = `1`.
   - Add `0 + 0 + carry(1) = 1`, result = `"101"`, carry = `0`.
   - Add `1 + 1 + carry(0) = 0`, result = `"0101"`, carry = `1`.
3. Append carry: result = `"10101"`.

Output: `"10101"`.

#### Complexity Analysis

1. **Time Complexity**: `O(max(n, m))`
   - Traverses both strings once.

2. **Space Complexity**: `O(max(n, m))`
   - The result string requires space proportional to the length of the longer string.

---

## Applications

1. **Binary Arithmetic**:
   - Adding binary numbers is a fundamental operation in computer science and digital systems.

2. **Low-Level Programming**:
   - Binary addition is used in low-level programming and hardware design.

3. **Data Encoding**:
   - Binary operations are used in data encoding and error detection.

---

## References

- [Leetcode Problem 67](https://leetcode.com/problems/add-binary/)
