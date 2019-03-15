#ifndef GREADY_PROBLEMS_H_INCLUDED
#define GREADY_PROBLEMS_H_INCLUDED
#include <vector>
#include <string>
using namespace std;

/**                                 Greedy algorithms
                                    ^^^^^^^^^^^^^^^^
* the main Idea behind the greedy technique is making sure that any move will be safe that means this move will reach you to an optimal
    solution

* but how to make you choice is safe you need to do some computation like sort the input, normalize it, do something that helps you to make
you choices are safe. if you can't find one then this technique will fail and you need to use another one like dp, backtracking, local search
, sat solver ....................................................

* the next problems are training on the greedy technique to master where exactly it can be successful and where it can be failure. I need to
find the main feature of the greedy technique.

* I notice that in every problem greedy algorithm order objects in order where that has max profit come first to choose it first. sometimes
  we don't need order and start move immediately. it is sometimes not save to reach the optimal solution
*/

/**    Changing Money
        ------------
Description : The goal in this problem is to find the minimum number of coins needed to change the input value
-----------(an integer) into coins with denominations 1, 5, and 10
complexity time : O(1)
*/

int changewith(int, int, int& );
int minCoins(int);

/**  Maximizing the Value of a Loot
        ---------------------------
Description : The goal of this code problem is to implement an algorithm for the fractional knapsack problem.
complexity time: O(nlog(n))
*/

struct Item{
    int w, v;
    float vPerw;
    Item(int w, int v) : w(w), v(v){ vPerw = ((float)v) / w;}

    bool operator < (const Item& rhs)const {
        return vPerw < rhs.vPerw;
    }
};

float fractionalKnapsack(int, int*, int*, int);

/** Maximizing Revenue in Online Ad Placement
    ----------------------------------------
Description : Given two sequences 𝑎1, 𝑎2, . . . , 𝑎𝑛 (𝑎𝑖 is the profit per click of the 𝑖-th ad) and 𝑏1, 𝑏2, . . . , 𝑏𝑛 (𝑏𝑖 is
------------ the average number of clicks per day of the 𝑖-th slot), we need to partition them into 𝑛 pairs (𝑎𝑖, 𝑏𝑗)
such that the sum of their products is maximized.
complexity time : O(nlog(n))
-----------
*/

double maxRevenue(int*, int*, int);

/** Collecting Signatures
    ---------------------
Description : Given a set of 𝑛 segments {[𝑎0, 𝑏0], [𝑎1, 𝑏1], . . . , [𝑎𝑛−1, 𝑏𝑛−1]} with integer coordinates on a line, find
-----------  the minimum number 𝑚 of points such that each segment contains at least one point. That is, find a
set of integers 𝑋 of the minimum size such that for any segment [𝑎𝑖, 𝑏𝑖] there is a point 𝑥 ∈ 𝑋 such
that 𝑎𝑖 ≤ 𝑥 ≤ 𝑏𝑖
in other words you need to find the minimum number of points belongs to A U B where every segment must be touches by at least one point
complexity time : O(nlog(n))
*/
struct Point{
    int from, to;
    Point(int f, int t) : from(f), to(t){}

    bool operator < (const Point& rhs) const{
        return rhs.to < to;
    }
};

void minPoints_touchAllSegments(const int*, int*, int, vector<Point>&);

/**     Maximizing the Number of Prize Places in a Competition
        --------------------------------------------------------
Description :The goal of this problem is to represent a given positive integer 𝑛 as a sum of as many pairwise
------------ distinct positive integers as possible. That is, to find the maximum 𝑘 such that 𝑛 can be written as
𝑎1 + 𝑎2 + · · · + 𝑎𝑘 where 𝑎1, . . . , 𝑎𝑘 are positive integers and 𝑎𝑖 ̸= 𝑎𝑗 for all 1 ≤ 𝑖 < 𝑗 ≤ 𝑘.

complexity time : O(n)

solution Here is based on start in solution directly where you don't need to make any preprocessing we start with 1 and then 2 and then 3
till we can't achieve the required number then add it to the last one
assume L = a1 then to go to new subproblem you need to make sure that (k-L)>2*(L+1) or all you want to do is adding the remaining of k to
the last one L=1 (1 + 2 + 3 + ....... + (an + (k-an))
*/

void makeChildren_happy(int , vector<int>&);

/**     Maximizing Your Salary
        ---------------------
Description : Compose the largest number out of a set of integers
complexity time : O(nlog(n))
*/
bool isGreater(const string&, const string&);

string findMax_salary(const vector<string>&, int);

struct Number{
    string number;
    Number(string n) : number(n){}

    bool operator < (const Number& rhs) const {
        return isGreater(rhs.number, number);
    }
};

/**    Heist
        ------
Description :
------------There was an electronic store heist last night.All keyboards which were in the store yesterday were
numbered in ascending order from some integer number x. For example, if x=4 and there were 3 keyboardsin the store, then
the devices had indices 4, 5 and 6, and if x=10 and there were 7 of them then the keyboards had indices 10, 11, 12, 13, 14, 15 and 16.
After the heist, only n keyboards remain, and they have indices a1,a2,…,an. Calculate the minimum possible number of keyboards
that have been stolen. The staff remember neither x nor the number of keyboards in the store before the heist.

complexity time : O(nlogn)
--------------
*/
int findMinStolen_keyboards(int*, int );
#endif // GREADY_PROBLEMS_H_INCLUDED
