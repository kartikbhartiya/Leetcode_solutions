# 🔥 Leetcode #4: Median of Two Sorted Arrays – Brute Force in C

> ✅ Solved using pointer-based brute-force logic without prior DSA knowledge  
> 🧠 Language: C | Status: Accepted | Date: June 19, 2025

---

## 📌 Problem Statement

Given two sorted arrays `arr1` and `arr2`, return the median of the merged sorted array. The overall run time complexity should be `O(log(min(n, m)))`, but this solution uses a brute-force approach.

🔗 [Leetcode Problem Link](https://leetcode.com/problems/median-of-two-sorted-arrays/)

---

## ⚙️ Approach: Brute Force + Selection Sort (Pointers)

- Merge both arrays manually into a third array
- Sort the merged array using selection sort (pointer-based logic)
- Find the median:
  - If odd → return middle element
  - If even → return average of two middle elements

---

## ✅ Code

```c
double findMedianSortedArrays(int* arr1, int nums1Size, int* arr2, int nums2Size) {
    int nums3 = nums1Size + nums2Size;
    double arr3[nums3];

    // Merge arr1 and arr2 into arr3
    for (int i = 0; i < nums3; i++) {
        int l = i - nums1Size;
        if (i < nums1Size)
            arr3[i] = arr1[i];
        else if (l < nums2Size)
            arr3[i] = arr2[l];
    }

    // Sort arr3 using pointer-based selection sort
    double *ptr1, *ptr2;
    double temp;
    for (ptr1 = arr3; ptr1 < arr3 + nums3 - 1; ptr1++) {
        for (ptr2 = ptr1 + 1; ptr2 < arr3 + nums3; ptr2++) {
            if (*ptr1 > *ptr2) {
                temp = *ptr2;
                *ptr2 = *ptr1;
                *ptr1 = temp;
            }
        }
    }

    // Return median
    if (nums3 % 2 == 0)
        return (arr3[nums3 / 2 - 1] + arr3[nums3 / 2]) / 2.0;
    else
        return arr3[nums3 / 2];
}
```
## 📊 Time & Space Complexity

| Metric           | Value            |
|------------------|------------------|
| Time Complexity  | O((n + m)²)      |
| Space Complexity | O(n + m)         |

---

## 📈 Performance on Leetcode

- ✅ All 2096 test cases passed  
- ⏱️ Runtime: 59 ms  
- 🧠 Memory: 11.27 MB  
- ⚠️ Beats only 14.65% — will optimization later after learning binary search

---

## 📦 Next Goals

- [ ] Replace selection sort with in-place merge sort for `O(n log n)`
- [ ] Eventually solve in `O(log(min(n, m)))` using binary search on partitions
- [ ] Benchmark and improve memory usage

---
