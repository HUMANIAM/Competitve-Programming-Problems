#ifndef ORGNIZING_LOTTERY_H_INCLUDED
#define ORGNIZING_LOTTERY_H_INCLUDED
#include <vector>
#include <map>
#include <iostream>
using namespace std;
/**
Task. You are given a set of points on a line and a set of segments on a line. The goal is to compute, for
each point, the number of segments that contain this point.

output : number of segments covers every point
We can solve this problem in very simple solution by labeling points by P_{point value} and every segment range
by S_{start of the segment value}, E_{end of the segment value} then put all these labels and sort them in
O(nlog(n)) using say merge sort then walk through sorted list count starts and ends and when meet a point then
it is covered by {stars - ends} segment.
*/
struct Element{
    int value;
    char label;
    Element(int v, char L) : value(v), label(L)
    {}
};

vector<int> organize_lottery(vector<vector<int> >&, vector<int>&);
#endif // ORGNIZING_LOTTERY_H_INCLUDED
