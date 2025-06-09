int fib(int n){
if(n==0) return 0;
if(n==1) return 1;
int arr[31] = {0,1};
int a = 0 , b = 1 ,c;
for(int i = 2 ; i<=30 ; i++){
    c = a+b;
    a=b;
    b=c;
    arr[i] = c;
}

return arr[n-1] + arr[n-2];
}
