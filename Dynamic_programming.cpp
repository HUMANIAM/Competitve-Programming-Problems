#include "Dynamic_programming.h"
#include <algorithm>
#include <iostream>
using namespace std;

// Implementation of Ugly Number Founder //
int maxDivision(int a, int b){
    while(a%b == 0)
        a/=b;
    return a;

}

bool isUgly(int n){
    int no = maxDivision(n, 2);
    no = maxDivision(no, 3);
    no = maxDivision(no, 5);

    return (no == 1)? true : false;
}

int findUglyNum_Naive(int n){
    int m = 1, coun = 1;

    while(n>coun){
        m++;
        if(isUgly(m)) coun++;
    }
    return m;
}

int minVal(int x, int y, int z){
    return min(min(x, y), z);
}

int findUglyNum_DB(int n){
    int uglies[n], i2=0, i3=0, i5=0;
    uglies[0] = 1;

    //find the remaining nth -1 uglies
    for(int m=1; m<n; m++){
        int minv = minVal(2*uglies[i2], 3*uglies[i3], 5*uglies[i5]);

        if(minv == 2*uglies[i2])  i2++;
        if(minv == 3*uglies[i3])  i3++;
        if(minv == 5*uglies[i5])  i5++;

        uglies[m] = minv;

    }
    return uglies[n-1];
}

//implementation of coin exchange //
//first solution:
int coinExchange( int S[], int m, int n )
{
    //if n = 0 don't include any coins
    if (n == 0)
        return 1;

    //n<0 no solution
    if (n < 0)
        return 0;

    //set is empty you can change coins with n>0
    if (m <=0 && n >= 1)
        return 0;

    //C({a0, a1, ...., an}, N) = c({a0, a1, ......., an}, N-an)+c({a0, a1, ......., an-1}, N);
    return coinExchange( S, m - 1, n ) + coinExchange( S, m, n-S[m-1] );
}

//second solution
int coinExchangeDp( int S[], int m, int n )
{
    int i, j, x, y;

    // We need n+1 rows as the table is constructed
    // in bottom up manner using the base case 0
    // value case (n = 0)
    int table[n+1][m];

    // Fill the enteries for 0 value case (n = 0)
    for (i=0; i<m; i++)
        table[0][i] = 1;

    // Fill rest of the table entries in bottom
    // up manner
    for (i = 1; i < n+1; i++)
    {
        for (j = 0; j < m; j++)
        {
            // Count of solutions including S[j]
            x = (i-S[j] >= 0)? table[i - S[j]][j]: 0;

            // Count of solutions excluding S[j]
            y = (j >= 1)? table[i][j-1]: 0;

            // total count
            table[i][j] = x + y;
        }
    }
    return table[n][m-1];
}
////////////////////////*******************************************////////////////////////////


