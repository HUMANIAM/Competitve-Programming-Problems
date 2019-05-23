#ifndef MERGESORT_H_INCLUDED
#define MERGESORT_H_INCLUDED

#include <iostream>
#include <vector>
using namespace std;
/**
    Merge sort : is one of using algorithms that use divide and conquer approach to sort an algorithms
    *********   where dividing the list into sublists sort them then combine the sorted ones into the larger
                list
    running time is O(nlog(n))
    ************
*/

void merge_sort(vector<int>&, int, int);

#endif // MERGESORT_H_INCLUDED
