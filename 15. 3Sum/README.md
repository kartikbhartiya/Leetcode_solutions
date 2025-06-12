# 🔍 Three Sum Problem – C Implementation

This repository contains an efficient and low-level C solution to the classic **3Sum** problem from LeetCode. It uses pure **pointer arithmetic**, **manual memory management**, and **bitwise XOR** operations for sorting.

---

## 📌 Problem Statement

> Given an integer array `nums`, return all the triplets `[nums[i], nums[j], nums[k]]` such that:
>
> - `i != j`, `i != k`, and `j != k`
> - `nums[i] + nums[j] + nums[k] == 0`
>
> The returned triplets must be **unique**.

---

## ⚙️ Approach

- Sort the array using XOR-based Bubble Sort
- Use one loop to fix a number (`a[i]`) as the middle of the triplet
- Use two pointers (`left`, `right`) to find two numbers that sum to `-a[i]`
- Skip over duplicates
- Store unique triplets in a 2D array
- Return result using dynamic memory allocation (`malloc`)

---

## 🧠 Function Signature

```c
int** threeSum(int* a, int numsSize, int* returnSize, int** returnColumnSizes);
```

---

## 🧾 Full Code

```c
#include <stdlib.h>

int** threeSum(int* a, int numsSize, int* returnSize, int** returnColumnSizes) {
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < numsSize - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                a[j] ^= a[j + 1];
                a[j + 1] ^= a[j];
                a[j] ^= a[j + 1];
            }
        }
    }

    int arr[100000][3];  // Temporary storage
    int n = 0;

    for (int i = 1; i < numsSize - 1; i++) {
        if (i > 1 && a[i] == a[i - 1]) continue;

        int sum = -a[i];
        int* left = a;
        int* right = a + numsSize - 1;

        while (left < right) {
            if (left == a + i) { left++; continue; }
            if (right == a + i) { right--; continue; }

            int pairSum = *left + *right;

            if (pairSum < sum) {
                left++;
            } else if (pairSum > sum) {
                right--;
            } else {
                int temp[3] = {*left, a[i], *right};

                for (int k = 0; k < 3; k++) {
                    for (int l = k; l < 2; l++) {
                        if (temp[l] > temp[l + 1]) {
                            temp[l] ^= temp[l + 1];
                            temp[l + 1] ^= temp[l];
                            temp[l] ^= temp[l + 1];
                        }
                    }
                }

                int isDuplicate = 0;
                for (int k = 0; k < n; k++) {
                    if (arr[k][0] == temp[0] && 
                        arr[k][1] == temp[1] && 
                        arr[k][2] == temp[2]) {
                        isDuplicate = 1;
                        break;
                    }
                }

                if (!isDuplicate) {
                    arr[n][0] = temp[0];
                    arr[n][1] = temp[1];
                    arr[n][2] = temp[2];
                    n++;
                }

                int current_left = *left;
                int current_right = *right;
                while (left < right && *left == current_left) left++;
                while (left < right && *right == current_right) right--;
            }
        }
    }

    int** result = (int**)malloc(n * sizeof(int*));
    *returnColumnSizes = (int*)malloc(n * sizeof(int));
    *returnSize = n;

    for (int i = 0; i < n; i++) {
        result[i] = (int*)malloc(3 * sizeof(int));
        result[i][0] = arr[i][0];
        result[i][1] = arr[i][1];
        result[i][2] = arr[i][2];
        (*returnColumnSizes)[i] = 3;
    }

    return result;
}
```

---

## 🧪 Sample Test Code

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int returnSize;
    int* returnColumnSizes;

    int** result = threeSum(nums, 6, &returnSize, &returnColumnSizes);

    for (int i = 0; i < returnSize; i++) {
        printf("[%d, %d, %d]\n", result[i][0], result[i][1], result[i][2]);
        free(result[i]);
    }

    free(result);
    free(returnColumnSizes);
    return 0;
}
```

---

## ✅ Sample Output

```
[-1, -1, 2]
[-1, 0, 1]
```

---

## 🧩 Problems

- 🔴 **Runtime**: Currently takes up to ~1127ms for large test cases.
- 🟠 **Scalability**: Temporary array `arr[100000][3]` can’t handle results beyond 100K triplets.
- 🟡 **Brute Force Deduplication**: Manual duplicate checking makes the algo slower at scale.
- ⚠️ **Non-optimized Sorting**: Using XOR Bubble Sort for fun, but it's not performant.

---

## 🔧 Future Fixes

- ✅ Replace XOR Bubble Sort with `qsort()` for faster sorting.
- ✅ Use hashing or binary search tree to optimize duplicate checks.
- ✅ Add LeetCode judge performance screenshot in repo later.
- ✅ Maybe implement with structs to store more metadata (indexes etc.)

---

## 📎 Problem Link

[LeetCode – 3Sum](https://leetcode.com/problems/3sum/)

---

## 💡 Concepts Used

- Pointer arithmetic
- XOR-based sorting
- Dynamic memory allocation
- Two-pointer technique
- Manual deduplication

---

## 👨‍💻 Author

**Kartik**  
B.Tech CSE (2025–2029)  

---

## ⭐️ If You Found This Helpful

Drop a ⭐ on the repo. Let’s keep climbing.
