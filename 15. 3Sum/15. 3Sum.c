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
        // Skip duplicates for middle element
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
                // Store the triplet
                int temp[3] = {*left, a[i], *right};
                
                // Sort the triplet (your XOR method)
                for (int k = 0; k < 3; k++) {
                    for (int l = k; l < 2; l++) {
                        if (temp[l] > temp[l + 1]) {
                            temp[l] ^= temp[l + 1];
                            temp[l + 1] ^= temp[l];
                            temp[l] ^= temp[l + 1];
                        }
                    }
                }

                // Check if this triplet already exists
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

                // Move pointers
                int current_left = *left;
                int current_right = *right;
                while (left < right && *left == current_left) left++;
                while (left < right && *right == current_right) right--;
            }
        }
    }

    // Final allocation
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


//Their are some douwn points of this code such as high 1127ms of runtime at limited to testcase with outputs less that 100000 which i will be fixing in future
