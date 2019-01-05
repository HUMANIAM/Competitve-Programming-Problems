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

vector<int> naive_poly_multiplication(const vector<int>& A, const vector<int>& B);

#endif // POLY_MULTI_PROBLEM_H_INCLUDED
