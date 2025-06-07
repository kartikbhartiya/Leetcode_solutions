int clumsy(int N) {
    int res = 0;      
    int last = N;     
    int op = 0;        

    
    for (int k = N - 1; k >= 1; --k) {
        if (op == 0) {
            
            last = last * k;
        }
        else if (op == 1) {
            last = last / k;
        }
        else if (op == 2) {
            res += last;
            last = k;   
        }
        else {
            res += last;
            last = -k;
        }
        op = (op + 1) % 4;  
    }

    res += last;
    return res;
}
