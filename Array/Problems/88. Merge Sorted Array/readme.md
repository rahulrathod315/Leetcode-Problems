# 88. Merge Sorted Array

This folder contains the solution to the Leetcode problem **88. Merge Sorted Array** implemented in C++.

## Problem Description

You are given two integer arrays `nums1` and `nums2`, sorted in **non-decreasing order**, and two integers `m` and `n`, representing the number of elements in `nums1` and `nums2`, respectively.

Merge `nums2` into `nums1` as one sorted array.

The final sorted array should not be returned by the function but instead be stored inside the array `nums1`. To accommodate this, `nums1` has a length of `m + n`, where the first `m` elements denote the elements that should be merged, and the last `n` elements are set to `0` and should be ignored.

---

## Example 1

```
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6].
```

### Example 2

```
Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: Nothing needs to be merged, so nums1 remains the same.
```

### Example 3

```
Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1], which is stored in nums1.
```

### Constraints

- `nums1.length == m + n`
- `nums2.length == n`
- `0 <= m, n <= 200`
- `1 <= m + n <= 200`
- `-10^9 <= nums1[i], nums2[i] <= 10^9`

---

## Approach 1: Insertion-Based Merge

### Explanation

This approach uses two pointers to traverse `nums1` and `nums2` and inserts elements from `nums2` into `nums1` at the correct position.

1. **Two Pointers**:
   - Use two pointers `i` and `j` to traverse `nums1` and `nums2`, respectively.
   - `i` starts at the beginning of the valid elements in `nums1` (index `0`), and `j` starts at the beginning of `nums2`.

2. **Comparison and Insertion**:
   - Compare the elements at `nums1[i]` and `nums2[j]`.
   - If `nums1[i] <= nums2[j]`, move the pointer `i` forward.
   - If `nums1[i] > nums2[j]`, shift all elements in `nums1` from index `i` to `m` one position to the right to make space for `nums2[j]`. Then, insert `nums2[j]` at index `i` and increment both `i` and `j`. Also, increment `m` to account for the newly added element.

3. **Remaining Elements**:
   - If there are remaining elements in `nums2` after the first loop, insert them into `nums1` in the same manner.

---

### Implementation

```cpp
// Approach 1: Insertion-Based Merge
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        if(nums1.size() == 0 || nums2.size() == 0) // If either array is empty, return
            return;

        int i = 0; // Pointer for nums1
        int j = 0; // Pointer for nums2

        // Traverse both arrays
        while(i < m && j < n)
        {
            if(nums1[i] <= nums2[j]) // If nums1[i] is smaller or equal, move i forward
            {
                i++;
            }
            else // If nums2[j] is smaller, insert it into nums1
            {
                for(int k = m; k > i; k--) // Shift elements in nums1 to the right
                {
                    nums1[k] = nums1[k-1];
                }
                nums1[i++] = nums2[j++]; // Insert nums2[j] into nums1
                m++; // Increment the size of valid elements in nums1
            }
        }

        // Insert remaining elements from nums2 into nums1
        while(j < n)
        {
            for(int k = m; k > i; k--) // Shift elements in nums1 to the right
            {
                nums1[k] = nums1[k-1];
            }
            nums1[i++] = nums2[j++]; // Insert nums2[j] into nums1
            m++; // Increment the size of valid elements in nums1
        }
    }
};
```

---

### Example Walkthrough

#### Input: `nums1 = [1,2,3,0,0,0]`, `m = 3`, `nums2 = [2,5,6]`, `n = 3`

1. **Initialization**:
   - `i = 0`, `j = 0`, `m = 3`.

2. **First Iteration**:
   - Compare `nums1[0] = 1` and `nums2[0] = 2`.
   - Since `1 <= 2`, increment `i` to `1`.

3. **Second Iteration**:
   - Compare `nums1[1] = 2` and `nums2[0] = 2`.
   - Since `2 <= 2`, increment `i` to `2`.

4. **Third Iteration**:
   - Compare `nums1[2] = 3` and `nums2[0] = 2`.
   - Since `3 > 2`, shift elements in `nums1` to the right and insert `2` at index `2`.
   - Update `nums1 = [1,2,2,3,0,0]`, `i = 3`, `j = 1`, `m = 4`.

5. **Fourth Iteration**:
   - Compare `nums1[3] = 3` and `nums2[1] = 5`.
   - Since `3 <= 5`, increment `i` to `4`.

6. **Insert Remaining Elements**:
   - Insert `5` and `6` from `nums2` into `nums1`.
   - Final `nums1 = [1,2,2,3,5,6]`.

#### Complexity Analysis

1. **Time Complexity**: `O(m * n)`
   - In the worst case, for each element in `nums2`, all elements in `nums1` may need to be shifted, resulting in a time complexity of `O(m * n)`.

2. **Space Complexity**: `O(1)`
   - The solution uses constant extra space as the merging is done in-place.

---

## Approach 2: Optimized Two-Pointer Approach

### Explanation

This approach uses two pointers starting from the end of both arrays to avoid shifting elements in `nums1`.

1. **Two Pointers from the End**:
   - Use two pointers `i` and `j` to traverse `nums1` and `nums2` from the end.
   - Use a third pointer `k` to track the position where the next largest element should be placed in `nums1`.

2. **Comparison and Placement**:
   - Compare the elements at `nums1[i]` and `nums2[j]`.
   - Place the larger element at `nums1[k]` and decrement the corresponding pointer (`i` or `j`) and `k`.

3. **Remaining Elements**:
   - If there are remaining elements in `nums2`, copy them into `nums1`.

---

### Implementation

```cpp
// Approach 2: Optimized Two-Pointer Approach
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int i = m - 1; // Pointer for the last valid element in nums1
        int j = n - 1; // Pointer for the last element in nums2
        int k = m + n - 1; // Pointer for the last position in nums1

        // Traverse both arrays from the end
        while(i >= 0 && j >= 0)
        {
            if(nums1[i] > nums2[j]) // If nums1[i] is larger, place it at nums1[k]
            {
                nums1[k--] = nums1[i--];
            }
            else // If nums2[j] is larger or equal, place it at nums1[k]
            {
                nums1[k--] = nums2[j--];
            }
        }

        // Copy remaining elements from nums2 into nums1
        while(j >= 0)
        {
            nums1[k--] = nums2[j--];
        }
    }
};
```

---

### Example Walkthrough

#### Input: `nums1 = [1,2,3,0,0,0]`, `m = 3`, `nums2 = [2,5,6]`, `n = 3`

1. **Initialization**:
   - `i = 2`, `j = 2`, `k = 5`.

2. **First Iteration**:
   - Compare `nums1[2] = 3` and `nums2[2] = 6`.
   - Place `6` at `nums1[5]`.
   - Update `nums1 = [1,2,3,0,0,6]`, `j = 1`, `k = 4`.

3. **Second Iteration**:
   - Compare `nums1[2] = 3` and `nums2[1] = 5`.
   - Place `5` at `nums1[4]`.
   - Update `nums1 = [1,2,3,0,5,6]`, `j = 0`, `k = 3`.

4. **Third Iteration**:
   - Compare `nums1[2] = 3` and `nums2[0] = 2`.
   - Place `3` at `nums1[3]`.
   - Update `nums1 = [1,2,3,3,5,6]`, `i = 1`, `k = 2`.

5. **Remaining Elements**:
   - Place `2` at `nums1[2]`.
   - Final `nums1 = [1,2,2,3,5,6]`.

#### Complexity Analysis

1. **Time Complexity**: `O(m + n)`
   - Each element in `nums1` and `nums2` is processed once.

2. **Space Complexity**: `O(1)`
   - The solution uses constant extra space as the merging is done in-place.

---

## Applications

1. **Merging Sorted Data**:
   - This approach is useful in scenarios where two sorted datasets need to be merged into one.

2. **Sorting Algorithms**:
   - Merging sorted arrays is a key step in the **Merge Sort** algorithm.

3. **Data Integration**:
   - Used in applications where sorted data from different sources needs to be combined.

---

## References

- [Leetcode Problem 88](https://leetcode.com/problems/merge-sorted-array/)
