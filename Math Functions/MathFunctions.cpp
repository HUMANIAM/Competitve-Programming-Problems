/** this file is about simple math functions and their implementation*/

#define LL long long

/**GCD : greatest common divisor*/
//complexity : O(log(N)) for N/M
// looping version
int gcd_iteration(int N, int M){
    int rem;
    while(M != 0){
        rem = N % M;
        N = M;
        M = rem;
    }
    return N;
}

//recursion version
int gcd_recursive(int N, int M){
    if(M == 0) return N;
    return gcd_recursive(M, N % M);
}

/**LCM : Least common multiple*/
// complexity time : like gcd
LL lcm(int N, int M){
    return (LL) (N* ( M / gcd_iteration(N, M)));
}

/** check if number is divisable by  8 */
//* this problem is about finding subnumber of number that is divisable by 8 but digits of subnumber must 
// must be in the same order
int findTheDivisableByEight(int* number, int n){
    /** it is very interesting to know that number can be divided by eight if
    and only if its last three digits form a number that can be divided by eight*/
    // check if there are one digit = 8
    for(int i = 0; i<n; i++)
        if(number[i] % 8 == 0)
            return number[i];

    // check if there is any combination of 2 numbers dividable by 8
    for(int i=0; i<n; i++){
        int num = number[i] * 10;
        for(int j = i + 1; j<n; j++){
            int nnum = num + number[j];
            if(nnum % 8 == 0)
                return nnum;
        }
    }

    // check if there is any combination of 3 numbers can be dividable by 8
    for(int i=0; i<n; i++){
        int num = number[i]*100;
        for(int j=i+1; j<n; j++){
            int nnum = num + number[j]*10;
            for(int k=j+1; k<n; k++){
                int nnnum = nnum + number[k];
                if(nnnum % 8 == 0)
                    return nnnum;
            }
        }
    }
    return -1;
}