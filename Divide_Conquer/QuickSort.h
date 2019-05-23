#ifndef QUICKSORT_H_INCLUDED
#define QUICKSORT_H_INCLUDED
#include <vector>
#include <cstdlib>
using namespace std;
/**
    Quick sort like merge sort is based on divide and conquer approach.
    average running time is (nlog(n)) and it is comparison-based sorting algorithm while merge sort is
    movement-based sorting algorithm.
*/

// there are many ways to select the pivot in Quick sort algorithm but we need a strategy that do it in an
// efficient way. and also handle repetition in an efficient way

void randomized_quick_sort(vector<int> &, int , int );
#endif // QUICKSORT_H_INCLUDED
