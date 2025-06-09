int sumOfTheDigitsOfHarshadNumber(int x) {
    int sum = 0 , rem , t = x;
    while(t!=0){
        rem = t%10;
        sum+=rem;
        t = t/10;
    }
    if(x%sum == 0) return sum;
    else return -1;
}
