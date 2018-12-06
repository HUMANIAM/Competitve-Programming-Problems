#									\# Greatest Common Divisor \#
									
- if we have 2 numbers a and b and we need to find the greatest common divisor between them we can use the 
	Euclid's algorithm

- if b == 0 : result = a else t = b  a = a%b  b = t and continue to the beginning of the line

**complexity time** : you can notice that if a > b and b < a/2 then every iteration decrease a by half	-----------------  which is at the end it will take roughly 2log(a) to reach the reaminder = 0
					so complexity time is **O(log(max(a, b)))**. if b > a the first iteration will swap them

```c++
int gcd_recursive(int N, int M){
    if(M == 0) return N;
    return gcd_recursive(M, N % M);
}
```