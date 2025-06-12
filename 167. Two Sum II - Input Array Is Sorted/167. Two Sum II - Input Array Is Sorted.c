/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* a, int numbersSize, int target, int* returnSize) {
    int *p1 = &a[0];
    int *p2 = &a[numbersSize-1];
    int* arr = (int*)malloc(2 * sizeof(int));  
    for(int i = 0 ; i<numbersSize ; i++){
        if(*p1+*p2<target) p1++;
        else if(*p1+*p2>target) p2--;
        else if(*p1+*p2 == target)  break;
    }
    arr[0] = p1 - a + 1;
    arr[1] = p2 - a+ 1;
    *returnSize = 2;
    return arr;
}
