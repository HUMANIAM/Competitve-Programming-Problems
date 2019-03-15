#ifndef POLY_MULTI_PROBLEM_H_INCLUDED
#define POLY_MULTI_PROBLEM_H_INCLUDED
#include <vector>
using namespace std;
/**
    Description: you are given two vectors A, B of coefficients and you need to find the result of multiply them
    ===========
    Polynomials multiplication problem is a major problem in digital signal processing and because it is a major
    problem we need to find an efficient algorithm to solve it and do less computation. computation are based on
    multiplication and addition
*/

/**
    naive solution: make all multiplication and addition operations to get the solution
    complexity : multiplication theta(n^2) and addition theta(n^2) so complexity is theta(n^2)
*/

vector<int> naive_poly_multiplication(const vector<int>&, const vector<int>&);

/**
Divide and Conquer : divide every vector into 2 sub vectors of size n/2
*****************
* using 4 multiplications
*----------------------
A(x) >> A0(x) + A1(x) * x^(floor(n/2))
B(x) >> B0(x) + B1(x) * x^(floor(n/2))
C(x) >> A0B0 + A0B1 * x^(floor(n/2)) + A1B0 * x^(floor(n/2)) + A1B1 * x^(2*floor(n/2))

complexity time : O(n^2) like the brute force approach
using master theorm T(n) = 4T(n/2) + cn and assume n = 2^h
*/
vector<int> recursive_poly_multiplication(const vector<int>&,int, int, const vector<int>&, int, int);
vector<int> polyn_mulitplication_DivideConquer_4Muli(const vector<int>&, const vector<int>&);


/**
Divide and conquer using 3 multiplications
*************************************
Y = (A0 + A1)(B0 + B1)
U = A0B0
Z = A1B1
A0B1 + A1B0 = Y - U - Z

complexity time : O(n^(lg3))
T(n) = 2T(n/2) + cn
*/
vector<int> polyn_mulitplication_DivideConquer_3Muli(const vector<int>&, const vector<int>&);

#endif // POLY_MULTI_PROBLEM_H_INCLUDED
