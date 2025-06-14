int removeDuplicates(int* nums, int numsSize) {
    int n = 0;
    int *ptr1 = nums;
    int *ptr2 = &nums[1];
    for(ptr2 = nums+1 ; ptr2<nums+numsSize ; ptr1++,ptr2++){
        if(*ptr1 != *ptr2){
        nums[n] = *ptr1;
        n++;
        }
        if(ptr2 == nums+numsSize-1){nums[n] = *ptr2;}
    }
    return n+1;
}
