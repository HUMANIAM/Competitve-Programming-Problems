#ifndef DYNAMIC_PROGRAMMING_H_INCLUDED
#define DYNAMIC_PROGRAMMING_H_INCLUDED
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


#endif // DYNAMIC_PROGRAMMING_H_INCLUDED
