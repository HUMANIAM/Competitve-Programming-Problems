#ifndef DYNAMIC_PROGRAMMING_H_INCLUDED
#define DYNAMIC_PROGRAMMING_H_INCLUDED

#include <vector>
#include <string>
#include <limits.h>
using namespace std;
/** dp is one of the most used algorithms in computer science and it based on the idea of
 * to solve a big complex problem start solve the smaller ones and store the solutions. then solve the bigger
    ones using the solutions of the smaller problems.
*/


/** find the minimum number of coins to change a coin with denomination coins
*/
// using dp
int dpCoinChangeMoney(int, const vector<int>&);


// using divide and conquer
int divideAndConquer_ChangeMoney(int, const vector<int>&);


// entry point function
int changeCoins(int, const vector<int>& );

/** primitive calculator is a problem about going from 1 to target number n with the minimum number
 of operations of *2, *3,  +1 */
 // this problem is a straight forward example about the dynamic programming technique.
 typedef struct Operation{
     // 0 for no operation, 1 for +1, 2 for *2, 3 for *3
    int min_operations;
    int last_operation;
    Operation():min_operations(0), last_operation (0){}
}Operation;

// find minimum number of operations to reach from 1 to n
vector<Operation> optimal_min_operatins(int);

/**Take as Much Gold as Possible problem is the same as knapsack problem without repetitions
*/
// we have to options for every item take it or not and our decision is based on the one gives the max
// value. if we don't take the item then we need to solve the same problem with same same capacity but with
// the remaining items, and if we take the item then we also need to solve the same problem without the current
// item and with capacity with capacity - the taken item. As you can see the solution for the bigger problem
// depends on the solution of the smaller problems and that means there are overlapping among problems. so to
// solve the bigger problem we need to solve the small problem.
// after this thinking, we find the solution of all capacity from 0 to n if there no item then we add one bar
// we find the best solution for every capacity from 1 to n may be adding the new bar make specific capacity solutions
// better before adding the new bar. and so on add bar by bar till you reach the best solution for all capacities
// from 1 to n with the given bars.
int optimal_weight(int , const vector<int>&);

/**Compute the Edit Distance Between Two Strings
The edit distance between two strings is the minimum number of insertions, deletions, and mismatches
to transform one string to another.
*/
// in this problem we need to solve smaller problems of the same problem to use those solutions in more
// complex problems of the same type. say we have ab and a and we ask ourselves what are the minimum no of
// operations to make them the same. when we compare last a in S1 and last b in S2 and we find they are
// different we have 3 options.
// 1- mismatch : editDistance('a', '') + 1 for mismatch
// 2- delete : editDistance('a', 'a') + 1 for deleting a
// 3- insert : editDistance('ab', '' ) + 1 for insertion
// as you can see all those options for solving edit distance of 'ab' 'a' depends on smaller overlapping
// problems like ('a', ''), ('a', 'a'), ('ab', '') so DP must be one of possible solutions.
// we can easily reconstruct the alignment matrix from the dynamic programming table
int editting_distance(string&, string&);


/** Placing parenthesis among operators and operands to get the maximum value
This problem after solving small version of it. I discover the solution of bigger problems
depends on solution of smaller one so we can solve the smaller ones first then use them in solving
the bigger ones next
*/
int expressionMaxValue(const string&);


/** Find the longest subsequence among 3 sequences*/
int lcs3(vector<int> &, vector<int> &, vector<int> &);

#endif // DYNAMIC_PROGRAMMING_H_INCLUDED
