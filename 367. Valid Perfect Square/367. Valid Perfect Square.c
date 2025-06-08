#include <math.h>
bool isPerfectSquare(int x) {
    if (x == 0) return 0;
    if (x == 1) return 1;
    int b = 1;                    
    for (int i = 2; i <= x / i; i++) {  
        int temp = i * i;
        if (temp <= x && temp > b * b) {
            b = i;
        }
    }
    if(b*b==x)
    return true;
    else
    return false;
}

