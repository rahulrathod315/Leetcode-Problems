# 997. Find the Town Judge

This folder contains the solution to the Leetcode problem **997. Find the Town Judge** implemented in C++.

## Problem Description

In a town, there are `n` people labeled from `1` to `n`. There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

1. The town judge trusts nobody.
2. Everybody (except for the town judge) trusts the town judge.
3. There is exactly one person that satisfies properties 1 and 2.

You are given an array `trust` where `trust[i] = [a, b]` represents that the person labeled `a` trusts the person labeled `b`.

Return the label of the town judge if the town judge exists and can be identified. Otherwise, return `-1`.

### Example 1

```
Input: n = 2, trust = [[1,2]]
Output: 2
```

### Example 2

```
Input: n = 3, trust = [[1,3],[2,3]]
Output: 3
```

### Example 3

```
Input: n = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1
```

### Constraints

- `1 <= n <= 1000`
- `0 <= trust.length <= 10^4`
- `trust[i].length == 2`
- All the pairs of `trust` are unique.
- `a != b`
- `1 <= a, b <= n`

---

## Basic Concept

The problem involves identifying a special node (the town judge) in a directed graph. The town judge satisfies specific conditions based on trust relationships.

Key concepts:
1. **Graph Representation**:
   - The trust relationships can be represented as a directed graph where an edge from `a` to `b` indicates that `a` trusts `b`.

2. **Indegree and Outdegree**:
   - The town judge has an indegree of `n-1` (trusted by everyone except themselves) and an outdegree of `0` (trusts nobody).

3. **Efficient Identification**:
   - By tracking the indegree and outdegree of each node, the town judge can be identified in linear time.

4. **Applications**:
   - Used in social network analysis, reputation systems, and graph theory problems.

---

## Approach

The problem can be solved using an **indegree-outdegree counting** approach. The idea is to track how many people each person trusts and how many people trust them.

### Key Observations

1. The town judge trusts nobody:
   - This means the **outdegree** (number of people they trust) of the town judge is `0`.

2. Everybody (except the town judge) trusts the town judge:
   - This means the **indegree** (number of people who trust them) of the town judge is `n-1`.

3. Using the above properties, we can identify the town judge by:
   - Checking if a person has an outdegree of `0` and an indegree of `n-1`.

---

## Implementation

Here is the implementation of the solution in C++:

```cpp
#include <vector>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        vector<int> trusts(n+1, 0); // Tracks how many people each person trusts
        vector<int> trustedBy(n+1, 0); // Tracks how many people trust each person

        for(auto &t : trust)
        {
            trusts[t[0]]++; // Increment the outdegree for the person who trusts
            trustedBy[t[1]]++; // Increment the indegree for the person being trusted
        }

        for(int i = 1; i <= n; i++)
        {
            // Check if the person satisfies the town judge conditions
            if(trusts[i] == 0 && trustedBy[i] == n-1)
                return i;
        }
        return -1; // No town judge found
    }
};
```

---

## Explanation of the Code

1. **Initialization**:
   - Create two vectors `trusts` and `trustedBy` of size `n+1` to track the outdegree and indegree of each person.

2. **Processing the Trust Array**:
   - For each pair `[a, b]` in `trust`:
     - Increment `trusts[a]` because person `a` trusts someone.
     - Increment `trustedBy[b]` because person `b` is trusted by someone.

3. **Finding the Town Judge**:
   - Iterate through all people from `1` to `n`.
   - Check if a person has `trusts[i] == 0` (trusts nobody) and `trustedBy[i] == n-1` (trusted by everyone else).
   - If such a person exists, return their label.

4. **Return Result**:
   - If no person satisfies the conditions, return `-1`.

---

## Complexity Analysis

1. **Time Complexity**: `O(n + m)`
   - `n` is the number of people, and `m` is the size of the `trust` array.
   - Processing the `trust` array takes `O(m)`, and checking all `n` people takes `O(n)`.

2. **Space Complexity**: `O(n)`
   - Two vectors of size `n+1` are used to store the outdegree and indegree of each person.

---

## Example Walkthrough

### Input: `n = 3, trust = [[1,3],[2,3]]`

1. Initialize `trusts = [0,0,0,0]` and `trustedBy = [0,0,0,0]`.
2. Process the `trust` array:
   - For `[1,3]`: `trusts[1]++` → `trusts = [0,1,0,0]`, `trustedBy[3]++` → `trustedBy = [0,0,0,1]`.
   - For `[2,3]`: `trusts[2]++` → `trusts = [0,1,1,0]`, `trustedBy[3]++` → `trustedBy = [0,0,0,2]`.
3. Check each person:
   - Person `1`: `trusts[1] = 1`, `trustedBy[1] = 0` → Not the judge.
   - Person `2`: `trusts[2] = 1`, `trustedBy[2] = 0` → Not the judge.
   - Person `3`: `trusts[3] = 0`, `trustedBy[3] = 2` → Judge found.
4. Output: `3`.

---

## Applications

1. **Social Network Analysis**:
   - Identifying influential individuals or leaders in a network.

2. **Graph Theory**:
   - Problems involving directed graphs and indegree-outdegree relationships.

3. **Trust and Reputation Systems**:
   - Modeling trust relationships in distributed systems or online platforms.

---

## References

- [Leetcode Problem 997](https://leetcode.com/problems/find-the-town-judge/)
