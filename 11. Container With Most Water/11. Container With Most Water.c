int maxArea(int* a, int heightSize) {
    int* left = a;                  // Pointer to the start of the array
    int* right = a + heightSize - 1; // Pointer to the end of the array
    int max = 0;

    while (left < right) {
        // Calculate width and height
        int width = (right - left);
        int height = (*left < *right) ? *left : *right;
        int area = width * height;

        // Update max area if current area is larger
        if (area > max) 
            max = area;

        // Move the pointer with the shorter height inward
        if (*left < *right) 
            left++;
        else 
            right--;
    }

    return max;
}
