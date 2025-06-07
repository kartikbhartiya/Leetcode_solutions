int mySqrt(int x) {
    if (x == 0) return 0;
    if (x == 1) return 1;
    int b = 1;                    // track the current best
    for (int i = 2; i <= x / i; i++) {  // avoid overflow
        int temp = i * i;
        // only update when i*i is ≤ x *and* larger than previous b*b
        if (temp <= x && temp > b * b) {
            b = i;
        }
    }
    return b;
}
