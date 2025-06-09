int countEven(int num) {
    int out=0,sum = 0,rem;
    int i;
    for(int j = 2 ; j<=num ; j++){
        i = j;
    while(i!=0){
        rem = i%10;
        sum+=rem;
        i = i/10;
    }
    if(sum%2 == 0) out++;
    sum=0;
    }
    return out;
}
