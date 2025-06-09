#include <math.h>
int maximum69Number (int num) {
    int total = 0 , b ,temp = num;
    int arr[4];
    while(temp!=0){
        b = temp%10;
        arr[total] = b;
        total++;
        temp = temp/10;
    }
    for(int i = total-1 ; i>=0 ; i--){
        if(arr[i] == 6) {arr[i] = 9;
         break;
        }
    }
    int sum = 0;
    for(int i = total - 1; i >= 0; i--){
        sum = sum * 10 + arr[i];
    }

    return sum;
}
