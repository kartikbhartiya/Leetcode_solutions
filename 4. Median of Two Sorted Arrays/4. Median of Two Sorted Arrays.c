double findMedianSortedArrays(int* arr1, int nums1Size, int* arr2, int nums2Size) {
    int nums3 = nums1Size + nums2Size;
    double arr3[nums3];
    for(int i = 0 ; i <nums3 ; i++){
        int l = i-nums1Size;
        if(i<nums1Size) arr3[i] = arr1[i];
        else if(l<nums2Size) arr3[i] = arr2[l];
    }
    double *ptr1 = arr3;
    double *ptr2 = &arr3[nums3 - 1];
    int temp;
    for(ptr1 = arr3 ; ptr1<arr3+nums3-1 ; ptr1++){
        for(ptr2 = ptr1 + 1 ; ptr2<arr3+nums3 ; ptr2++){
            if(*ptr1>*ptr2){
                temp = *ptr2;
                *ptr2 = *ptr1;
                *ptr1 = temp;
            }
        }
    }
    double result;
    if(nums3%2 == 0) result = (arr3[nums3/2 -1] + arr3[nums3/2 + 1 -1])/2;
    else result = arr3[(nums3 + 1)/2 - 1];
    return result;
}

// I solved this problem with brute force until the time being i learn DSA topics
