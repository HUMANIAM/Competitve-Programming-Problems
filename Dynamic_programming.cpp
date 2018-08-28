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
////////////////////////*******************************************////////////////////////////


