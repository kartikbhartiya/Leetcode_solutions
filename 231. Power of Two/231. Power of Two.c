bool isPowerOfTwo(int n) {
     long int k = 1;
    if(n==1) return true;
    if(n%2!=0) return false;
    for( long int i = 2 ; i<=n ; i*=2){
        k*=2;
        if(k==n) return true;
    }
    return false;
}
