#include "dynamic_programming.h"
#include <iostream>
#include <cassert>
#include <algorithm>
#include <limits>

#define LLMAX numeric_limits<LL>::max()
#define LLMIN numeric_limits<LL>::min()

typedef long long LL;
typedef vector<vector<LL> > VECTOR2D_LL;

/// find the minimum number of coins to change a coin with denomination coins

// using dp
int minNumberOfCoins(vector<int>& dpT, const vector<int>& coins, int money){
    int minNumCoins = INT_MAX;
    for(size_t i = 0; i < coins.size(); i++){
        if(money >= coins[i]){
            int v = dpT[money - coins[i]];
            if(v != INT_MAX && (v + 1) < minNumCoins)
                minNumCoins = v + 1;
        }
    }
    return minNumCoins;
}


int dpCoinChange(int money, const vector<int>& coins){
    /** solve the problem for small money and save solutions then use the solutions
    to solve bigger and bigger problem till solve the main one.
    */
    vector<int> dpTable(money + 1, 0);
    for (int i=1; i <= money; i++){
        dpTable[i] = minNumberOfCoins(dpTable, coins, money);
    }

    return dpTable[money];
}


// using divide and conquer
int divideAndConquer_ChangeMoney(int money, const vector<int>& coins){
    // base case
    if (money == 0) return 0;

    int MinNumberOfCoins = INT_MAX;
    for(size_t i = 0; i < coins.size(); i++){
        if(money >= coins[i]){
            int numOfCoins = divideAndConquer_ChangeMoney(money - coins[i], coins) + 1;
            if(numOfCoins < MinNumberOfCoins)
                MinNumberOfCoins = numOfCoins;
        }
    }

    return MinNumberOfCoins;
}

// entry point function
int changeCoins(int money, const vector<int>& coins){
    int r = dpCoinChange(money, coins);
    return r == INT_MAX ? -1 : r;
}


/// find the minimum number of operations to go from 1 to target number n
vector<Operation> optimal_min_operatins(int n) {
  vector<Operation> sequence(n+1);
  //using the bottom up approach
  for(int i=2; i<=n; i++){
      // assume no of (operations of (i - 1)) + 1 is the min for i+1
      sequence[i].min_operations = sequence[i-1].min_operations + 1;
      sequence[i].last_operation = 1;

      int v;
      for(int j = 2; j < 4; j++){
        if(i%j == 0)
        if(sequence[i].min_operations > ( v = sequence[i/j].min_operations +1 )){
          sequence[i].min_operations = v;
          sequence[i].last_operation = j;
        }
      }
  }

  return sequence;
}


/**Take as Much Gold as Possible problem is the same as knapsack problem without repetitions
*/
// for all capacities we solve the problem with specific bar and without it and choose the solution
// gives the maximum value.
int optimal_capacity(int W, const vector<int> &w) {
  //write your code here
  vector< vector<int> > memotable( w.size()+1 , vector<int>(W+1) );

 // for capacity = 0 and whatever the number of bars the maximum value will be 0
 for(int i=0; i<memotable.size(); i++)
    memotable[i][0] = 0;

  // if there are no bars then whatever the capacity you want to get the max value of bars will be 0
  for(int i=0; i<memotable[0].size(); i++)
    memotable[0][i] = 0;

  for(int bar_index=1; bar_index<memotable.size(); bar_index++)
      for(int capacity=1; capacity<memotable[bar_index].size(); capacity++){
            // assume the best solution is not take the current bar
          memotable[bar_index][capacity] = memotable[bar_index-1][capacity];
          if(capacity >= w[bar_index-1]){
            // if we take current bar as part of the solution
            int b = ( memotable[bar_index-1][capacity-w[bar_index-1]] + w[bar_index-1]);
            memotable[bar_index][capacity] = max(memotable[bar_index][capacity], b );
          }
      }

 return memotable[w.size()][W];
}



/// Editting Distance problem
int editting_distance(string& str1, string& str2){
    /**finding the minimum number of insertions, deletions, mismatches to convert one string
    to another. e.g str1 = ab, str2 = a solution will be 1*/
    size_t n = str1.size();
    size_t m = str2.size();
    vector<vector<int> > dpTable(m+1, vector<int>(n+1, 0));

    // if one string is empty then the minimum score equals the length of the other string
    for(size_t i = 0; i<= m; i++)
        dpTable[i][0] = i;

    for(size_t i = 0; i <= n; i++)
        dpTable[0][i] = i;

    // complete the table with min operations among every 2 pair of substrings from Str1 and Str2
    for(int i=1; i <= m; i++)
        for(int j=1; j <= n; j++)
            if(str1[i-1] == str2[j - 1]) dpTable[i][j] = dpTable[i-1][j-1];
            else{
                int mismatchCost = dpTable[i-1][j-1] + 1;
                int deleteCost   = dpTable[i][j-1]   + 1;
                int insertCost   = dpTable[i-1][j]   + 1;
                dpTable[i][j] = min(mismatchCost, min(deleteCost, insertCost));
            }

    return dpTable[m][n];
}


/** placing parenthesis among expressions to get the maximum result*/
// for an operand like - it is better to get max of LHS and min of RHS
// for an operand like + and * it is better to get max from LHS and RHS

LL eval(LL a, LL b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}


// assign min and max for subExpression from i operand to j operand
void setMaxMin(VECTOR2D_LL& maxValues, VECTOR2D_LL& minValues, int i, int j,const string& symbols){
    for(int k = i; k < j; k++){
        char op = symbols[k];
        LL a = eval(maxValues[i][k], maxValues[k+1][j], op);
        LL b = eval(maxValues[i][k], minValues[k+1][j], op);
        LL c = eval(minValues[i][k], maxValues[k+1][j], op);
        LL d = eval(minValues[i][k], minValues[k+1][j], op);

        maxValues[i][j] = max(maxValues[i][j], max(max(a, b), max(c, d)));
        minValues[i][j] = min(minValues[i][j], min(min(a, b), min(c, d)));
    }
}


// get symbols in the expression
string getSymbols(const string& expr){
    string symbols = "";
    for(size_t i = 1; i < expr.size(); i += 2)
        symbols += expr[i];
    return symbols;
}


// get operators in the expression
string getDigits(const string& expr){
    string digits = "";
    for(int i=0; i < expr.size(); i += 2)
        digits += expr[i];
    return digits;
}


// find the max possible evaluation of the expression
int expressionMaxValue(const string& expr){
    // get symbols among operands
    string symbols = getSymbols(expr);

    // get digits among operators
    string digits = getDigits(expr);
    int n = digits.size();

    // initialize table for MINS of subExpressions and MAXs of subExpressions
    VECTOR2D_LL maxValues(n, vector<LL>(n, LLMIN));
    VECTOR2D_LL minValues(n, vector<LL>(n, LLMAX));

    // initialize the diagonals of both tables
    for(int i=0; i < n; i++)
        maxValues[i][i] = minValues[i][i] = digits[i] - '0';

    // compute the subExpressions with length 3 then 5 then 7 and so on till expression length
    for(int s = 1; s < n; s++)
        for(int i = 0; i < n - s; i++){
            int j = i + s;
            setMaxMin(maxValues, minValues, i, j, symbols);
        }

    // return max value
    return maxValues[0][n-1];
}


/** Find the maximum subsequence among 3 different sequences*/
int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
    int n = a.size();
    int m = b.size();
    int k = c.size();
    int memotable[n+1][m+1][k+1];
 //   initialize_memotable
     for(int i=0; i<=m; i++)
       for(int j=0; j<=k; j++)
          memotable[0][i][j] = 0;

     for(int i=0; i<=n; i++)
       for(int j=0; j<=k; j++)
          memotable[i][0][j] = 0;

           for(int i=0; i<=n; i++)
       for(int j=0; j<=m; j++)
          memotable[i][j][0] = 0;

    //filling the memotable with results of subproblems
    for(int x=1; x<=n; x++)
       for(int y=1; y<=m; y++)
         for(int z=1; z<=k; z++)
            if( (a[x-1] == b[y-1]) && (a[x-1]== c[z-1]))
                memotable[x][y][z] = memotable[x-1][y-1][z-1] + 1;
            else
                memotable[x][y][z] = max( max(memotable[x-1][y][z], memotable[x][y-1][z]), memotable[x][y][z-1]);

    return memotable[n][m][k];
}

