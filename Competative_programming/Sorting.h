#ifndef SORTING_H_INCLUDED
#define SORTING_H_INCLUDED

/**
            Kefa and Company
            **************
Description : your are given n friends to kefa and you need to select the max company make friendship
----------- where there is no 2 friends in the company has diff in many greate than or equal to d
input : n, d, pairs(money, friendship)
output : max friendship under the predetermined condition
*/

#define ull unsigned long long
struct Friend{int m, f;};
ull findm(const Friend*, int, int);



#endif // SORTING_H_INCLUDED
