# Two Sum (Two Pointers) — C Solution

This is a C implementation of the classic **Two Sum II - Input Array is Sorted** problem using the **two pointers** technique.

## Problem

Given a **sorted array** of integers and a target value, return the indices (1-based) of the two numbers such that they add up to the target.

- Exactly one solution exists.
- You may not use the same element twice.
- Return the answer as a dynamically allocated array of size 2.
- The array must be returned using `malloc` as per LeetCode requirements.

## Code

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* a, int numbersSize, int target, int* returnSize) {
    int *p1 = &a[0];
    int *p2 = &a[numbersSize - 1];
    int* arr = (int*)malloc(2 * sizeof(int));  

    for (int i = 0; i < numbersSize; i++) {
        if (*p1 + *p2 < target) p1++;
        else if (*p1 + *p2 > target) p2--;
        else if (*p1 + *p2 == target) break;
    }

    arr[0] = p1 - a + 1;  // 1-based indexing
    arr[1] = p2 - a + 1;
    *returnSize = 2;

    return arr;
}
```

## Example

**Input:**
```c
a = [2, 7, 11, 15];
target = 9;
```

**Output:**
```c
[1, 2]
```

## Time and Space Complexity

- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

## How It Works

- Initialize two pointers, one at the start and one at the end of the array.
- Move the pointers inward based on whether their sum is less than or greater than the target.
- Once the target sum is found, return the 1-based indices.

---
