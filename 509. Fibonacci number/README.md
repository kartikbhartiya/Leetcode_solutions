# Fibonacci Number (C)

This is a C implementation of the "Fibonacci Number" problem from LeetCode (#509).

The Fibonacci sequence is defined as:
- F(0) = 0
- F(1) = 1
- F(n) = F(n-1) + F(n-2) for n > 1

---

## ⚙️ How It Works

This solution uses an iterative approach with memoization:

1. Base cases handle n=0 and n=1 directly
2. For n ≥ 2:
   - Pre-computes all Fibonacci numbers up to n=30
   - Uses three variables (a, b, c) to iterate through the sequence
   - Stores results in an array for O(1) lookup

```c
int fib(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    int arr[31] = {0,1};
    int a = 0, b = 1, c;
    for(int i = 2; i<=30; i++){
        c = a+b;
        a=b;
        b=c;
        arr[i] = c;
    }
    return arr[n];
}

