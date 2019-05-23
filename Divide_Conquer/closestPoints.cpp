/**
In this problem we are given a set of points and we need to find the closest two points of them.
we will use the Divide and conquer approach to solve this problem.
thinking of this problem.
1- sort the points according to x coordinate
2- divide the points into two parts Pl and Pr
3- find the closest 2 points in the Pl and the closest 2 points in the right say they are Dl and Dr
4- delta = min(Dl, Dr)
5- take every point from the left say pl with every point from the right far away from pl with
    abs(plx - prx) < delta and abs(ply - pry) < delta
*/
#include "closestPoints.h"

//sort points according to x coordinate
static bool comparePoints_x(Point& p1, Point& p2){
    return p1.x < p2.x;
}
//sort points according to y coordinate
static bool comparePoints_y(Point& p1, Point& p2){
    return p1.y < p2.y;
}
//find points in the rhs and locate in where their x in the delta strip line then sort them by y
void findValidrhsPoints(Point* points, vector<Point>& rhsvalidPoints, double delta,
                         int center, int to, int n){
    for(int i= center + 1; i<= to; i++){
        double dx = (points[i].x - points[center].x);
        if(dx <= delta)
            rhsvalidPoints.push_back(points[i]);
        else
            break;
    }

    //sort them according to y
    sort(rhsvalidPoints.begin(), rhsvalidPoints.end(), &comparePoints_y);
}

//distance between 2 points
static double Distance(Point& p1, Point& p2){
    return sqrt( pow( (p1.x - p2.x), 2 ) + pow( (p1.y - p2.y), 2));
}

//the cross minimum distance between two points from left and right sides
static double minCrossDistance(Point* points, vector<Point>& rhsvPoints, double delta,
                                int from, int center){

    for(int i = center; i >= from; i--){
        double dx = (points[center].x - points[i].x);
        if(dx > delta) break;

        for(auto& rhsvPoint : rhsvPoints){
            int dy = abs(rhsvPoint.y - points[i].y);
            if(dy >= delta)
                break;

            double d = Distance(points[i], rhsvPoint);
            if(d < delta)
                delta =d;
        }
    }
    return delta;
}

static double minimalDistance(Point* points, int from, int to, int n){
    if (to <= from )
        return numeric_limits<double>::max();

    //find the closest distance in the left and the closest distance in the right hand side
    int center = (from + to) / 2;
    double Dl = minimalDistance(points, from, center, n);
    double Dr = minimalDistance(points, center + 1, to, n);

    double delta = min(Dl, Dr);

    //find all points those are away from the center by at most x equal to delta.
    vector<Point> rhsvalidPoints;
    findValidrhsPoints(points, rhsvalidPoints, delta, center, to, n);

    //take every point from the lhs that locate in the delta distance and compare it with other
    //valid points in the right.
    return minCrossDistance(points, rhsvalidPoints, delta, from, center);
}


double closestDistance(Point* points, size_t n){
    sort(points, points + n, &comparePoints_x);
    return minimalDistance(points, 0, n-1, n);
}
