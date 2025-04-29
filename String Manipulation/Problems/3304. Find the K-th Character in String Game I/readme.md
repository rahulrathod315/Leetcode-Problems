# 3304. Find the K-th Character in String Game I

This folder contains the solution to the Leetcode problem **3304. Find the K-th Character in String Game I** implemented in C++.

---

## Problem Description

Alice and Bob are playing a game. Initially, Alice has a string `word = "a"`.

You are given a positive integer `k`.

Now Bob will ask Alice to perform the following operation forever:

1. Generate a new string by changing each character in `word` to its next character in the English alphabet.
2. Append the newly generated string to the original `word`.

For example:
- Performing the operation on `"c"` generates `"cd"`.
- Performing the operation on `"zb"` generates `"zbac"`.

Return the value of the `k`-th character in `word`, after enough operations have been done for `word` to have at least `k` characters.

Note that the character `'z'` can be changed to `'a'` in the operation.

---

## Basic Concepts

### String Transformation
The problem involves transforming a string by replacing each character with the next character in the alphabet. This transformation is cyclic, meaning `'z'` wraps around to `'a'`.

### Recursive and Iterative Approaches
The solution can be approached recursively or iteratively by simulating the string generation process until the string length is sufficient to contain the `k`-th character.

---

## Approach 1: Recursive String Generation

### Explanation

This approach recursively generates the string until its length is greater than or equal to `k`. At each step:
1. Generate the next string by replacing each character in the current string with the next character in the alphabet.
2. Append the newly generated string to the current string.
3. If the length of the string is greater than or equal to `k`, return the `k`-th character.

---

### Implementation

```cpp
class Solution {
public:
    // Function to generate the next string by replacing each character
    string findWord(string s)
    {
        string result = "";
        for(auto ch : s)
        {
            if(ch != 'z') // If character is not 'z', increment it
                result += string(1, ch + 1);
            else // If character is 'z', wrap around to 'a'
                result += string(1, 'a');
        }
        return result;
    }

    // Recursive function to find the K-th character
    char findkthCharacter(string s, int k)
    {
        if(s.length() >= k) // If the string length is sufficient, return the K-th character
            return s[k - 1];
        return findkthCharacter(s + findWord(s), k); // Recursively generate the string
    }

    // Wrapper function to start with the initial string "a"
    char kthCharacter(int k) 
    {
        return findkthCharacter("a", k);
    }
};
```

---

### Example Walkthrough

#### Input: `k = 5`

1. Start with the initial string: `"a"`.
2. Generate the next string: `"b"`.
   - Combined string: `"ab"`.
3. Generate the next string: `"bc"`.
   - Combined string: `"abbc"`.
4. Generate the next string: `"cd"`.
   - Combined string: `"abbccd"`.
5. The 5th character is `'c'`.

**Output**: `'c'`

---

### Complexity Analysis

1. **Time Complexity**: `O(k^2)`
   - At each step, the string length approximately doubles, and generating the next string takes linear time relative to the current string length.

2. **Space Complexity**: `O(k)`
   - The recursion stack and the generated string require space proportional to `k`.

---

## Approach 2: Optimized Iterative Approach

### Explanation

Instead of generating the entire string recursively, this approach calculates the `k`-th character directly by simulating the process iteratively. The key observation is that the string grows exponentially, so we can determine which "generation" contains the `k`-th character and simulate only the necessary transformations.

---

### Implementation

```cpp
class Solution {
public:
    // Function to find the K-th character iteratively
    char kthCharacter(int k) 
    {
        string current = "a"; // Start with the initial string
        while(current.length() < k) // Generate until the string length is sufficient
        {
            string next = "";
            for(auto ch : current)
            {
                if(ch != 'z') // If character is not 'z', increment it
                    next += string(1, ch + 1);
                else // If character is 'z', wrap around to 'a'
                    next += string(1, 'a');
            }
            current += next; // Append the next string to the current string
        }
        return current[k - 1]; // Return the K-th character
    }
};
```

---

### Example Walkthrough

#### Input: `k = 5`

1. Start with the initial string: `"a"`.
2. Generate the next string: `"b"`.
   - Combined string: `"ab"`.
3. Generate the next string: `"bc"`.
   - Combined string: `"abbc"`.
4. Generate the next string: `"cd"`.
   - Combined string: `"abbccd"`.
5. The 5th character is `'c'`.

**Output**: `'c'`

---

### Complexity Analysis

1. **Time Complexity**: `O(k)`
   - Each character is processed once until the `k`-th character is found.

2. **Space Complexity**: `O(k)`
   - The generated string requires space proportional to `k`.

---

## Applications

1. **String Manipulation**:
   - This problem demonstrates how to manipulate strings using transformations and recursion.

2. **Recursive Algorithms**:
   - The recursive approach highlights the use of recursion to solve problems involving repeated transformations.

3. **Optimization**:
   - The iterative approach shows how to optimize recursive solutions by reducing unnecessary computations.

---

## References

- [Leetcode Problem 3304](https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/)
