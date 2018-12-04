
/**
    Fibonancci series is invented by the Italian mathematician finonancci in 18th century
    Formula : F(n) = 0                  if n == 0
                     1                  if n == 1
                     F(n-1) + F(n-2)    if n > 1

    there are many ways to implement it. some of them are naives has exponential time complexity and another are efficient
    has linear time complexity. and one of them can get F(n) in complexity time that is constant complexity time
    I will implement all of them in this program
*/
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
#define LL long long
#define swap(t,x,y) { t _z; \
             _z = x;\
              x = y;\
              y = _z; }
// naive algorithm is recursive algorithm but it makes so much redundant computation
// complexity time : O(1.62^n)

LL naive_fibonancci(int n){
    if(n <= 1)          // base case
        return n;
    return naive_fibonancci(n-1) + naive_fibonancci(n-2);
}

// we can avoid redundant computation by storing sub solutions of sub problems using memorization (dynamic programming)
// complexity time : O(n)
LL dp_fibonancci(int n){
    if(n <= 1)      //base case
        return n;

    LL dpTable[n+1];
    dpTable[0] = 0;
    dpTable[1] = 1;

    for(int i=2; i<=n; i++)
        dpTable[i] = dpTable[i-1] + dpTable[i-2];

    return dpTable[n];
}

// using less memory to save only the useful solutions to reach the final solution which is F(n)
LL dp_simple_fibonancci(int n){
    if(n <= 1)      //base case
        return n;

    int a = 0;
    int b = 1;
    int tmp;
    for(int i=2; i<=n; i++){
        b += a;
        a = b - a;
    }
    return b;
}

// This is closed form formula for computing F(n) take O(1) as complexity time (Binet's formula)
// the nominator must be computed completely before the denominator to avoid floating point error
// that results in when n = 38 the nominator is very large number to hold in long long type it converted to -1
// this is the main problem with binet's formula
LL binet_fibonancci(int n){
    LL denominator = pow(2, n) * sqrt(5);
    LL nominator  = pow(1 + sqrt(5), n) - pow(1 - sqrt(5), n);

    return nominator / denominator;

}

// stress test all solution against the naive one (we are sure it is correct mathematically)
int stress_test(void){
    int n=40;
    std::cout<<"Test until F40\n";

    std::cout<<"* dynamic programming solution\n";
    for(int i=1; i<=n; i++)
        if(!(naive_fibonancci(i) == dp_fibonancci(i))){
            std::cout<<"    ^ Fail at F"<<i<<std::endl;
            return -1;
        }
    std::cout<<"    ^ passed\n";

    std::cout<<"* simple dynamic programming solution\n";
    for(int i=1; i<=n; i++)
        if(!(naive_fibonancci(i) == dp_simple_fibonancci(i))){
            std::cout<<"    ^ Fail at F"<<i<<std::endl;
            return -1;
        }
    std::cout<<"    ^ passed\n";

    std::cout<<"* benit's formula dynamic programming solution\n";
    for(int i=1; i<=n; i++)
        if(!(naive_fibonancci(i) == binet_fibonancci(i))){
            std::cout<<"    ^ Fail at F"<<i<<std::endl;
            return -1;
        }
    std::cout<<"    ^ passed\n";

    return 1;
}

// for F200 you can't store it in memory type but there are so many problems don't need the F(n) itself but part of it
// Last digit of large Fibonancci number
int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)    //base case
        return n;

   int f1=0, f2=1, temp;
   for(int i=2; i<=n; i++){
       temp = f2;
       f2 = (f1+f2) % 10;
       f1=temp;
   }
        return f2;
}

/**huge finonancci module m like F(n) % m */
// if we try do some series of fibonancci series you will find its periodic where remainder repeat periodically
// so all you need is find the period length and their remainders
// then know exactly the n located in this period without calculate the F(n) then return sequence(n%m)
// when you calculate the remainder cycle you don't need to save the fibonancci value just the remainder
// any remainder cycle start with 0 and 1

int computeCycle_remainder(vector<int>& cycle_remainder, LL n, int m){
    cycle_remainder.push_back(0);
    cycle_remainder.push_back(1);

    int index = 2;
    while(index <= n){
        int r = (cycle_remainder[index-1] + cycle_remainder[index - 2]) % m;
        if(r==1 && cycle_remainder[index-1] == 0){ //start of new cycle
            cycle_remainder.pop_back();         //remove the last zero
            return cycle_remainder.size();
        }
        else
            cycle_remainder.push_back(r);

        index++;
    }

    //if there is no cycle found
    return -1;
}

int fibonancci_module_m(LL n, int m){
    if(n==1) return n;

    vector<int> cycle_remainder;
    int cycleLength = computeCycle_remainder(cycle_remainder, n, m);

    if(cycleLength != -1){
        int pos = n % cycleLength;
        return cycle_remainder[pos];

    }else
        return cycle_remainder[cycle_remainder.size()-1];
}

/** First digit of Partial sum of fibonancci numbers*/
// after we know that we don't need to compute all F to compute the first digit of sum
// we can note also in sum there is a cycle repeat every specific length so once we find it we can compute
// the first digit of the sum to specific n at a glance
int fibonacci_sum_rem10(long long n) {
    if (n <= 1)
        return n;

    int temp;
    long long i;
    vector<int> a;
    a.push_back(0);     //pre fab reminder
    a.push_back(1);     //cur fab reminder

    // sumUntilN = F(N) + F(N-1) + F(N-2)
    for (i = 2; i <= n ; ++i) {
        a.push_back(( ((a[i-2] + a[i-1]) % 10) + a[i-1]) % 10);
        if( a[i-1] == 0 && a[i] == 1)   break;
    }
    if(--i == n)
      return a[i];

    return a[n % i];
}


long long get_fibonacci_partial_sum(long long from, long long to) {
    if (to <= 1)
        return to;

    int sumfrom = fibonacci_sum_rem10(from-1);   //sum of finbonacci till Fm-1
    int sumto = fibonacci_sum_rem10(to);       // sum of fibonacci till Fn

    sumto -= sumfrom;
    if(sumto > 0) return sumto;
    else return sumto + 10;

}

/** max Fibonancci segement in sequence of numbers*/
int findMaxFibonancciSegement(int* arr, int n){
    if(n <= 2) cout<<n<<endl;
    else{
        int maxsegment = 2;
        int left = 0;
        int right = 2;
        while(right < n){
            if(arr[right] != (arr[right-1] + arr[right-2])){
                if((right - left) > maxsegment)
                    maxsegment = right - left;
                left = right - 1;
            }
            right++;
        }

        if((right - left) > maxsegment) maxsegment = (right - left);
        cout<<maxsegment<<endl;
    }
}
