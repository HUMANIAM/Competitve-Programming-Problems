#ifndef DYNAMIC_PROGRAMMING_H_INCLUDED
#define DYNAMIC_PROGRAMMING_H_INCLUDED
#define Map(i, d) {(i >= d)? 0 : d}
//*****************************************************************//
//                      Ugly Number Founder
//                      ********************
/*
Description: this algorithm is used to find the ugly number in specific position
------------  if the number is prime of 2, 3, 5 only then it is ugly. In other words
              if number is dividable by only powers of 2, 3, 5 then it ugly.
              EX: ugly sequence : 1 2 3 4 5 6 8 9 10 12 14 . . . . . . . .  . . .
**/

//here we walk through all number till we reach the target order of ugly numbers
//  Time complexity : theta(n)
// Space complexity : O(1)
int findUglyNum_Naive(int);

//her we build the ugly number list using down-top approach till reach the required order
// Time Complexity : O(n)
// Space Complexity : O(n)
int findUglyNum_DB(int);

//assistant functions
bool isUgly(int);
int minVal(int, int, int);
int maxDivision(int, int);

//******************************************************************************//
//                              Coin Exchange
//                              *************

/* Description : this problem is a good example about dp (bottom up solution). we need to find how many ways we can exchange a value
    -----------  with set of coins say {1, 2, 3} and value 5 {1,1,1,1,1}, {1,1,3}, {1,1,1,2}, {1,2,2}, {2,3}
*/
//first solution
int coinExchange( int [], int, int);
//dynamic programming solution
int coinExchangeDp( int [], int, int);

//****************************************************************

/**                     K_tree problem
                        **************
Description : you have a tree where every node has exactly k children and every edge between parent and its child
              kth has weight equal kth. you need to find how many paths has exactly cost equal n and where also
              every one of them has at least one edge with weight >= d
input : 1<= n, k<=100  1<= d <= k
output : number of paths % (1e9 + 7) because it will be very large number
*/
int findPaths(int, int, int);
void findPaths();

/**
                        Flowers
                        ******
Description : today ahmed decide to take dinner of red and white flowers and he want to make his dinner is
------------  good dinner. he decide good dinner is dinner that has white flowers in k contigous order as
an example if k = 2 then good dinner are R, RR, WW, RRR, WWR, RWW, RRRR, RRWW, WWRR, RWWR, but RWWW is not
so you are given k and length of flowers and need to find the max numbers of ways he can take good dinner
*/
void Max_good_dinners(int);
int get_max_good_dinners(int);
#endif // DYNAMIC_PROGRAMMING_H_INCLUDED
