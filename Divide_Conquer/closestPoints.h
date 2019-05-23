#ifndef CLOSESTPOINTS_H_INCLUDED
#define CLOSESTPOINTS_H_INCLUDED
#include<vector>
#include <limits>
#include <algorithm>
#include <iostream>
using namespace std;
typedef struct {int x, y;} Point;
double closestDistance(Point*, size_t);

#endif // CLOSESTPOINTS_H_INCLUDED
