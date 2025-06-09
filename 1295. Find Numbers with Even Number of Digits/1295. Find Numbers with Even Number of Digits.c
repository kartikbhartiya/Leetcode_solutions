int findNumbers(int* nums, int numsSize) {
    int ans = 0;
    for (int i = 0; i < numsSize; i++){
       int d = (int)log10(nums[i]) + 1;
       if (d % 2 == 0) ans++;
    }
    return ans;
}


//I have applied another logic based on fixed constrained mentioned below

int findNumbers(int* arr, int numsSize) {
    int output = 0;
    for (int i = 0; i < numsSize; i++) {
        int n = arr[i];
        if ((n >= 10 && n <= 99) || (n >= 1000 && n <= 9999) || n == 100000)
            output++;
    }
    return output;
}








//both have 0ms of runtime
