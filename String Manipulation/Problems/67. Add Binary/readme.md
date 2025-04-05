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

The problem can be solved using multiple approaches. Below are the detailed explanations and implementations.

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
    // Convert a binary string to an integer
    int binaryToInt(string binaryNum)
    {
        long long result = 0;
        for(auto ch : binaryNum) // Traverse each character in the binary string
            result = (result * 2) + (ch - '0'); // Update result by shifting left and adding the current bit
        return result;
    }

    // Convert an integer to a binary string
    string intToBinaryString(int num)
    {
        string result = "";

        while(num) // Extract binary digits using modulo and division
        {
            result = to_string(num % 2) + result; // Append the least significant bit to the result
            num = num / 2; // Divide the number by 2
        }
        return result == "" ? "0" : result; // Return "0" if the result is empty
    }

    // Add two binary strings
    string addBinary(string a, string b) 
    {
        int sum = binaryToInt(a) + binaryToInt(b); // Convert both strings to integers, add them
        return intToBinaryString(sum); // Convert the sum back to a binary string
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

#### Issue

This approach fails for large inputs due to the constraints of integer data types. For example, given the inputs:

```
a = "10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101"
b = "110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011"
```

The binary strings exceed the range of standard integer types like `int` or `long long`, causing overflow and incorrect results.

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
   - Use the following rules for addition:
     - If `carry == 0`:
       - Compute the sum as `XOR (^)` of the two bits.
       - Compute the updated carry as `AND (&)` of the two bits.
     - If `carry == 1`:
       - Compute the sum as `XNOR (~(XOR))` of the two bits.
       - Compute the updated carry as `OR (|)` of the two bits.

3. **Carry Handling**:
   - If there is a carry left after processing all bits, append it to the result.

#### Implementation

```cpp
// filepath: /Users/rahulrathod/Personal Work/Leetcode-Problems/String Manipulation/Problems/67. Add Binary/solution_approach2.cpp
class Solution {
public:
    string addBinary(string a, string b) 
    {
        string result = ""; // Initialize the result string
        bool sum = 0; // Variable to store the sum of current bits
        bool carry = 0; // Variable to store the carry

        // Pad the shorter string with leading zeros
        if(a.length() > b.length())
        {
            b = string(a.length() - b.length(), '0') + b; // Add leading zeros to b
        }
        else
        {
            a = string(b.length() - a.length(), '0') + a; // Add leading zeros to a
        }

        // Perform addition from the least significant bit to the most significant bit
        while(a.length() > 0)
        {
            bool x = (a[a.length() - 1] == '1'); // Get the last bit of a
            bool y = (b[b.length() - 1] == '1'); // Get the last bit of b

            if(carry == 0)
            {
                sum = x ^ y; // XOR for sum when carry is 0
                carry = x & y; // AND for carry when carry is 0
            }
            else
            {
                sum = !(x ^ y); // XNOR for sum when carry is 1
                carry = x | y; // OR for carry when carry is 1
            }

            result = to_string(sum) + result; // Append the sum to the result

            a.pop_back(); // Remove the last bit of a
            b.pop_back(); // Remove the last bit of b
        }

        // If there is a carry left, add it to the result
        if(carry)
            result = to_string(carry) + result;

        return result; // Return the final binary sum
    }
};
```

#### Example Walkthrough

##### Input: `a = "1010"`, `b = "1011"`

1. Pad the strings: `a = "1010"`, `b = "1011"`.
2. Traverse from the end:
   - Add `0 + 1 + carry(0)`: `sum = 0 ^ 1 = 1`, `carry = 0 & 1 = 0`, result = `"1"`.
   - Add `1 + 1 + carry(0)`: `sum = 1 ^ 1 = 0`, `carry = 1 & 1 = 1`, result = `"01"`.
   - Add `0 + 0 + carry(1)`: `sum = !(0 ^ 0) = 1`, `carry = 0 | 0 = 0`, result = `"101"`.
   - Add `1 + 1 + carry(0)`: `sum = 1 ^ 1 = 0`, `carry = 1 & 1 = 1`, result = `"0101"`.
3. Append carry: result = `"10101"`.

Output: `"10101"`.

#### Complexity Analysis

1. **Time Complexity**: `O(max(n, m))`
   - Traverses both strings once.

2. **Space Complexity**: `O(max(n, m))`
   - The result string requires space proportional to the length of the longer string.

---

### Approach 3: Optimized Binary Addition Using Indices

#### Explanation

This is the most optimized approach. Instead of modifying the strings, we use indices to traverse the strings from the end to the beginning. This avoids the overhead of string operations like `pop_back()`.

1. **Initialization**:
   - Use two pointers `i` and `j` to traverse the strings `a` and `b` from the end.
   - Use a `carry` variable to keep track of the carry from the previous addition.

2. **Binary Addition**:
   - Add the current bits of `a` and `b` (if they exist) along with the carry.
   - Append the least significant bit of the sum (`sum % 2`) to the result.
   - Update the carry as the most significant bit of the sum (`sum / 2`).

3. **Handle Remaining Carry**:
   - If there is a carry left after processing all bits, append it to the result.

4. **Reverse the Result**:
   - Since the result is built in reverse order, reverse it before returning.

#### Implementation

```cpp
// filepath: /Users/rahulrathod/Personal Work/Leetcode-Problems/String Manipulation/Problems/67. Add Binary/solution_approach3.cpp
class Solution {
public:
    string addBinary(string a, string b) 
    {
        string result = ""; // Initialize the result string
        int i = a.length() - 1; // Pointer for the last bit of a
        int j = b.length() - 1; // Pointer for the last bit of b
        int carry = 0; // Variable to store the carry

        // Traverse both strings from the end
        while(i >= 0 || j >= 0 || carry)
        {
            int sum = carry; // Start with the carry from the previous step

            if(i >= 0)
                sum += a[i--] - '0'; // Add the current bit of a to sum and move the pointer

            if(j >= 0)
                sum += b[j--] - '0'; // Add the current bit of b to sum and move the pointer

            result = to_string(sum % 2) + result; // Append the least significant bit of sum to the result
            carry = sum / 2; // Update the carry
        }

        return result; // Return the final binary sum
    }
};
```

#### Example Walkthrough

##### Input: `a = "1010"`, `b = "1011"`

1. Initialize `i = 3`, `j = 3`, `carry = 0`, `result = ""`.
2. First iteration:
   - `sum = 0 + 0 + 1 = 1`, `result = "1"`, `carry = 0`.
3. Second iteration:
   - `sum = 1 + 1 + 0 = 2`, `result = "01"`, `carry = 1`.
4. Third iteration:
   - `sum = 0 + 0 + 1 = 1`, `result = "101"`, `carry = 0`.
5. Fourth iteration:
   - `sum = 1 + 1 + 0 = 2`, `result = "0101"`, `carry = 1`.
6. Final carry:
   - `result = "10101"`.

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
