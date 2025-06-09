#include <stdlib.h>

double* convertTemperature(double celsius, int* returnSize) {
    double* arr = (double*)malloc(2 * sizeof(double));
    if (!arr) return NULL; 

    arr[0] = celsius + 273.15;     // Kelvin
    arr[1] = celsius * 1.80 + 32.0; // Fahrenheit

    *returnSize = 2;

    return arr;
}
