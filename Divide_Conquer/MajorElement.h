#ifndef MAJORELEMENT_H_INCLUDED
#define MAJORELEMENT_H_INCLUDED
#include <iostream>
#include <vector>
using namespace std;
/**
    Majority element problem is about checking whether there is an element with majority in a list or not
    We will solve this problem using many different approaches
    1- naive one is counting the occurrence of every element by pass through the list with every element
        O(n^2)
    2- divide and conquer approach by divide the list into two parts find the major one in left say m1 and
        find the major one in right say m2 then choose from m1 and m2 the one has majority over all the array
        O(nlog(n))
    3- mapping

    //we will implement only the second solution D&C approach. solution close to the merge sort but instead of
      sorting the 2 halves we find the major element in both parts. why this solution is correct?
      because if m1 represent the major element in left part then m1 > 0.25 total list and the same with m2
      then (m1 + m2) > 0.5 total list so any element else will have size < 0.5
*/

typedef struct MajorElment{
    int element, occurrence;
    //constructor
    MajorElment() : element(-1), occurrence(-1)
    {}
    MajorElment(int e, int o) : element(e), occurrence(o)
    {}
    } MajorElment;

MajorElment find_major_element(const vector<int>&, size_t, size_t);

#endif // MAJORELEMENT_H_INCLUDED
